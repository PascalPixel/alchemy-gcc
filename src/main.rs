use std::env;
use std::fs;
use std::path::{Path, PathBuf};
use std::process::Command;

const BUNDLE_LOCK_FILE_NAME: &str = ".alchemy-gcc.lock";

#[cfg(unix)]
const LOCK_SH: i32 = 1;
#[cfg(unix)]
const LOCK_EX: i32 = 2;

#[cfg(unix)]
unsafe extern "C" {
    fn flock(file_descriptor: i32, operation: i32) -> i32;
}

type Result<T> = std::result::Result<T, String>;

#[derive(Clone, Copy)]
enum Target {
    Gs1cc,
    Gs2cc,
    Agbcc,
}

impl Target {
    fn parse(value: &str) -> Result<Self> {
        match value {
            "gs1cc" | "gs1" => Ok(Self::Gs1cc),
            "gs2cc" | "gs2" => Ok(Self::Gs2cc),
            "agbcc" => Ok(Self::Agbcc),
            _ => Err(format!("unknown compiler target: {value}")),
        }
    }
    fn name(self) -> &'static str {
        match self {
            Self::Gs1cc => "gs1cc",
            Self::Gs2cc => "gs2cc",
            Self::Agbcc => "agbcc",
        }
    }
}

struct Layout {
    root: PathBuf,
    dist: PathBuf,
}

struct BundleLock {
    #[cfg(unix)]
    _file: fs::File,
}

fn lock_bundle(dist: &Path, exclusive: bool) -> Result<BundleLock> {
    fs::create_dir_all(dist).map_err(|error| format!("{}: {error}", dist.display()))?;
    #[cfg(unix)]
    {
        use std::os::unix::io::AsRawFd;

        let path = dist.join(BUNDLE_LOCK_FILE_NAME);
        let file = fs::OpenOptions::new()
            .create(true)
            .read(true)
            .write(true)
            .truncate(false)
            .open(&path)
            .map_err(|error| {
                format!(
                    "cannot open compiler bundle lock {}: {error}",
                    path.display()
                )
            })?;
        let operation = if exclusive { LOCK_EX } else { LOCK_SH };
        // SAFETY: `file` owns a valid descriptor for this call and remains in
        // the returned guard for the complete lock lifetime.
        if unsafe { flock(file.as_raw_fd(), operation) } != 0 {
            return Err(format!(
                "cannot acquire compiler bundle lock {}: {}",
                path.display(),
                std::io::Error::last_os_error()
            ));
        }
        Ok(BundleLock { _file: file })
    }
    #[cfg(not(unix))]
    {
        let _ = exclusive;
        Ok(BundleLock {})
    }
}

impl Layout {
    fn discover() -> Result<Self> {
        let root = Path::new(env!("CARGO_MANIFEST_DIR")).to_path_buf();
        // Alchemy validates and executes this one canonical stage. Allowing
        // the staging driver to point elsewhere can make `stage --check`
        // approve bytes that the consuming repository never reads.
        let dist = root.join("dist");
        validate_dist(&dist)?;
        Ok(Self { root, dist })
    }
    fn build(&self, target: Target) -> PathBuf {
        let key = match target {
            Target::Gs1cc => "ALCHEMY_GCC_BUILD_GS1CC",
            Target::Gs2cc => "ALCHEMY_GCC_BUILD_GS2CC",
            Target::Agbcc => "ALCHEMY_GCC_BUILD_AGBCC",
        };
        env::var_os(key)
            .map(PathBuf::from)
            .unwrap_or_else(|| match target {
                Target::Gs1cc => self.root.join("build-gs1cc/gcc"),
                Target::Gs2cc => self.root.join("build-gs2cc/gcc"),
                Target::Agbcc => self.root.join("agbcc/gcc"),
            })
    }
    fn destination(&self, target: Target) -> PathBuf {
        match target {
            Target::Gs1cc => self.dist.clone(),
            Target::Gs2cc => self.dist.join("gs2"),
            Target::Agbcc => self.dist.join("agbcc"),
        }
    }
}

fn validate_dist(path: &Path) -> Result<()> {
    if path.as_os_str().is_empty()
        || path == Path::new("/")
        || path.file_name().and_then(|v| v.to_str()) != Some("dist")
    {
        return Err(format!(
            "runtime stage root must be a directory named dist: {}",
            path.display()
        ));
    }
    Ok(())
}

#[cfg(unix)]
fn executable(path: &Path) -> bool {
    use std::os::unix::fs::PermissionsExt;
    path.is_file()
        && fs::metadata(path)
            .map(|m| m.permissions().mode() & 0o111 != 0)
            .unwrap_or(false)
}

fn command_on_path(name: &str) -> bool {
    let Some(path) = env::var_os("PATH") else {
        return false;
    };
    env::split_paths(&path).any(|directory| executable(&directory.join(name)))
}

fn binutils_available() -> bool {
    env::var_os("DEVKITARM")
        .map(PathBuf::from)
        .map(|root| root.join("bin").is_dir())
        .unwrap_or(false)
        || (command_on_path("arm-none-eabi-as") && command_on_path("arm-none-eabi-ar"))
}

fn require_binutils() -> Result<()> {
    if binutils_available() {
        Ok(())
    } else {
        Err("required ARM binutils not found: install devkitARM or arm-none-eabi-as and arm-none-eabi-ar".into())
    }
}
#[cfg(not(unix))]
fn executable(path: &Path) -> bool {
    path.is_file()
}

fn artifacts(target: Target) -> &'static [(&'static str, &'static str)] {
    match target {
        Target::Gs1cc => &[
            ("xgcc", "xgcc"),
            ("cc1", "cc1"),
            ("cpp", "cpp"),
            ("tradcpp", "tradcpp"),
        ],
        Target::Gs2cc => &[
            ("xgcc", "xgcc"),
            ("cc1", "cc1"),
            ("cpp0", "cpp0"),
            ("tradcpp0", "tradcpp0"),
        ],
        Target::Agbcc => &[("old_agbcc", "old_agbcc")],
    }
}

fn install_artifacts(target: Target) -> &'static [&'static str] {
    match target {
        Target::Gs1cc => &["cc1", "xgcc", "cpp", "tradcpp"],
        Target::Gs2cc => &["cc1", "xgcc", "cpp0", "tradcpp0"],
        Target::Agbcc => &["old_agbcc"],
    }
}

fn require(path: &Path) -> Result<()> {
    if executable(path) {
        Ok(())
    } else {
        Err(format!(
            "required executable is missing: {}",
            path.display()
        ))
    }
}

fn set_executable(path: &Path) -> Result<()> {
    #[cfg(unix)]
    {
        use std::os::unix::fs::PermissionsExt;
        let mut permissions = fs::metadata(path)
            .map_err(|e| format!("{}: {e}", path.display()))?
            .permissions();
        permissions.set_mode(0o755);
        fs::set_permissions(path, permissions).map_err(|e| format!("{}: {e}", path.display()))?;
    }
    Ok(())
}

fn copy_bundle(layout: &Layout, target: Target) -> Result<()> {
    let source = layout.build(target);
    let destination = layout.destination(target);
    for (from, _) in artifacts(target) {
        require(&source.join(from))?;
    }
    fs::create_dir_all(&layout.dist).map_err(|e| format!("{}: {e}", layout.dist.display()))?;

    if matches!(target, Target::Gs1cc) {
        for (from, to) in artifacts(target) {
            let output = destination.join(to);
            fs::copy(source.join(from), &output)
                .map_err(|e| format!("{}: {e}", output.display()))?;
            set_executable(&output)?;
        }
    } else {
        let temporary =
            layout
                .dist
                .join(format!(".{}-stage.{}", target.name(), std::process::id()));
        if temporary.exists() {
            fs::remove_dir_all(&temporary).map_err(|e| e.to_string())?;
        }
        fs::create_dir(&temporary).map_err(|e| format!("{}: {e}", temporary.display()))?;
        for (from, to) in artifacts(target) {
            let output = temporary.join(to);
            fs::copy(source.join(from), &output)
                .map_err(|e| format!("{}: {e}", output.display()))?;
            set_executable(&output)?;
        }
        if destination.exists() {
            fs::remove_dir_all(&destination)
                .map_err(|e| format!("{}: {e}", destination.display()))?;
        }
        fs::rename(&temporary, &destination)
            .map_err(|e| format!("{}: {e}", destination.display()))?;
    }
    println!(
        "staged {} runtime in {}",
        target.name(),
        destination.display()
    );
    Ok(())
}

fn check_bundle(layout: &Layout, target: Target) -> Result<()> {
    let source = layout.build(target);
    let destination = layout.destination(target);
    for (from, to) in artifacts(target) {
        let from = source.join(from);
        let to = destination.join(to);
        require(&from)?;
        require(&to)?;
        if fs::read(&from).map_err(|e| e.to_string())?
            != fs::read(&to).map_err(|e| e.to_string())?
        {
            return Err(format!(
                "staged executable differs from local build: {}",
                to.display()
            ));
        }
    }
    if !matches!(target, Target::Gs1cc) {
        let count = fs::read_dir(&destination)
            .map_err(|e| format!("{}: {e}", destination.display()))?
            .count();
        if count != artifacts(target).len() {
            return Err(format!(
                "{} runtime stage must contain exactly {} executables",
                target.name(),
                artifacts(target).len()
            ));
        }
    }
    println!(
        "{} runtime stage is current: {}",
        target.name(),
        destination.display()
    );
    Ok(())
}

fn stage(args: &[String]) -> Result<()> {
    let (check, token) = match args {
        [one] => (false, one.as_str()),
        [flag, one] if flag == "--check" => (true, one.as_str()),
        _ => return Err("usage: alchemy-gcc stage [--check] <gs1cc|gs2cc|agbcc|all>".into()),
    };
    let layout = Layout::discover()?;
    // Consumers hold the matching shared lock for their process lifetime.
    // Taking the exclusive side before touching `dist` prevents a validator,
    // signature, or compiler invocation from observing a mixed generation.
    let _bundle_lock = lock_bundle(&layout.dist, true)?;
    let targets: Vec<Target> = if token == "all" {
        vec![Target::Gs1cc, Target::Gs2cc, Target::Agbcc]
    } else {
        vec![Target::parse(token)?]
    };
    for target in targets {
        if check {
            check_bundle(&layout, target)?;
        } else {
            copy_bundle(&layout, target)?;
        }
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

fn copy_license(layout: &Layout, checkout: &Path, name: &str) -> Result<()> {
    let source = layout.root.join(name);
    let filename = Path::new(name)
        .file_name()
        .ok_or_else(|| format!("license path has no file name: {name}"))?;
    let destination = checkout.join("tools").join("agbcc").join(filename);
    fs::copy(&source, &destination)
        .map_err(|e| format!("{} -> {}: {e}", source.display(), destination.display()))?;
    Ok(())
}

fn install_one(layout: &Layout, checkout: &Path, target: Target) -> Result<()> {
    let destination = checkout.join("tools").join(target.name());
    if matches!(target, Target::Agbcc) {
        let compiler = layout.build(target).join("old_agbcc");
        require(&compiler)?;
        let binary = destination.join("bin/old_agbcc");
        fs::create_dir_all(binary.parent().expect("binary has parent"))
            .map_err(|e| e.to_string())?;
        fs::copy(&compiler, &binary).map_err(|e| format!("{}: {e}", binary.display()))?;
        set_executable(&binary)?;
        let include = destination.join("include");
        copy_tree(&layout.root.join("agbcc/libc/include"), &include)?;
        copy_tree(&layout.root.join("agbcc/ginclude"), &include)?;
        copy_license(layout, checkout, "agbcc/gcc/COPYING")?;
        copy_license(layout, checkout, "agbcc/gcc/COPYING.LIB")?;
        copy_license(layout, checkout, "agbcc/libc/COPYING.NEWLIB")?;
    } else {
        let source = layout.build(target);
        for artifact in install_artifacts(target) {
            require(&source.join(artifact))?;
        }
        fs::create_dir_all(&destination).map_err(|e| format!("{}: {e}", destination.display()))?;
        for artifact in install_artifacts(target) {
            let output = destination.join(artifact);
            fs::copy(source.join(artifact), &output)
                .map_err(|e| format!("{}: {e}", output.display()))?;
            set_executable(&output)?;
        }
    }
    println!("installed {} into {}", target.name(), destination.display());
    Ok(())
}

fn install(args: &[String]) -> Result<()> {
    let [checkout, token] = args else {
        return Err("usage: alchemy-gcc install DECOMP <gs1cc|gs2cc|agbcc|all>".into());
    };
    let checkout = Path::new(checkout);
    if !checkout.is_dir() {
        return Err(format!(
            "target directory does not exist: {}",
            checkout.display()
        ));
    }
    let layout = Layout::discover()?;
    let targets: Vec<Target> = if token == "all" {
        vec![Target::Gs1cc, Target::Gs2cc, Target::Agbcc]
    } else {
        vec![Target::parse(token)?]
    };
    for target in targets {
        install_one(&layout, checkout, target)?;
    }
    Ok(())
}

const HOST_CFLAGS: &str = "-O2 -fno-pie -no-pie -Wno-narrowing -Wno-implicit-int -Wno-implicit-function-declaration -Wno-pointer-arith -Wno-int-conversion -Wno-format -Wno-error -std=gnu17 -Wno-incompatible-pointer-types";
const HOST_CXXFLAGS: &str = "-O2 -fno-pie -no-pie -Wno-narrowing -Wno-error -std=gnu++17";
const HOST_LDFLAGS: &str = "-no-pie";

fn run(command: &mut Command) -> Result<()> {
    let display = format!("{command:?}");
    let status = command
        .status()
        .map_err(|e| format!("could not start {display}: {e}"))?;
    if status.success() {
        Ok(())
    } else {
        Err(format!("command failed ({status}): {display}"))
    }
}

fn make_executable_tree(root: &Path) -> Result<()> {
    const HELPERS: &[&str] = &[
        "configure",
        "config.sub",
        "config.guess",
        "install-sh",
        "mkinstalldirs",
        "move-if-change",
        "missing",
        "ltconfig",
        "ltmain.sh",
        "mkdep",
    ];
    fn walk(path: &Path) -> Result<()> {
        for entry in fs::read_dir(path).map_err(|e| format!("{}: {e}", path.display()))? {
            let entry = entry.map_err(|e| e.to_string())?;
            if entry.file_type().map_err(|e| e.to_string())?.is_dir() {
                walk(&entry.path())?;
            } else if HELPERS.contains(&entry.file_name().to_string_lossy().as_ref()) {
                set_executable(&entry.path())?;
            }
        }
        Ok(())
    }
    walk(root)
}

fn files_named(root: &Path, names: &[&str], out: &mut Vec<PathBuf>) -> Result<()> {
    for entry in fs::read_dir(root).map_err(|e| format!("{}: {e}", root.display()))? {
        let entry = entry.map_err(|e| e.to_string())?;
        if entry.file_type().map_err(|e| e.to_string())?.is_dir() {
            files_named(&entry.path(), names, out)?;
        } else if names.contains(&entry.file_name().to_string_lossy().as_ref()) {
            out.push(entry.path());
        }
    }
    Ok(())
}

fn restamp_generated(source: &Path, marker: &Path) -> Result<()> {
    if marker.is_file() {
        return Ok(());
    }
    let mut inputs = Vec::new();
    files_named(
        source,
        &["configure.in", "c-parse.y", "c-gperf.gperf", "acconfig.h"],
        &mut inputs,
    )?;
    for path in inputs {
        run(Command::new("touch").args(["-t", "200001010000"]).arg(path))?;
    }
    let mut outputs = Vec::new();
    files_named(
        source,
        &[
            "configure",
            "c-parse.c",
            "c-parse.h",
            "c-gperf.h",
            "cstamp-h.in",
            "config.in",
            "cexp.c",
            "tradcif.c",
        ],
        &mut outputs,
    )?;
    for path in outputs {
        run(Command::new("touch").arg(path))?;
    }
    Ok(())
}

fn configure<'a>(command: &'a mut Command, cflags: &str) -> &'a mut Command {
    command
        .env("CFLAGS", cflags)
        .env("CXXFLAGS", HOST_CXXFLAGS)
        .env("LDFLAGS", HOST_LDFLAGS)
}

fn build_gcc_tree(layout: &Layout, target: Target) -> Result<()> {
    let (source, build, triple, extra, cpp, tradcpp) = match target {
        Target::Gs1cc => (
            layout.root.join("gs1cc"),
            layout.root.join("build-gs1cc"),
            "arm-elf",
            " -fcommon",
            "cpp",
            "tradcpp",
        ),
        Target::Gs2cc => (
            layout.root.join("gs2cc"),
            layout.root.join("build-gs2cc"),
            "arm-agb-elf",
            "",
            "cpp0",
            "tradcpp0",
        ),
        Target::Agbcc => return Err("internal target mismatch".into()),
    };
    if !source.is_dir() {
        return Err(format!("{} not found", source.display()));
    }
    make_executable_tree(&source)?;
    restamp_generated(&source, &build.join("gcc/Makefile"))?;
    fs::create_dir_all(&build).map_err(|e| e.to_string())?;
    let cflags = format!("{HOST_CFLAGS}{extra}");
    if !build.join("Makefile").is_file() {
        let mut top = Command::new(source.join("configure"));
        configure(&mut top, &cflags)
            .current_dir(&build)
            .arg(format!("--prefix={}", build.join("install").display()))
            .args([
                format!("--target={triple}"),
                "--with-cpu=arm7tdmi".into(),
                "--enable-multilib".into(),
                "--enable-interwork".into(),
                "--enable-languages=c".into(),
                "--without-headers".into(),
                "--disable-shared".into(),
                "--disable-threads".into(),
                "--disable-libstdc++-v3".into(),
                "--disable-nls".into(),
                "--disable-win32-registry".into(),
            ]);
        let _ = top.status();
    }
    let lib = build.join("libiberty");
    if !lib.join("libiberty.a").is_file() {
        if lib.exists() {
            fs::remove_dir_all(&lib).map_err(|e| e.to_string())?;
        }
        fs::create_dir(&lib).map_err(|e| e.to_string())?;
        let mut config = Command::new(source.join("libiberty/configure"));
        configure(&mut config, &cflags).current_dir(&lib).args([
            format!("--srcdir={}", source.join("libiberty").display()),
            format!("--prefix={}", build.join("install").display()),
            "--build=x86_64-unknown-linux-gnu".into(),
            "--host=x86_64-unknown-linux-gnu".into(),
            format!("--target={triple}"),
            "--disable-shared".into(),
            "--disable-nls".into(),
        ]);
        run(&mut config)?;
        run(Command::new("make").current_dir(&lib).arg(format!(
            "-j{}",
            std::thread::available_parallelism()
                .map(|v| v.get())
                .unwrap_or(4)
        )))?;
    }
    let gcc = build.join("gcc");
    if !gcc.join("Makefile").is_file() {
        fs::create_dir_all(&gcc).map_err(|e| e.to_string())?;
        let mut config = Command::new(source.join("gcc/configure"));
        configure(&mut config, &cflags).current_dir(&gcc).args([
            format!("--srcdir={}", source.join("gcc").display()),
            format!("--prefix={}", build.join("install").display()),
            "--build=x86_64-unknown-linux-gnu".into(),
            "--host=x86_64-unknown-linux-gnu".into(),
            format!("--target={triple}"),
            "--with-cpu=arm7tdmi".into(),
            "--enable-multilib".into(),
            "--enable-interwork".into(),
            "--enable-languages=c".into(),
            "--without-headers".into(),
            "--disable-shared".into(),
            "--disable-threads".into(),
            "--disable-nls".into(),
            "--with-gnu-as".into(),
            "--with-gnu-ld".into(),
            "--disable-checking".into(),
        ]);
        run(&mut config)?;
    }
    run(Command::new("make")
        .current_dir(&gcc)
        .arg(format!(
            "-j{}",
            std::thread::available_parallelism()
                .map(|v| v.get())
                .unwrap_or(4)
        ))
        .arg(format!("CFLAGS={cflags}"))
        .arg(format!("CXXFLAGS={HOST_CXXFLAGS}"))
        .arg(format!("LDFLAGS={HOST_LDFLAGS}"))
        .args(["cc1", "xgcc", cpp, tradcpp]))?;
    for artifact in ["cc1", "xgcc", cpp, tradcpp] {
        require(&gcc.join(artifact))?;
    }
    println!("BUILD OK ({})", target.name());
    Ok(())
}

fn build_agbcc(layout: &Layout) -> Result<()> {
    let gcc = layout.root.join("agbcc/gcc");
    if !gcc.is_dir() {
        return Err(format!("{} not found", gcc.display()));
    }
    make_executable_tree(&layout.root.join("agbcc"))?;
    run(Command::new("make").current_dir(&gcc).arg("clean"))?;
    run(Command::new("make").current_dir(&gcc).args(["old", "-j1"]))?;
    require(&gcc.join("old_agbcc"))?;
    println!("BUILD OK (agbcc)");
    Ok(())
}

fn build(args: &[String]) -> Result<()> {
    let [token] = args else {
        return Err("usage: alchemy-gcc build <gs1cc|gs2cc|agbcc|all>".into());
    };
    require_binutils()?;
    let layout = Layout::discover()?;
    let targets = if token == "all" {
        vec![Target::Gs1cc, Target::Gs2cc, Target::Agbcc]
    } else {
        vec![Target::parse(token)?]
    };
    for target in targets {
        if matches!(target, Target::Agbcc) {
            build_agbcc(&layout)?;
        } else {
            build_gcc_tree(&layout, target)?;
        }
    }
    Ok(())
}

struct Scratch(PathBuf);
impl Scratch {
    fn new() -> Result<Self> {
        let path = env::temp_dir().join(format!("alchemy-gcc-test-{}", std::process::id()));
        if path.exists() {
            fs::remove_dir_all(&path).map_err(|e| e.to_string())?;
        }
        fs::create_dir(&path).map_err(|e| e.to_string())?;
        Ok(Self(path))
    }
}
impl Drop for Scratch {
    fn drop(&mut self) {
        let _ = fs::remove_dir_all(&self.0);
    }
}

fn compile_xgcc(
    layout: &Layout,
    build: &Path,
    fixture: &str,
    output: &Path,
    flags: &[&str],
) -> Result<()> {
    let driver = build.join("xgcc");
    require(&driver)?;
    let mut command = Command::new(driver);
    command
        .arg(format!("-B{}/", build.display()))
        .args([
            "-O2",
            "-mthumb",
            "-mthumb-interwork",
            "-mcpu=arm7tdmi",
            "-fno-builtin",
            "-nostdinc",
            "-ffreestanding",
        ])
        .args(flags)
        .arg("-S")
        .arg(layout.root.join("tests/fixtures").join(fixture))
        .arg("-o")
        .arg(output);
    run(&mut command)
}

fn assert_same(left: &Path, right: &Path, context: &str) -> Result<()> {
    if fs::read(left).map_err(|e| e.to_string())? != fs::read(right).map_err(|e| e.to_string())? {
        Err(format!("{context}: expected identical assembly"))
    } else {
        Ok(())
    }
}
fn assert_different(left: &Path, right: &Path, context: &str) -> Result<()> {
    if fs::read(left).map_err(|e| e.to_string())? == fs::read(right).map_err(|e| e.to_string())? {
        Err(format!("{context}: opt-in did not change assembly"))
    } else {
        Ok(())
    }
}

fn assert_contains(path: &Path, needle: &str, context: &str) -> Result<()> {
    let text = fs::read_to_string(path).map_err(|e| e.to_string())?;
    if text.contains(needle) {
        Ok(())
    } else {
        Err(format!("{context}: assembly did not contain `{needle}`"))
    }
}

fn test_gs1cc(layout: &Layout, scratch: &Path) -> Result<()> {
    let build = layout.build(Target::Gs1cc);
    let cases: &[(&str, &[&str], &[&str])] = &[
        (
            "grouped_dma_store.c",
            &["-fcall-used-r4", "-mgrouped-dma-store"],
            &["-fcall-used-r4", "-mno-grouped-dma-store"],
        ),
        (
            "gcc296_thumb_minipool_tail_first.c",
            &["-fcall-used-r4", "-fthumb-minipool-tail-first"],
            &["-fcall-used-r4", "-fno-thumb-minipool-tail-first"],
        ),
        (
            "gcc296_grouped_dma_extended.c",
            &["-fcall-used-r4", "-mgrouped-dma-store"],
            &["-fcall-used-r4", "-mno-grouped-dma-store"],
        ),
        (
            "gcc296_thumb_3ce_value_entry_cluster.c",
            &[
                "-fcall-used-r4",
                "-mgrouped-dma-store",
                "-fno-flow2-cleanup-cfg",
                "-fno-cse-two-insn-immediate",
                "-fno-reload-cse-regs",
                "-fthumb-group-value1-before-base",
                "-fthumb-group-value1-in-place",
                "-fthumb-sink-group-pool-loads",
                "-fthumb-group-control-last",
                "-fthumb-hoist-add-immediate",
                "-fthumb-3ce-value-entry-cluster",
            ],
            &[
                "-fcall-used-r4",
                "-mgrouped-dma-store",
                "-fno-flow2-cleanup-cfg",
                "-fno-cse-two-insn-immediate",
                "-fno-reload-cse-regs",
                "-fthumb-group-value1-before-base",
                "-fthumb-group-value1-in-place",
                "-fthumb-sink-group-pool-loads",
                "-fthumb-group-control-last",
                "-fthumb-hoist-add-immediate",
                "-fno-thumb-3ce-value-entry-cluster",
            ],
        ),
        (
            "gcc296_thumb_38f_call_cluster.c",
            &["-fcall-used-r4", "-fsched-38f-call-cluster"],
            &["-fcall-used-r4", "-fno-sched-38f-call-cluster"],
        ),
        (
            "gcc296_thumb_bit_tests.c",
            &[
                "-mpreserve-single-bit-test",
                "-mentry-low-register-order",
                "-mthumb-and-sets-cc",
            ],
            &[
                "-mno-preserve-single-bit-test",
                "-mno-entry-low-register-order",
                "-mno-thumb-and-sets-cc",
            ],
        ),
        (
            "gcc296_early_frame_allocation.c",
            &["-fcall-used-r4", "-mearly-frame-allocation"],
            &["-fcall-used-r4", "-mno-early-frame-allocation"],
        ),
        (
            "gcc296_high_register_move_first.c",
            &["-fcall-used-r4", "-mhigh-register-move-first"],
            &["-fcall-used-r4", "-mno-high-register-move-first"],
        ),
        (
            "gcc296_high_move_before_stack_store.c",
            &[
                "-fcall-used-r4",
                "-mgrouped-dma-store",
                "-fthumb-high-move-before-stack-store",
            ],
            &[
                "-fcall-used-r4",
                "-mgrouped-dma-store",
                "-fno-thumb-high-move-before-stack-store",
            ],
        ),
        (
            "gcc296_low_constant_before_high_move.c",
            &[
                "-fcall-used-r4",
                "-fno-rerun-cse-after-loop",
                "-fno-regmove",
                "-fthumb-low-constant-before-high-move",
            ],
            &[
                "-fcall-used-r4",
                "-fno-rerun-cse-after-loop",
                "-fno-regmove",
                "-fno-thumb-low-constant-before-high-move",
            ],
        ),
        (
            "gcc296_thumb_callee_reg_order.c",
            &["-fcall-used-r4", "-mcallee-reg-order=0132"],
            &["-fcall-used-r4"],
        ),
        (
            "gcc296_thumb_high_reg_order.c",
            &["-fcall-used-r4", "-mhigh-reg-order=1203"],
            &["-fcall-used-r4"],
        ),
        (
            "gcc296_thumb_orr_dead_input_reuse.c",
            &["-fcall-used-r4", "-fthumb-orr-dead-input-reuse"],
            &["-fcall-used-r4", "-fno-thumb-orr-dead-input-reuse"],
        ),
        (
            "gcc296_thumb_rotate_orr_mask_load.c",
            &[
                "-fcall-used-r4",
                "-fsched-call-dest-descending",
                "-fthumb-rotate-orr-mask-load",
            ],
            &[
                "-fcall-used-r4",
                "-fsched-call-dest-descending",
                "-fno-thumb-rotate-orr-mask-load",
            ],
        ),
        (
            "gcc296_thumb_entry_frame_cluster.c",
            &["-fcall-used-r4", "-fthumb-entry-frame-cluster"],
            &["-fcall-used-r4", "-fno-thumb-entry-frame-cluster"],
        ),
        (
            "gcc296_thumb_literal_before_index_shift.c",
            &[
                "-fcall-used-r4",
                "-fno-schedule-insns2",
                "-fthumb-literal-before-index-shift",
            ],
            &[
                "-fcall-used-r4",
                "-fno-schedule-insns2",
                "-fno-thumb-literal-before-index-shift",
            ],
        ),
        (
            "gcc296_thumb_call_target_before_final_shift.c",
            &["-fcall-used-r4", "-fthumb-call-target-before-final-shift"],
            &["-fcall-used-r4"],
        ),
        (
            "gcc296_call_arg0_move_first.c",
            &["-fcall-used-r4", "-mcall-arg0-move-first"],
            &["-fcall-used-r4", "-mno-call-arg0-move-first"],
        ),
        (
            "gcc296_thumb_pool_long_call_arg0.c",
            &["-fcall-used-r4", "-fthumb-pool-long-call-arg0"],
            &["-fcall-used-r4"],
        ),
        (
            "gcc296_thumb_pool_long_call_arg0_interleaved.c",
            &[
                "-fcall-used-r4",
                "-fthumb-no-constant-reuse",
                "-fsched-low-dest-first",
                "-fthumb-pool-long-call-arg0",
            ],
            &[
                "-fcall-used-r4",
                "-fthumb-no-constant-reuse",
                "-fsched-low-dest-first",
            ],
        ),
        (
            "gcc296_thumb_zero_arg1_before_nonzero_arg0.c",
            &[
                "-fcall-used-r4",
                "-fthumb-no-constant-reuse",
                "-fsched-low-dest-first",
                "-fthumb-order-zero-arg1-before-nonzero-arg0",
            ],
            &[
                "-fcall-used-r4",
                "-fthumb-no-constant-reuse",
                "-fsched-low-dest-first",
            ],
        ),
        (
            "gcc296_thumb_order_8_0_20_args.c",
            &["-fcall-used-r4", "-fthumb-order-8-0-20-args"],
            &["-fcall-used-r4"],
        ),
        (
            "gcc296_thumb_shift_before_store_in_split_volatile.c",
            &[
                "-fcall-used-r4",
                "-fsched-low-dest-first",
                "-fthumb-shift-before-store-in-split",
            ],
            &["-fcall-used-r4", "-fsched-low-dest-first"],
        ),
        (
            "gcc296_thumb_zero_r1_before_r0_load_after_8_2.c",
            &["-fcall-used-r4", "-fthumb-zero-r1-before-r0-load-after-8-2"],
            &["-fcall-used-r4"],
        ),
        (
            "gcc296_thumb_call_arg12_before_arg0.c",
            &["-fcall-used-r4", "-fthumb-call-arg12-before-arg0"],
            &["-fcall-used-r4"],
        ),
        (
            "gcc296_thumb_stack_slot_before_table.c",
            &["-fcall-used-r4", "-fthumb-stack-slot-before-table"],
            &["-fcall-used-r4"],
        ),
        (
            "gcc296_thumb_store_before_pool_load.c",
            &[
                "-fcall-used-r4",
                "-fno-gcse",
                "-fno-cse-two-insn-immediate",
                "-fno-cse-pool-immediate",
                "-fsched-low-dest-first",
                "-fthumb-store-before-pool-load",
            ],
            &[
                "-fcall-used-r4",
                "-fno-gcse",
                "-fno-cse-two-insn-immediate",
                "-fno-cse-pool-immediate",
                "-fsched-low-dest-first",
            ],
        ),
        (
            "gcc296_thumb_entry_literal_first.c",
            &[
                "-fcall-used-r4",
                "-fno-schedule-insns2",
                "-mthumb-entry-literal-first",
            ],
            &[
                "-fcall-used-r4",
                "-fno-schedule-insns2",
                "-mno-thumb-entry-literal-first",
            ],
        ),
        (
            "gcc296_thumb_literal_arg1_before_zero_pair.c",
            &[
                "-fcall-used-r4",
                "-fthumb-literal-arg1-first-before-zero-pair",
            ],
            &["-fcall-used-r4"],
        ),
        (
            "gcc296_thumb_sink_constant_past_call_args.c",
            &["-fcall-used-r4", "-fthumb-sink-constant-past-call-args"],
            &["-fcall-used-r4"],
        ),
        (
            "gcc296_thumb_scene_call_sheets.c",
            &[
                "-fcall-used-r4",
                "-fno-gcse",
                "-fno-cse-two-insn-immediate",
                "-fno-cse-pool-immediate",
                "-fsched-low-dest-first",
                "-fthumb-scene-call-sheets",
            ],
            &[
                "-fcall-used-r4",
                "-fno-gcse",
                "-fno-cse-two-insn-immediate",
                "-fno-cse-pool-immediate",
                "-fsched-low-dest-first",
            ],
        ),
        (
            "gcc296_thumb_scene_call_sheets_resource_391.c",
            &[
                "-fcall-used-r4",
                "-fno-gcse",
                "-fno-cse-two-insn-immediate",
                "-fno-cse-pool-immediate",
                "-fsched-low-dest-first",
                "-fthumb-scene-call-sheets",
            ],
            &[
                "-fcall-used-r4",
                "-fno-gcse",
                "-fno-cse-two-insn-immediate",
                "-fno-cse-pool-immediate",
                "-fsched-low-dest-first",
            ],
        ),
        (
            "gcc296_thumb_boolean_r8_scratch_r2.c",
            &["-fcall-used-r4", "-fthumb-boolean-r8-scratch-r2"],
            &["-fcall-used-r4"],
        ),
        (
            "gcc296_thumb_single_arg_immediate_before_halfword_store.c",
            &[
                "-fcall-used-r4",
                "-fthumb-single-arg-immediate-before-halfword-store",
            ],
            &["-fcall-used-r4"],
        ),
        (
            "gcc296_thumb_pool_r1_lsl4.c",
            &[
                "-fcall-used-r4",
                "-fsched-low-dest-first",
                "-fthumb-pool-r1-lsl4",
            ],
            &["-fcall-used-r4", "-fsched-low-dest-first"],
        ),
        // The production route carries no scheduling flag, so the same sheet
        // arrives with the shift before the small r0 literal; the matcher
        // must accept both orders.
        (
            "gcc296_thumb_pool_r1_lsl4.c",
            &["-fcall-used-r4", "-fthumb-pool-r1-lsl4"],
            &["-fcall-used-r4"],
        ),
        (
            "gcc296_thumb_strict_addsi_imm.c",
            &["-fcall-used-r4", "-fthumb-strict-addsi-imm"],
            &["-fcall-used-r4"],
        ),
        (
            "gcc296_sextqi_minuend_base_conflict.c",
            &["-fcall-used-r4", "-fsextqi-minuend-base-conflict"],
            &["-fcall-used-r4"],
        ),
        (
            "gcc296_no_hoist_volatile_address.c",
            &["-fcall-used-r4", "-fno-hoist-volatile-address"],
            &["-fcall-used-r4", "-fhoist-volatile-address"],
        ),
    ];
    for (index, (fixture, enabled, disabled)) in cases.iter().enumerate() {
        let stock = scratch.join(format!("{index}-stock.s"));
        let opt_in = scratch.join(format!("{index}-in.s"));
        let opt_out = scratch.join(format!("{index}-out.s"));
        let common = enabled
            .iter()
            .zip(disabled.iter())
            .take_while(|(left, right)| left == right)
            .count();
        let baseline = &enabled[..common];
        compile_xgcc(layout, &build, fixture, &stock, baseline)?;
        compile_xgcc(layout, &build, fixture, &opt_in, enabled)?;
        compile_xgcc(layout, &build, fixture, &opt_out, disabled)?;
        assert_same(&stock, &opt_out, fixture)?;
        assert_different(&stock, &opt_in, fixture)?;
    }

    let negative_cases: &[(&str, &[&str], &str)] = &[
        (
            "gcc296_thumb_pool_long_call_arg0_no_arg_negative.c",
            &["-fcall-used-r4"],
            "-fthumb-pool-long-call-arg0",
        ),
        (
            "gcc296_thumb_order_8_0_20_args_wrong_predecessor_negative.c",
            &["-fcall-used-r4"],
            "-fthumb-order-8-0-20-args",
        ),
        (
            "gcc296_thumb_shift_before_store_in_split_volatile_negative.c",
            &["-fcall-used-r4", "-fsched-low-dest-first"],
            "-fthumb-shift-before-store-in-split",
        ),
        (
            "gcc296_thumb_zero_r1_before_r0_load_after_8_2_volatile_negative.c",
            &["-fcall-used-r4"],
            "-fthumb-zero-r1-before-r0-load-after-8-2",
        ),
        (
            "gcc296_thumb_call_arg12_before_arg0_negative.c",
            &["-fcall-used-r4"],
            "-fthumb-call-arg12-before-arg0",
        ),
        (
            "gcc296_thumb_literal_arg1_before_zero_pair_negative.c",
            &["-fcall-used-r4"],
            "-fthumb-literal-arg1-first-before-zero-pair",
        ),
        (
            "gcc296_thumb_sink_constant_past_call_args_negative.c",
            &["-fcall-used-r4"],
            "-fthumb-sink-constant-past-call-args",
        ),
        (
            "gcc296_thumb_call_target_before_final_shift_negative.c",
            &["-fcall-used-r4"],
            "-fthumb-call-target-before-final-shift",
        ),
        (
            "gcc296_thumb_scene_call_sheets_negative.c",
            &[
                "-fcall-used-r4",
                "-fno-gcse",
                "-fno-cse-two-insn-immediate",
                "-fno-cse-pool-immediate",
                "-fsched-low-dest-first",
            ],
            "-fthumb-scene-call-sheets",
        ),
        (
            "gcc296_thumb_single_arg_immediate_before_halfword_store_negative.c",
            &["-fcall-used-r4"],
            "-fthumb-single-arg-immediate-before-halfword-store",
        ),
        (
            "gcc296_thumb_pool_zero_r8_after_r9_negative.c",
            &["-fcall-used-r4"],
            "-fthumb-pool-zero-r8-after-r9",
        ),
        (
            "gcc296_thumb_pool_r1_lsl4_negative.c",
            &["-fcall-used-r4", "-fsched-low-dest-first"],
            "-fthumb-pool-r1-lsl4",
        ),
        (
            "gcc296_thumb_pool_r1_lsl4_negative.c",
            &["-fcall-used-r4"],
            "-fthumb-pool-r1-lsl4",
        ),
        (
            "gcc296_thumb_strict_addsi_imm_negative.c",
            &["-fcall-used-r4"],
            "-fthumb-strict-addsi-imm",
        ),
        (
            "gcc296_sextqi_minuend_base_conflict_negative.c",
            &["-fcall-used-r4"],
            "-fsextqi-minuend-base-conflict",
        ),
        (
            "gcc296_thumb_3ce_value_entry_cluster.c",
            &[
                "-DVALUE_ENTRY_NEAR_MISS",
                "-fcall-used-r4",
                "-mgrouped-dma-store",
                "-fno-flow2-cleanup-cfg",
                "-fno-cse-two-insn-immediate",
                "-fno-reload-cse-regs",
                "-fthumb-group-value1-before-base",
                "-fthumb-group-value1-in-place",
                "-fthumb-sink-group-pool-loads",
                "-fthumb-group-control-last",
                "-fthumb-hoist-add-immediate",
            ],
            "-fthumb-3ce-value-entry-cluster",
        ),
        (
            "gcc296_thumb_38f_call_cluster.c",
            &["-DCALL_CLUSTER_NEAR_MISS", "-fcall-used-r4"],
            "-fsched-38f-call-cluster",
        ),
        (
            "gcc296_no_hoist_volatile_address_negative.c",
            &["-fcall-used-r4"],
            "-fno-hoist-volatile-address",
        ),
    ];
    for (index, (fixture, baseline, mode)) in negative_cases.iter().enumerate() {
        let stock = scratch.join(format!("negative-{index}-stock.s"));
        let opt_in = scratch.join(format!("negative-{index}-in.s"));
        let mut enabled = baseline.to_vec();
        enabled.push(mode);
        compile_xgcc(layout, &build, fixture, &stock, baseline)?;
        compile_xgcc(layout, &build, fixture, &opt_in, &enabled)?;
        assert_same(&stock, &opt_in, fixture)?;
    }

    let volatile_flag_index = scratch.join("shift-before-volatile-store.s");
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_shift_before_store_in_split_volatile.c",
        &volatile_flag_index,
        &[
            "-fcall-used-r4",
            "-fsched-low-dest-first",
            "-fthumb-shift-before-store-in-split",
        ],
    )?;
    assert_contains(
        &volatile_flag_index,
        "mov\tr1, #225\n\torr\tr3, r3, r2\n\tlsl\tr1, r1, #1\n\tstrb\tr3, [r0]",
        "volatile flag update keeps the independent scene index ahead of its store",
    )?;

    let immediate_before_store = scratch.join("single-arg-immediate-before-halfword-store.s");
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_single_arg_immediate_before_halfword_store.c",
        &immediate_before_store,
        &[
            "-fcall-used-r4",
            "-fthumb-single-arg-immediate-before-halfword-store",
        ],
    )?;
    assert_contains(
        &immediate_before_store,
        "mov\tr0, #113\n\tstrh\tr3, [r2]\n\tbl\tfixture_cue",
        "single-argument immediate is issued before the halfword store",
    )?;

    let boolean_r8_enabled = scratch.join("boolean-r8-scratch-r2-enabled.s");
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_boolean_r8_scratch_r2.c",
        &boolean_r8_enabled,
        &["-fcall-used-r4", "-fthumb-boolean-r8-scratch-r2"],
    )?;
    assert_contains(
        &boolean_r8_enabled,
        "mov\tr2, #1\n\tmov\tr0, #111\n\tsub\tr5, r5, #1\n\tmov\tr8, r2",
        "boolean r8 positive fixture uses r2 on the decrement side",
    )?;
    assert_contains(
        &boolean_r8_enabled,
        "mov\tr2, r8\n\tcmp\tr2, #0",
        "boolean r8 positive fixture uses r2 for the post-call test",
    )?;
    assert_contains(
        &boolean_r8_enabled,
        "mov\tr3, #1\n\tmov\tr0, #111\n\tadd\tr5, r5, #1\n\tmov\tr8, r3",
        "boolean r8 negative increment twin remains in r3",
    )?;

    let store_positive = scratch.join("store-before-pool-load-positive.s");
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_store_before_pool_load.c",
        &store_positive,
        &[
            "-fcall-used-r4",
            "-fno-gcse",
            "-fno-cse-two-insn-immediate",
            "-fno-cse-pool-immediate",
            "-fsched-low-dest-first",
            "-fthumb-store-before-pool-load",
        ],
    )?;
    assert_contains(
        &store_positive,
        "mov	r1, #200\n\tstrb	r2, [r3]\n\tldr	r0",
        "store/pool positive fixture puts the byte store before the pool load",
    )?;

    let store_negative_stock = scratch.join("store-before-pool-load-negative-stock.s");
    let store_negative_enabled = scratch.join("store-before-pool-load-negative-enabled.s");
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_store_before_pool_load_negative.c",
        &store_negative_stock,
        &[
            "-fcall-used-r4",
            "-fno-gcse",
            "-fno-cse-two-insn-immediate",
            "-fno-cse-pool-immediate",
            "-fsched-low-dest-first",
        ],
    )?;
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_store_before_pool_load_negative.c",
        &store_negative_enabled,
        &[
            "-fcall-used-r4",
            "-fno-gcse",
            "-fno-cse-two-insn-immediate",
            "-fno-cse-pool-immediate",
            "-fsched-low-dest-first",
            "-fthumb-store-before-pool-load",
        ],
    )?;
    assert_same(
        &store_negative_stock,
        &store_negative_enabled,
        "store/pool negative halfword fixture is not reordered",
    )?;

    let reg_order_negative_stock = scratch.join("reg-order-negative-stock.s");
    let reg_order_negative_callee = scratch.join("reg-order-negative-callee.s");
    let reg_order_negative_high = scratch.join("reg-order-negative-high.s");
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_reg_order_negative.c",
        &reg_order_negative_stock,
        &["-fcall-used-r4"],
    )?;
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_reg_order_negative.c",
        &reg_order_negative_callee,
        &["-fcall-used-r4", "-mcallee-reg-order=0132"],
    )?;
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_reg_order_negative.c",
        &reg_order_negative_high,
        &["-fcall-used-r4", "-mhigh-reg-order=1203"],
    )?;
    assert_same(
        &reg_order_negative_stock,
        &reg_order_negative_callee,
        "callee-reg-order negative fixture is unchanged",
    )?;
    assert_same(
        &reg_order_negative_stock,
        &reg_order_negative_high,
        "high-reg-order negative fixture is unchanged",
    )?;

    let stack_table_positive_stock = scratch.join("stack-table-positive-stock.s");
    let stack_table_positive_enabled = scratch.join("stack-table-positive-enabled.s");
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_stack_slot_before_table.c",
        &stack_table_positive_stock,
        &["-fcall-used-r4"],
    )?;
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_stack_slot_before_table.c",
        &stack_table_positive_enabled,
        &["-fcall-used-r4", "-fthumb-stack-slot-before-table"],
    )?;
    assert_contains(
        &stack_table_positive_stock,
        "ldr\tr3, [r5]",
        "stack/table positive fixture starts with the stock stack selector register",
    )?;
    assert_contains(
        &stack_table_positive_enabled,
        "ldr\tr2, [r5]",
        "stack/table positive fixture allocates the stack selector in r2",
    )?;
    assert_different(
        &stack_table_positive_stock,
        &stack_table_positive_enabled,
        "stack/table positive fixture changes only with the opt-in mode",
    )?;

    let pool_positive = scratch.join("pool-long-positive.s");
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_pool_long_call_arg0.c",
        &pool_positive,
        &["-fcall-used-r4", "-fthumb-pool-long-call-arg0"],
    )?;
    assert_contains(
        &pool_positive,
        ".word\t7264",
        "thumb pool long arg0 pools 0x1c60",
    )?;

    let pool_interleaved = scratch.join("pool-long-interleaved.s");
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_pool_long_call_arg0_interleaved.c",
        &pool_interleaved,
        &[
            "-fcall-used-r4",
            "-fthumb-no-constant-reuse",
            "-fsched-low-dest-first",
            "-fthumb-pool-long-call-arg0",
        ],
    )?;
    assert_contains(
        &pool_interleaved,
        "mov\tr1, #208\n\tmov\tr0, #1\n\tlsl\tr1, r1, #8",
        "thumb pool long arg0 witnesses an interleaved split setup",
    )?;
    assert_contains(
        &pool_interleaved,
        ".word\t7264",
        "thumb pool long arg0 pools 0x1c60 after interleaved setup",
    )?;

    let pair_positive = scratch.join("zero-arg1-positive.s");
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_zero_arg1_before_nonzero_arg0.c",
        &pair_positive,
        &[
            "-fcall-used-r4",
            "-fthumb-no-constant-reuse",
            "-fsched-low-dest-first",
            "-fthumb-order-zero-arg1-before-nonzero-arg0",
        ],
    )?;
    assert_contains(
        &pair_positive,
        "mov\tr1, #0\n\tmov\tr0, #1\n\tbl\tpair_arguments",
        "zero r1/nonzero r0 literal pair",
    )?;
    assert_contains(
        &pair_positive,
        "mov\tr0, #40\n\tbl\tdelay\n\tmov\tr1, #0\n\tmov\tr0, #8\n\tbl\tpair_arguments",
        "zero r1 after a one-argument delay-40 call",
    )?;

    let delay_negative_stock = scratch.join("zero-arg1-delay-negative-stock.s");
    let delay_negative_enabled = scratch.join("zero-arg1-delay-negative-enabled.s");
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_zero_arg1_after_delay_negative.c",
        &delay_negative_stock,
        &[
            "-fcall-used-r4",
            "-fthumb-no-constant-reuse",
            "-fsched-low-dest-first",
        ],
    )?;
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_zero_arg1_after_delay_negative.c",
        &delay_negative_enabled,
        &[
            "-fcall-used-r4",
            "-fthumb-no-constant-reuse",
            "-fsched-low-dest-first",
            "-fthumb-order-zero-arg1-before-nonzero-arg0",
        ],
    )?;
    assert_same(
        &delay_negative_stock,
        &delay_negative_enabled,
        "zero r1 delay mode leaves wrong-delay, wrong-argument, and three-argument calls unchanged",
    )?;

    let ordered_args_stock = scratch.join("ordered-8-0-20-stock.s");
    let ordered_args_enabled = scratch.join("ordered-8-0-20-enabled.s");
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_order_8_0_20_args.c",
        &ordered_args_stock,
        &["-fcall-used-r4"],
    )?;
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_order_8_0_20_args.c",
        &ordered_args_enabled,
        &["-fcall-used-r4", "-fthumb-order-8-0-20-args"],
    )?;
    assert_contains(
        &ordered_args_stock,
        "mov\tr0, #8\n\tmov\tr1, #0\n\tmov\tr2, #20\n\tbl\ttarget",
        "8,0,20 positive fixture has the scheduler's pre-transform order",
    )?;
    assert_contains(
        &ordered_args_enabled,
        "mov\tr2, #20\n\tmov\tr1, #0\n\tmov\tr0, #8\n\tbl\ttarget",
        "8,0,20 transform restores the reference order",
    )?;

    let ordered_args_negative_stock = scratch.join("ordered-8-0-20-negative-stock.s");
    let ordered_args_negative_enabled = scratch.join("ordered-8-0-20-negative-enabled.s");
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_order_8_0_20_args_negative.c",
        &ordered_args_negative_stock,
        &["-fcall-used-r4"],
    )?;
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_order_8_0_20_args_negative.c",
        &ordered_args_negative_enabled,
        &["-fcall-used-r4", "-fthumb-order-8-0-20-args"],
    )?;
    assert_same(
        &ordered_args_negative_stock,
        &ordered_args_negative_enabled,
        "8,0,21 negative fixture is not reordered",
    )?;

    let zero_load_stock = scratch.join("zero-r1-after-8-2-stock.s");
    let zero_load_enabled = scratch.join("zero-r1-after-8-2-enabled.s");
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_zero_r1_before_r0_load_after_8_2.c",
        &zero_load_stock,
        &["-fcall-used-r4"],
    )?;
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_zero_r1_before_r0_load_after_8_2.c",
        &zero_load_enabled,
        &["-fcall-used-r4", "-fthumb-zero-r1-before-r0-load-after-8-2"],
    )?;
    assert_contains(
        &zero_load_stock,
        "mov\tr0, #8\n\tmov\tr1, #2\n\tbl\tlead\n\tldr\tr0, .L3\n\tmov\tr1, #0",
        "8,2 positive fixture has the actual pre-transform forward shape",
    )?;
    assert_contains(
        &zero_load_enabled,
        "mov\tr0, #8\n\tmov\tr1, #2\n\tbl\tlead\n\tmov\tr1, #0\n\tldr\tr0, .L3",
        "zero r1 transform precedes the constant r0 load",
    )?;

    let zero_load_negative_stock = scratch.join("zero-r1-after-8-2-negative-stock.s");
    let zero_load_negative_enabled = scratch.join("zero-r1-after-8-2-negative-enabled.s");
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_zero_r1_before_r0_load_after_8_2_negative.c",
        &zero_load_negative_stock,
        &["-fcall-used-r4"],
    )?;
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_zero_r1_before_r0_load_after_8_2_negative.c",
        &zero_load_negative_enabled,
        &["-fcall-used-r4", "-fthumb-zero-r1-before-r0-load-after-8-2"],
    )?;
    assert_same(
        &zero_load_negative_stock,
        &zero_load_negative_enabled,
        "8,3 negative fixture is not reordered",
    )?;

    let stack_table_negative_stock = scratch.join("stack-table-negative-stock.s");
    let stack_table_negative_enabled = scratch.join("stack-table-negative-enabled.s");
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_stack_slot_before_table_negative.c",
        &stack_table_negative_stock,
        &["-fcall-used-r4"],
    )?;
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_stack_slot_before_table_negative.c",
        &stack_table_negative_enabled,
        &["-fcall-used-r4", "-fthumb-stack-slot-before-table"],
    )?;
    assert_same(
        &stack_table_negative_stock,
        &stack_table_negative_enabled,
        "stack/table negative fixture is not changed",
    )?;

    let pool_772_stock = scratch.join("pool-772-stock.s");
    let pool_772_enabled = scratch.join("pool-772-enabled.s");
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_pool_long_call_arg0_772.c",
        &pool_772_stock,
        &["-fcall-used-r4"],
    )?;
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_pool_long_call_arg0_772.c",
        &pool_772_enabled,
        &["-fcall-used-r4", "-fthumb-pool-long-call-arg0"],
    )?;
    assert_same(
        &pool_772_stock,
        &pool_772_enabled,
        "thumb pool long arg0 leaves 772 unchanged",
    )?;
    assert_contains(
        &pool_772_enabled,
        "mov\tr0, #193\n\tlsl\tr0, r0, #2",
        "thumb pool long arg0 keeps 772 split",
    )?;

    let pool_r1_lsl4_enabled = scratch.join("pool-r1-lsl4-enabled.s");
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_pool_r1_lsl4.c",
        &pool_r1_lsl4_enabled,
        &[
            "-fcall-used-r4",
            "-fsched-low-dest-first",
            "-fthumb-pool-r1-lsl4",
        ],
    )?;
    assert_contains(
        &pool_r1_lsl4_enabled,
        "ldr\tr1, .L",
        "thumb pool r1 lsl4 loads the literal from the pool",
    )?;
    assert_contains(
        &pool_r1_lsl4_enabled,
        "mov\tr0, #4\n\tbl\tevent_push",
        "thumb pool r1 lsl4 keeps the small r0 literal beside the call",
    )?;
    assert_contains(
        &pool_r1_lsl4_enabled,
        ".word\t2080",
        "thumb pool r1 lsl4 pools 0x820",
    )?;
    assert_contains(
        &pool_r1_lsl4_enabled,
        ".word\t2144",
        "thumb pool r1 lsl4 pools 0x860",
    )?;

    // Production routes no scheduling flag, so the shift precedes the small
    // r0 literal; the matcher must pool that order too.
    let pool_r1_lsl4_plain = scratch.join("pool-r1-lsl4-plain.s");
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_pool_r1_lsl4.c",
        &pool_r1_lsl4_plain,
        &["-fcall-used-r4", "-fthumb-pool-r1-lsl4"],
    )?;
    assert_contains(
        &pool_r1_lsl4_plain,
        "ldr\tr1, .L",
        "thumb pool r1 lsl4 loads the literal in shift-first order",
    )?;
    assert_contains(
        &pool_r1_lsl4_plain,
        ".word\t2080",
        "thumb pool r1 lsl4 pools 0x820 in shift-first order",
    )?;
    assert_contains(
        &pool_r1_lsl4_plain,
        ".word\t2144",
        "thumb pool r1 lsl4 pools 0x860 in shift-first order",
    )?;

    let multi_arg_stock = scratch.join("zero-arg1-multi-stock.s");
    let multi_arg_enabled = scratch.join("zero-arg1-multi-enabled.s");
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_zero_arg1_before_nonzero_arg0_multi.c",
        &multi_arg_stock,
        &[
            "-fcall-used-r4",
            "-fthumb-no-constant-reuse",
            "-fsched-low-dest-first",
        ],
    )?;
    compile_xgcc(
        layout,
        &build,
        "gcc296_thumb_zero_arg1_before_nonzero_arg0_multi.c",
        &multi_arg_enabled,
        &[
            "-fcall-used-r4",
            "-fthumb-no-constant-reuse",
            "-fsched-low-dest-first",
            "-fthumb-order-zero-arg1-before-nonzero-arg0",
        ],
    )?;
    assert_same(
        &multi_arg_stock,
        &multi_arg_enabled,
        "zero r1/nonzero r0 mode leaves unrelated multi-arg order unchanged",
    )?;

    let stock = scratch.join("peephole-stock.s");
    let disabled = scratch.join("peephole-disabled.s");
    compile_xgcc(
        layout,
        &build,
        "gcc296_legacy_peephole_numbering.c",
        &stock,
        &["-fcall-used-r4"],
    )?;
    compile_xgcc(
        layout,
        &build,
        "gcc296_legacy_peephole_numbering.c",
        &disabled,
        &["-fcall-used-r4", "-fno-peephole"],
    )?;
    assert_different(&stock, &disabled, "legacy peephole")?;
    println!(
        "gs1cc codegen regressions passed: {} routed modes",
        cases.len() + 1
    );
    Ok(())
}

fn test_agbcc(layout: &Layout, scratch: &Path) -> Result<()> {
    let compiler = layout.build(Target::Agbcc).join("old_agbcc");
    require(&compiler)?;
    let source = layout
        .root
        .join("tests/fixtures/agbcc_literal_before_shift.c");
    let stock = scratch.join("agbcc-stock.s");
    let enabled = scratch.join("agbcc-enabled.s");
    let compile = |output: &Path, extra: Option<&str>| -> Result<()> {
        let mut command = Command::new(&compiler);
        command
            .arg(&source)
            .args(["-mthumb-interwork", "-O2", "-fno-builtin", "-ffreestanding"]);
        if let Some(flag) = extra {
            command.arg(flag);
        }
        command.arg("-o").arg(output);
        run(&mut command)
    };
    compile(&stock, None)?;
    compile(&enabled, Some("-mliteral-before-shift"))?;
    assert_different(&stock, &enabled, "old_agbcc literal-before-shift")?;

    let track_source = layout
        .root
        .join("tests/fixtures/agbcc_track_narrow_value_r1.c");
    let track_stock = scratch.join("agbcc-track-stock.s");
    let track_enabled = scratch.join("agbcc-track-enabled.s");
    let compile_track = |output: &Path, extra: Option<&str>| -> Result<()> {
        let mut command = Command::new(&compiler);
        command.arg(&track_source).args([
            "-mthumb-interwork",
            "-O2",
            "-fno-builtin",
            "-ffreestanding",
        ]);
        if let Some(flag) = extra {
            command.arg(flag);
        }
        command.arg("-o").arg(output);
        run(&mut command)
    };
    compile_track(&track_stock, None)?;
    compile_track(&track_enabled, Some("-mtrack-narrow-value-r1"))?;
    assert_different(
        &track_stock,
        &track_enabled,
        "old_agbcc track-narrow-value-r1",
    )?;
    println!("old_agbcc codegen regression passed");
    Ok(())
}

fn test_compilers(args: &[String]) -> Result<()> {
    let token = match args {
        [] => "all",
        [one] => one.as_str(),
        _ => return Err("usage: alchemy-gcc test [gs1cc|all]".into()),
    };
    require_binutils()?;
    let layout = Layout::discover()?;
    // A regression run against yesterday's build can look green while the
    // edited compiler source is broken. Re-enter the canonical build first;
    // make reuses current objects, and `check_bundle` then forces the caller
    // to stage any byte-different runtime before tests continue.
    match token {
        "gs1cc" => build_gcc_tree(&layout, Target::Gs1cc)?,
        "all" => {
            build_gcc_tree(&layout, Target::Gs1cc)?;
            build_gcc_tree(&layout, Target::Gs2cc)?;
            build_agbcc(&layout)?;
        }
        _ => return Err(format!("unknown test target: {token}")),
    }
    let _bundle_lock = lock_bundle(&layout.dist, false)?;
    check_bundle(&layout, Target::Gs1cc)?;
    let scratch = Scratch::new()?;
    match token {
        "gs1cc" => test_gs1cc(&layout, &scratch.0),
        "all" => {
            test_gs1cc(&layout, &scratch.0)?;
            test_agbcc(&layout, &scratch.0)?;
            println!("all compiler codegen regressions passed");
            Ok(())
        }
        _ => unreachable!("test target was validated before building"),
    }
}

fn main() {
    let args: Vec<String> = env::args().skip(1).collect();
    let result = match args.split_first() {
        Some((command, rest)) if command == "stage" => stage(rest),
        Some((command, rest)) if command == "install" => install(rest),
        Some((command, rest)) if command == "build" => build(rest),
        Some((command, rest)) if command == "test" => test_compilers(rest),
        _ => Err("usage: alchemy-gcc <build|stage|install|test> ...".into()),
    };
    if let Err(error) = result {
        eprintln!("error: {error}");
        std::process::exit(1);
    }
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
        assert_eq!(artifacts(Target::Gs1cc).len(), 4);
        assert_eq!(artifacts(Target::Gs2cc).len(), 4);
        assert_eq!(artifacts(Target::Agbcc), &[("old_agbcc", "old_agbcc")]);
        assert!(Target::parse("gcc2951").is_err());
        assert!(Target::parse("gcc296").is_err(), "the version-numbered name is retired");
        assert!(Target::parse("gcc3").is_err(), "stock gcc 3.0 is not a separate target");
        assert!(Target::parse("gs2cc-stock").is_err(), "gs2cc IS stock gcc 3.0 now");
        assert!(Target::parse("pretearlythumb").is_err());
    }

    #[test]
    fn install_shapes_keep_full_gcc_tools_and_nested_agbcc_binary() {
        assert_eq!(
            install_artifacts(Target::Gs1cc),
            &["cc1", "xgcc", "cpp", "tradcpp"]
        );
        assert_eq!(install_artifacts(Target::Agbcc), &["old_agbcc"]);
    }
}
