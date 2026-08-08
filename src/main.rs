use std::env;
use std::fs;
use std::path::{Path, PathBuf};
use std::process::Command;

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

const HOST_CFLAGS: &str = "-O2 -fno-pie -no-pie -Wno-narrowing -Wno-implicit-int -Wno-implicit-function-declaration -Wno-pointer-arith -Wno-int-conversion -Wno-format -Wno-error -std=gnu17 -Wno-incompatible-pointer-types";
const HOST_CXXFLAGS: &str = "-O2 -fno-pie -no-pie -Wno-narrowing -Wno-error -std=gnu++17";
const HOST_LDFLAGS: &str = "-no-pie";

fn run(command: &mut Command) -> Result<()> {
    let display = format!("{command:?}");
    let status = command.status().map_err(|e| format!("could not start {display}: {e}"))?;
    if status.success() { Ok(()) } else { Err(format!("command failed ({status}): {display}")) }
}

fn make_executable_tree(root: &Path) -> Result<()> {
    const HELPERS: &[&str] = &["configure", "config.sub", "config.guess", "install-sh", "mkinstalldirs", "move-if-change", "missing", "ltconfig", "ltmain.sh", "mkdep"];
    fn walk(path: &Path) -> Result<()> {
        for entry in fs::read_dir(path).map_err(|e| format!("{}: {e}", path.display()))? {
            let entry = entry.map_err(|e| e.to_string())?;
            if entry.file_type().map_err(|e| e.to_string())?.is_dir() { walk(&entry.path())?; }
            else if HELPERS.contains(&entry.file_name().to_string_lossy().as_ref()) { set_executable(&entry.path())?; }
        }
        Ok(())
    }
    walk(root)
}

fn files_named(root: &Path, names: &[&str], out: &mut Vec<PathBuf>) -> Result<()> {
    for entry in fs::read_dir(root).map_err(|e| format!("{}: {e}", root.display()))? {
        let entry = entry.map_err(|e| e.to_string())?;
        if entry.file_type().map_err(|e| e.to_string())?.is_dir() { files_named(&entry.path(), names, out)?; }
        else if names.contains(&entry.file_name().to_string_lossy().as_ref()) { out.push(entry.path()); }
    }
    Ok(())
}

fn restamp_generated(source: &Path, marker: &Path) -> Result<()> {
    if marker.is_file() { return Ok(()); }
    let mut inputs = Vec::new();
    files_named(source, &["configure.in", "c-parse.y", "c-gperf.gperf", "acconfig.h"], &mut inputs)?;
    for path in inputs { run(Command::new("touch").args(["-t", "200001010000"]).arg(path))?; }
    let mut outputs = Vec::new();
    files_named(source, &["configure", "c-parse.c", "c-parse.h", "c-gperf.h", "cstamp-h.in", "config.in", "cexp.c", "tradcif.c"], &mut outputs)?;
    for path in outputs { run(Command::new("touch").arg(path))?; }
    Ok(())
}

fn configure<'a>(command: &'a mut Command, cflags: &str) -> &'a mut Command {
    command.env("CFLAGS", cflags).env("CXXFLAGS", HOST_CXXFLAGS).env("LDFLAGS", HOST_LDFLAGS)
}

fn build_gcc_tree(layout: &Layout, target: Target) -> Result<()> {
    let (source, build, triple, extra, cpp, tradcpp) = match target {
        Target::Gcc296 => (layout.root.join("gcc-2.96"), layout.root.join("build-296"), "arm-elf", " -fcommon", "cpp", "tradcpp"),
        Target::Gcc3 => (layout.root.join("gcc-3.0"), layout.root.join("build"), "arm-agb-elf", "", "cpp0", "tradcpp0"),
        Target::Gs2 => (layout.root.join("gcc-3.0"), layout.root.join("build-gs2"), "arm-agb-elf", " -DCAMELOT_GS2_DEFAULT=1", "cpp0", "tradcpp0"),
        Target::Agbcc => return Err("internal target mismatch".into()),
    };
    if !source.is_dir() { return Err(format!("{} not found", source.display())); }
    make_executable_tree(&source)?;
    restamp_generated(&source, &build.join("gcc/Makefile"))?;
    fs::create_dir_all(&build).map_err(|e| e.to_string())?;
    let cflags = format!("{HOST_CFLAGS}{extra}");
    if !build.join("Makefile").is_file() {
        let mut top = Command::new(source.join("configure"));
        configure(&mut top, &cflags).current_dir(&build).arg(format!("--prefix={}", build.join("install").display()))
            .args([format!("--target={triple}"), "--with-cpu=arm7tdmi".into(), "--enable-multilib".into(), "--enable-interwork".into(), "--enable-languages=c".into(), "--without-headers".into(), "--disable-shared".into(), "--disable-threads".into(), "--disable-libstdc++-v3".into(), "--disable-nls".into(), "--disable-win32-registry".into()]);
        let _ = top.status();
    }
    let lib = build.join("libiberty");
    if !lib.join("libiberty.a").is_file() {
        if lib.exists() { fs::remove_dir_all(&lib).map_err(|e| e.to_string())?; }
        fs::create_dir(&lib).map_err(|e| e.to_string())?;
        let mut config = Command::new(source.join("libiberty/configure"));
        configure(&mut config, &cflags).current_dir(&lib)
            .args([format!("--srcdir={}", source.join("libiberty").display()), format!("--prefix={}", build.join("install").display()), "--build=x86_64-unknown-linux-gnu".into(), "--host=x86_64-unknown-linux-gnu".into(), format!("--target={triple}"), "--disable-shared".into(), "--disable-nls".into()]);
        run(&mut config)?;
        run(Command::new("make").current_dir(&lib).arg(format!("-j{}", std::thread::available_parallelism().map(|v| v.get()).unwrap_or(4))))?;
    }
    let gcc = build.join("gcc");
    if !gcc.join("Makefile").is_file() {
        fs::create_dir_all(&gcc).map_err(|e| e.to_string())?;
        let mut config = Command::new(source.join("gcc/configure"));
        configure(&mut config, &cflags).current_dir(&gcc)
            .args([format!("--srcdir={}", source.join("gcc").display()), format!("--prefix={}", build.join("install").display()), "--build=x86_64-unknown-linux-gnu".into(), "--host=x86_64-unknown-linux-gnu".into(), format!("--target={triple}"), "--with-cpu=arm7tdmi".into(), "--enable-multilib".into(), "--enable-interwork".into(), "--enable-languages=c".into(), "--without-headers".into(), "--disable-shared".into(), "--disable-threads".into(), "--disable-nls".into(), "--with-gnu-as".into(), "--with-gnu-ld".into(), "--disable-checking".into()]);
        run(&mut config)?;
    }
    run(Command::new("make").current_dir(&gcc)
        .arg(format!("-j{}", std::thread::available_parallelism().map(|v| v.get()).unwrap_or(4)))
        .arg(format!("CFLAGS={cflags}")).arg(format!("CXXFLAGS={HOST_CXXFLAGS}")).arg(format!("LDFLAGS={HOST_LDFLAGS}"))
        .args(["cc1", "xgcc", cpp, tradcpp]))?;
    for artifact in ["cc1", "xgcc", cpp, tradcpp] { require(&gcc.join(artifact))?; }
    println!("BUILD OK ({})", target.name());
    Ok(())
}

fn build_agbcc(layout: &Layout) -> Result<()> {
    let gcc = layout.root.join("agbcc/gcc");
    if !gcc.is_dir() { return Err(format!("{} not found", gcc.display())); }
    make_executable_tree(&layout.root.join("agbcc"))?;
    run(Command::new("make").current_dir(&gcc).arg("clean"))?;
    run(Command::new("make").current_dir(&gcc).args(["old", "-j1"]))?;
    require(&gcc.join("old_agbcc"))?;
    println!("BUILD OK (agbcc)");
    Ok(())
}

fn build(args: &[String]) -> Result<()> {
    let [token] = args else { return Err("usage: alchemy-gcc build <gcc296|gcc3|gs2|agbcc|all>".into()); };
    let layout = Layout::discover()?;
    let targets = if token == "all" { vec![Target::Gcc296, Target::Gcc3, Target::Gs2, Target::Agbcc] } else { vec![Target::parse(token)?] };
    for target in targets { if matches!(target, Target::Agbcc) { build_agbcc(&layout)?; } else { build_gcc_tree(&layout, target)?; } }
    Ok(())
}

struct Scratch(PathBuf);
impl Scratch {
    fn new() -> Result<Self> {
        let path = env::temp_dir().join(format!("alchemy-gcc-test-{}", std::process::id()));
        if path.exists() { fs::remove_dir_all(&path).map_err(|e| e.to_string())?; }
        fs::create_dir(&path).map_err(|e| e.to_string())?;
        Ok(Self(path))
    }
}
impl Drop for Scratch { fn drop(&mut self) { let _ = fs::remove_dir_all(&self.0); } }

fn compile_xgcc(layout: &Layout, build: &Path, fixture: &str, output: &Path, flags: &[&str]) -> Result<()> {
    let driver = build.join("xgcc");
    require(&driver)?;
    let mut command = Command::new(driver);
    command.arg(format!("-B{}/", build.display()))
        .args(["-O2", "-mthumb", "-mthumb-interwork", "-mcpu=arm7tdmi", "-fno-builtin", "-nostdinc", "-ffreestanding"])
        .args(flags).arg("-S").arg(layout.root.join("tests/fixtures").join(fixture)).arg("-o").arg(output);
    run(&mut command)
}

fn assert_same(left: &Path, right: &Path, context: &str) -> Result<()> {
    if fs::read(left).map_err(|e| e.to_string())? != fs::read(right).map_err(|e| e.to_string())? {
        Err(format!("{context}: expected identical assembly"))
    } else { Ok(()) }
}
fn assert_different(left: &Path, right: &Path, context: &str) -> Result<()> {
    if fs::read(left).map_err(|e| e.to_string())? == fs::read(right).map_err(|e| e.to_string())? {
        Err(format!("{context}: opt-in did not change assembly"))
    } else { Ok(()) }
}

fn test_gcc296(layout: &Layout, scratch: &Path) -> Result<()> {
    let build = layout.build(Target::Gcc296);
    let cases: &[(&str, &[&str], &[&str])] = &[
        ("grouped_dma_store.c", &["-fcall-used-r4", "-mgrouped-dma-store"], &["-fcall-used-r4", "-mno-grouped-dma-store"]),
        ("gcc296_thumb_minipool_tail_first.c", &["-fcall-used-r4", "-fthumb-minipool-tail-first"], &["-fcall-used-r4", "-fno-thumb-minipool-tail-first"]),
        ("gcc296_grouped_dma_extended.c", &["-fcall-used-r4", "-mgrouped-dma-store"], &["-fcall-used-r4", "-mno-grouped-dma-store"]),
        ("gcc296_thumb_bit_tests.c", &["-mpreserve-single-bit-test", "-mentry-low-register-order", "-mthumb-and-sets-cc"], &["-mno-preserve-single-bit-test", "-mno-entry-low-register-order", "-mno-thumb-and-sets-cc"]),
        ("gcc296_early_frame_allocation.c", &["-fcall-used-r4", "-mearly-frame-allocation"], &["-fcall-used-r4", "-mno-early-frame-allocation"]),
        ("gcc296_high_register_move_first.c", &["-fcall-used-r4", "-mhigh-register-move-first"], &["-fcall-used-r4", "-mno-high-register-move-first"]),
        ("gcc296_high_move_before_stack_store.c", &["-fcall-used-r4", "-mgrouped-dma-store", "-fthumb-high-move-before-stack-store"], &["-fcall-used-r4", "-mgrouped-dma-store", "-fno-thumb-high-move-before-stack-store"]),
        ("gcc296_low_constant_before_high_move.c", &["-fcall-used-r4", "-fno-rerun-cse-after-loop", "-fno-regmove", "-fthumb-low-constant-before-high-move"], &["-fcall-used-r4", "-fno-rerun-cse-after-loop", "-fno-regmove", "-fno-thumb-low-constant-before-high-move"]),
        ("gcc296_thumb_orr_dead_input_reuse.c", &["-fcall-used-r4", "-fthumb-orr-dead-input-reuse"], &["-fcall-used-r4", "-fno-thumb-orr-dead-input-reuse"]),
        ("gcc296_thumb_entry_frame_cluster.c", &["-fcall-used-r4", "-fthumb-entry-frame-cluster"], &["-fcall-used-r4", "-fno-thumb-entry-frame-cluster"]),
        ("gcc296_thumb_literal_before_index_shift.c", &["-fcall-used-r4", "-fno-schedule-insns2", "-fthumb-literal-before-index-shift"], &["-fcall-used-r4", "-fno-schedule-insns2", "-fno-thumb-literal-before-index-shift"]),
        ("gcc296_call_arg0_move_first.c", &["-fcall-used-r4", "-mcall-arg0-move-first"], &["-fcall-used-r4", "-mno-call-arg0-move-first"]),
        ("gcc296_thumb_entry_literal_first.c", &["-fcall-used-r4", "-fno-schedule-insns2", "-mthumb-entry-literal-first"], &["-fcall-used-r4", "-fno-schedule-insns2", "-mno-thumb-entry-literal-first"]),
    ];
    for (index, (fixture, enabled, disabled)) in cases.iter().enumerate() {
        let stock = scratch.join(format!("{index}-stock.s"));
        let opt_in = scratch.join(format!("{index}-in.s"));
        let opt_out = scratch.join(format!("{index}-out.s"));
        let common = enabled.iter().zip(disabled.iter()).take_while(|(left, right)| left == right).count();
        let baseline = &enabled[..common];
        compile_xgcc(layout, &build, fixture, &stock, baseline)?;
        compile_xgcc(layout, &build, fixture, &opt_in, enabled)?;
        compile_xgcc(layout, &build, fixture, &opt_out, disabled)?;
        assert_same(&stock, &opt_out, fixture)?;
        assert_different(&stock, &opt_in, fixture)?;
    }
    let stock = scratch.join("peephole-stock.s");
    let disabled = scratch.join("peephole-disabled.s");
    compile_xgcc(layout, &build, "gcc296_legacy_peephole_numbering.c", &stock, &["-fcall-used-r4"])?;
    compile_xgcc(layout, &build, "gcc296_legacy_peephole_numbering.c", &disabled, &["-fcall-used-r4", "-fno-peephole"])?;
    assert_different(&stock, &disabled, "legacy peephole")?;
    println!("gcc296 codegen regressions passed: {} routed modes", cases.len() + 1);
    Ok(())
}

fn test_gcc3_and_gs2(layout: &Layout, scratch: &Path) -> Result<()> {
    let stock = layout.build(Target::Gcc3);
    let gs2 = layout.build(Target::Gs2);
    let native = scratch.join("native.s");
    compile_xgcc(layout, &stock, "native_codegen.c", &native, &["-fcall-used-r4"])?;
    assert_same(&layout.root.join("tests/expected/native_codegen.s"), &native, "native gcc3 fixture")?;

    let stock_out = scratch.join("gs2-stock.s");
    let gs2_out = scratch.join("gs2-default.s");
    let opt_in = scratch.join("gs2-opt-in.s");
    let opt_out = scratch.join("gs2-opt-out.s");
    compile_xgcc(layout, &stock, "gs2_codegen.c", &stock_out, &["-fcall-used-r4"])?;
    compile_xgcc(layout, &gs2, "gs2_codegen.c", &gs2_out, &["-fcall-used-r4"])?;
    compile_xgcc(layout, &stock, "gs2_codegen.c", &opt_in, &["-fcall-used-r4", "-mcamelot-gs2"])?;
    compile_xgcc(layout, &gs2, "gs2_codegen.c", &opt_out, &["-fcall-used-r4", "-mno-camelot-gs2"])?;
    assert_same(&gs2_out, &opt_in, "GS2 default versus opt-in")?;
    assert_same(&stock_out, &opt_out, "stock default versus GS2 opt-out")?;
    assert_different(&stock_out, &gs2_out, "GS2 backend")?;
    let assembly = fs::read_to_string(&gs2_out).map_err(|e| e.to_string())?;
    if !assembly.contains(".short\t0xf800") || assembly.contains("_call_via_") {
        return Err("GS2 indirect-call codegen regression".into());
    }
    println!("gcc3 and GS2 codegen regressions passed");
    Ok(())
}

fn test_agbcc(layout: &Layout, scratch: &Path) -> Result<()> {
    let compiler = layout.build(Target::Agbcc).join("old_agbcc");
    require(&compiler)?;
    let source = layout.root.join("tests/fixtures/agbcc_literal_before_shift.c");
    let stock = scratch.join("agbcc-stock.s");
    let enabled = scratch.join("agbcc-enabled.s");
    let compile = |output: &Path, extra: Option<&str>| -> Result<()> {
        let mut command = Command::new(&compiler);
        command.arg(&source).args(["-mthumb-interwork", "-O2", "-fno-builtin", "-ffreestanding"]);
        if let Some(flag) = extra { command.arg(flag); }
        command.arg("-o").arg(output);
        run(&mut command)
    };
    compile(&stock, None)?;
    compile(&enabled, Some("-mliteral-before-shift"))?;
    assert_different(&stock, &enabled, "old_agbcc literal-before-shift")?;
    println!("old_agbcc codegen regression passed");
    Ok(())
}

fn test_compilers(args: &[String]) -> Result<()> {
    let token = match args { [] => "all", [one] => one.as_str(), _ => return Err("usage: alchemy-gcc test [gcc296|all]".into()) };
    let layout = Layout::discover()?;
    check_bundle(&layout, Target::Gcc296)?;
    let scratch = Scratch::new()?;
    match token {
        "gcc296" => test_gcc296(&layout, &scratch.0),
        "all" => {
            test_gcc296(&layout, &scratch.0)?;
            test_gcc3_and_gs2(&layout, &scratch.0)?;
            test_agbcc(&layout, &scratch.0)?;
            println!("all compiler codegen regressions passed");
            Ok(())
        }
        _ => Err(format!("unknown test target: {token}")),
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
