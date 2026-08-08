use std::env;
use std::fs;
use std::path::{Path, PathBuf};

type Result<T> = std::result::Result<T, String>;

#[derive(Clone, Copy)]
enum Target { Gcc296, Gcc3, Gs2, Agbcc }

impl Target {
    fn parse(value: &str) -> Result<Self> {
        match value {
            "gcc296" | "gs1" => Ok(Self::Gcc296),
            "gcc3" => Ok(Self::Gcc3),
            "gs2" => Ok(Self::Gs2),
            "agbcc" => Ok(Self::Agbcc),
            _ => Err(format!("unknown compiler target: {value}")),
        }
    }
    fn name(self) -> &'static str {
        match self { Self::Gcc296 => "gcc296", Self::Gcc3 => "gcc3", Self::Gs2 => "gs2", Self::Agbcc => "agbcc" }
    }
}

struct Layout { root: PathBuf, dist: PathBuf }

impl Layout {
    fn discover() -> Result<Self> {
        let root = Path::new(env!("CARGO_MANIFEST_DIR")).to_path_buf();
        let dist = env::var_os("ALCHEMY_GCC_DIST_ROOT").map(PathBuf::from).unwrap_or_else(|| root.join("dist"));
        validate_dist(&dist)?;
        Ok(Self { root, dist })
    }
    fn build(&self, target: Target) -> PathBuf {
        let key = match target {
            Target::Gcc296 => "ALCHEMY_GCC_BUILD_296",
            Target::Gcc3 => "ALCHEMY_GCC_BUILD_GCC3",
            Target::Gs2 => "ALCHEMY_GCC_BUILD_GS2",
            Target::Agbcc => "ALCHEMY_GCC_BUILD_AGBCC",
        };
        env::var_os(key).map(PathBuf::from).unwrap_or_else(|| match target {
            Target::Gcc296 => self.root.join("build-296/gcc"),
            Target::Gcc3 => self.root.join("build/gcc"),
            Target::Gs2 => self.root.join("build-gs2/gcc"),
            Target::Agbcc => self.root.join("agbcc/gcc"),
        })
    }
    fn destination(&self, target: Target) -> PathBuf {
        match target {
            Target::Gcc296 => self.dist.clone(),
            Target::Gcc3 => self.dist.join("gcc3"),
            Target::Gs2 => self.dist.join("gs2"),
            Target::Agbcc => self.dist.join("agbcc"),
        }
    }
}

fn validate_dist(path: &Path) -> Result<()> {
    if path.as_os_str().is_empty() || path == Path::new("/") || path.file_name().and_then(|v| v.to_str()) != Some("dist") {
        return Err(format!("runtime stage root must be a directory named dist: {}", path.display()));
    }
    Ok(())
}

#[cfg(unix)]
fn executable(path: &Path) -> bool {
    use std::os::unix::fs::PermissionsExt;
    path.is_file() && fs::metadata(path).map(|m| m.permissions().mode() & 0o111 != 0).unwrap_or(false)
}
#[cfg(not(unix))]
fn executable(path: &Path) -> bool { path.is_file() }

fn artifacts(target: Target) -> &'static [(&'static str, &'static str)] {
    match target {
        Target::Gcc296 => &[("xgcc", "xgcc"), ("cc1", "cc1"), ("cpp", "cpp"), ("tradcpp", "tradcpp")],
        Target::Gcc3 => &[("cc1", "cc1")],
        Target::Gs2 => &[("xgcc", "xgcc"), ("cc1", "cc1"), ("cpp0", "cpp0"), ("tradcpp0", "tradcpp0")],
        Target::Agbcc => &[("old_agbcc", "old_agbcc")],
    }
}

fn install_artifacts(target: Target) -> &'static [&'static str] {
    match target {
        Target::Gcc296 => &["cc1", "xgcc", "cpp", "tradcpp"],
        Target::Gcc3 | Target::Gs2 => &["cc1", "xgcc", "cpp0", "tradcpp0"],
        Target::Agbcc => &["old_agbcc"],
    }
}

fn require(path: &Path) -> Result<()> {
    if executable(path) { Ok(()) } else { Err(format!("required executable is missing: {}", path.display())) }
}

fn set_executable(path: &Path) -> Result<()> {
    #[cfg(unix)] {
        use std::os::unix::fs::PermissionsExt;
        let mut permissions = fs::metadata(path).map_err(|e| format!("{}: {e}", path.display()))?.permissions();
        permissions.set_mode(0o755);
        fs::set_permissions(path, permissions).map_err(|e| format!("{}: {e}", path.display()))?;
    }
    Ok(())
}

fn copy_bundle(layout: &Layout, target: Target) -> Result<()> {
    let source = layout.build(target);
    let destination = layout.destination(target);
    for (from, _) in artifacts(target) { require(&source.join(from))?; }
    fs::create_dir_all(&layout.dist).map_err(|e| format!("{}: {e}", layout.dist.display()))?;

    if matches!(target, Target::Gcc296) {
        for (from, to) in artifacts(target) {
            let output = destination.join(to);
            fs::copy(source.join(from), &output).map_err(|e| format!("{}: {e}", output.display()))?;
            set_executable(&output)?;
        }
    } else {
        let temporary = layout.dist.join(format!(".{}-stage.{}", target.name(), std::process::id()));
        if temporary.exists() { fs::remove_dir_all(&temporary).map_err(|e| e.to_string())?; }
        fs::create_dir(&temporary).map_err(|e| format!("{}: {e}", temporary.display()))?;
        for (from, to) in artifacts(target) {
            let output = temporary.join(to);
            fs::copy(source.join(from), &output).map_err(|e| format!("{}: {e}", output.display()))?;
            set_executable(&output)?;
        }
        if destination.exists() { fs::remove_dir_all(&destination).map_err(|e| format!("{}: {e}", destination.display()))?; }
        fs::rename(&temporary, &destination).map_err(|e| format!("{}: {e}", destination.display()))?;
    }
    println!("staged {} runtime in {}", target.name(), destination.display());
    Ok(())
}

fn check_bundle(layout: &Layout, target: Target) -> Result<()> {
    let source = layout.build(target);
    let destination = layout.destination(target);
    for (from, to) in artifacts(target) {
        let from = source.join(from);
        let to = destination.join(to);
        require(&from)?; require(&to)?;
        if fs::read(&from).map_err(|e| e.to_string())? != fs::read(&to).map_err(|e| e.to_string())? {
            return Err(format!("staged executable differs from local build: {}", to.display()));
        }
    }
    if !matches!(target, Target::Gcc296) {
        let count = fs::read_dir(&destination).map_err(|e| format!("{}: {e}", destination.display()))?.count();
        if count != artifacts(target).len() {
            return Err(format!("{} runtime stage must contain exactly {} executables", target.name(), artifacts(target).len()));
        }
    }
    println!("{} runtime stage is current: {}", target.name(), destination.display());
    Ok(())
}

fn stage(args: &[String]) -> Result<()> {
    let (check, token) = match args {
        [one] => (false, one.as_str()),
        [flag, one] if flag == "--check" => (true, one.as_str()),
        _ => return Err("usage: alchemy-gcc stage [--check] <gcc296|gcc3|gs2|agbcc|all>".into()),
    };
    let layout = Layout::discover()?;
    let targets: Vec<Target> = if token == "all" {
        vec![Target::Gcc296, Target::Gcc3, Target::Gs2, Target::Agbcc]
    } else { vec![Target::parse(token)?] };
    for target in targets {
        if check { check_bundle(&layout, target)?; } else { copy_bundle(&layout, target)?; }
    }
    Ok(())
}

fn copy_tree(source: &Path, destination: &Path) -> Result<()> {
    fs::create_dir_all(destination).map_err(|e| format!("{}: {e}", destination.display()))?;
    for entry in fs::read_dir(source).map_err(|e| format!("{}: {e}", source.display()))? {
        let entry = entry.map_err(|e| format!("{}: {e}", source.display()))?;
        let output = destination.join(entry.file_name());
        if entry.file_type().map_err(|e| e.to_string())?.is_dir() {
            copy_tree(&entry.path(), &output)?;
        } else {
            fs::copy(entry.path(), &output).map_err(|e| format!("{}: {e}", output.display()))?;
        }
    }
    Ok(())
}

fn install_one(layout: &Layout, checkout: &Path, target: Target) -> Result<()> {
    let destination = checkout.join("tools").join(target.name());
    if matches!(target, Target::Agbcc) {
        let compiler = layout.build(target).join("old_agbcc");
        require(&compiler)?;
        let binary = destination.join("bin/old_agbcc");
        fs::create_dir_all(binary.parent().expect("binary has parent")).map_err(|e| e.to_string())?;
        fs::copy(&compiler, &binary).map_err(|e| format!("{}: {e}", binary.display()))?;
        set_executable(&binary)?;
        let include = destination.join("include");
        copy_tree(&layout.root.join("agbcc/libc/include"), &include)?;
        copy_tree(&layout.root.join("agbcc/ginclude"), &include)?;
    } else {
        let source = layout.build(target);
        for artifact in install_artifacts(target) { require(&source.join(artifact))?; }
        fs::create_dir_all(&destination).map_err(|e| format!("{}: {e}", destination.display()))?;
        for artifact in install_artifacts(target) {
            let output = destination.join(artifact);
            fs::copy(source.join(artifact), &output).map_err(|e| format!("{}: {e}", output.display()))?;
            set_executable(&output)?;
        }
    }
    println!("installed {} into {}", target.name(), destination.display());
    Ok(())
}

fn install(args: &[String]) -> Result<()> {
    let [checkout, token] = args else {
        return Err("usage: alchemy-gcc install DECOMP <gcc296|gcc3|gs2|agbcc|all>".into());
    };
    let checkout = Path::new(checkout);
    if !checkout.is_dir() { return Err(format!("target directory does not exist: {}", checkout.display())); }
    let layout = Layout::discover()?;
    let targets: Vec<Target> = if token == "all" {
        vec![Target::Gcc296, Target::Gcc3, Target::Gs2, Target::Agbcc]
    } else { vec![Target::parse(token)?] };
    for target in targets { install_one(&layout, checkout, target)?; }
    Ok(())
}

fn main() {
    let args: Vec<String> = env::args().skip(1).collect();
    let result = match args.split_first() {
        Some((command, rest)) if command == "stage" => stage(rest),
        Some((command, rest)) if command == "install" => install(rest),
        _ => Err("usage: alchemy-gcc <stage|install> ...".into()),
    };
    if let Err(error) = result { eprintln!("error: {error}"); std::process::exit(1); }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn rejects_broad_or_misnamed_stage_roots() {
        assert!(validate_dist(Path::new("/")).is_err());
        assert!(validate_dist(Path::new("/tmp/runtime")).is_err());
        assert!(validate_dist(Path::new("/tmp/dist")).is_ok());
    }
    #[test]
    fn supported_targets_have_exact_runtime_shapes() {
        assert_eq!(artifacts(Target::Gcc296).len(), 4);
        assert_eq!(artifacts(Target::Gs2).len(), 4);
        assert_eq!(artifacts(Target::Agbcc), &[("old_agbcc", "old_agbcc")]);
        assert_eq!(artifacts(Target::Gcc3), &[("cc1", "cc1")]);
        assert!(Target::parse("gcc2951").is_err());
        assert!(Target::parse("pretearlythumb").is_err());
    }

    #[test]
    fn install_shapes_keep_full_gcc_tools_and_nested_agbcc_binary() {
        assert_eq!(install_artifacts(Target::Gcc296), &["cc1", "xgcc", "cpp", "tradcpp"]);
        assert_eq!(install_artifacts(Target::Gcc3), &["cc1", "xgcc", "cpp0", "tradcpp0"]);
        assert_eq!(install_artifacts(Target::Agbcc), &["old_agbcc"]);
    }
}
