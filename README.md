# camelot-gcc

Patched stock GCC reproducing Camelot's GBA-era codegen byte-identically.
Used by the [goldensun decomp](https://github.com/Coaltergeist/goldensun-decomp)
and, in principle, any other Camelot GBA matching-decomp project (Mario
Tennis / Mario Golf would need different patches that haven't been written
yet; see "Scope" below).

This repo ships two compilers in parallel:

| Compiler | Vendored at | Build / install | Decomp install path |
|---|---|---|---|
| **gcc-2.96 dev snapshot (2000-07-31)** | `gcc-2.96/` | `build-296.sh` / `install-296.sh` | `tools/gcc296/` |
| gcc-3.0 release | `gcc-3.0/` | `build.sh` / `install.sh` | `tools/gcc3/` |

**gcc-2.96 is the default for GS1 work** and produces the full goldensun
ROM byte-identically against the current goldensun-decomp Makefile flag
set. gcc-3.0 is kept around as a clean modern-host-buildable GS2 starting
point (Camelot forked their toolchain around the GS1 → GS2 transition); it
is not currently wired into goldensun-decomp. See "Validation" below.

This repo mirrors the [pret/agbcc](https://github.com/pret/agbcc) shape:
vendored compiler source, a build script per compiler, an install script
per compiler that copies binaries into a sibling decomp checkout.

## Quick start (gcc-2.96, default for GS1)

```sh
sudo apt install -y build-essential                      # one-time
./build-296.sh                                           # ~5-10 min
./install-296.sh <YOUR GOLDENSUN-DECOMP LOCATION>        # copy binaries
```

The vendored tree ships pre-generated `configure`, `c-parse.c`, `c-gperf.h`
etc. and the build scripts pin their timestamps newer than their `.in` /
`.y` / `.gperf` inputs (see "Modern host compatibility" below), so
`autoconf`, `bison`, `flex`, `m4`, and `gperf` are not invoked and don't
need to be installed.

After install, the goldensun Makefile finds the compiler at `tools/gcc296/`
by default (`GCC296_DIR ?= tools/gcc296`).

## Quick start (gcc-3.0, alt / GS2 starting point)

```sh
./build.sh                                               # ~5-10 min
./install.sh <YOUR GOLDENSUN-DECOMP LOCATION>            # copy binaries
```

Installs to `tools/gcc3/`. The goldensun build does not consume this path
by default any more; it's available for opt-in testing or for downstream
projects (like GS2 work) that need a 3.0 baseline.

## Validation

**gcc-2.96** against the goldensun-decomp Makefile flag set produces SHA1
`5c4695205413df7db52b9a184815a07783999971` for the full byte-identical
Golden Sun ROM. This is the supported, regression-tested path.

**gcc-3.0** builds successfully on modern hosts but is not currently wired
into goldensun-decomp's Makefile (which was scrubbed to gcc-2.96-only when
2.96 became production). gcc-3.0 cannot reach fingerprint #5 (MULT → shift-
add) natively, so historical byte-identity under 3.0 depended on source-
side workarounds in the decomp. The 3.0 build is kept here as a clean
modern-host-buildable starting point for GS2 work, not as a regression-
tested GS1 path.

## Patches applied to vendored gcc-2.96 source

Seven small patches against the gcc-2.96 20000731 Debian dev snapshot. The
first six make the 2000-era source compile on a modern host (Ubuntu 22.04
plus gcc-11). The seventh is the only Camelot-flavor codegen patch.

1. **`config.sub` / `config.guess`:** refreshed from GNU savannah (originals
   predate x86_64 standardization).
2. **`gcc/configure` x86_64 host:** 2.96 has no `config.gcc`; the host
   table lives directly in `configure`. Two awk inserts (cloned from i386
   entries); safe because host config only affects the cc1 binary itself.
3. **`gcc/collect2.c`:** add `, 0666` mode arg to `open(redir, O_WRONLY |
   O_TRUNC | O_CREAT)`. Modern glibc `_FORTIFY_SOURCE` rejects `O_CREAT`
   without a mode argument.
4. **Touch pre-shipped parser outputs:** `gcc/c-parse.c` and
   `gcc/cstamp-h.in` are touched newer than `gcc/c-parse.y`. Modern bison
   (3.8.x) rejects 2.96's `c-parse.y` due to stricter midrule typing; the
   pre-shipped `c-parse.c` is fine and just needs to be newer than the .y.
5. **Exec bits:** restored on `configure` / `config.sub` / `config.guess` /
   `install-sh` / etc. via `find -exec chmod +x` in build-296.sh. (Windows-
   side extraction often strips these.)
6. **`gcc/c-gperf.h` `is_reserved_word` static qualifier:** the pre-shipped
   `c-gperf.h` declares `__inline struct resword *is_reserved_word(...)`
   without `static`. Modern gcc-10+ defaults to C99 inline semantics and
   refuses to emit an out-of-line copy of a non-static inline function that
   references static symbols (`wordlist`, `hash`). c-lex.c is the only file
   that includes c-gperf.h, so adding `static` to the declaration and
   definition is safe and gives the compiler full freedom to inline or
   emit a file-local copy. (`hash` was already `static __inline`; only
   `is_reserved_word` was missing the qualifier.) `-fcommon` is also added
   in build-296.sh; gcc-10+ flipped the default to `-fno-common` and some
   2.96 tentative definitions need the old merge behavior.
7. **`gcc/config/arm/elf.h` `ASM_OUTPUT_ALIGN`:** emit `.align N, 0`
   instead of `.align N`. Forces zero-fill on alignment padding bytes in
   `.text`. Modern `arm-none-eabi-as` fills alignment gaps with Thumb nops
   (`46c0`); Camelot's binutils filled with zeros. This is the only
   codegen-affecting patch.

Both build scripts target the four host binaries directly from the gcc/
subdir (`make cc1 xgcc cpp tradcpp` for 2.96, `make cc1 xgcc cpp0 tradcpp0`
for 3.0) instead of going through the top-level `make all-gcc` umbrella.
This bypasses both fixinc (which has a static-vs-extern collision with
modern gcc and is unneeded for a freestanding cross-compile) and the
top-level configure stub (which depends on `configure.in` regen rules).

## Patches applied to vendored gcc-3.0 source

Five small patches against pristine `gcc-3.0.tar.gz`. The first four make
the 2001 source compile on a modern host. The fifth is the only Camelot-
flavor patch.

1. **`config.sub` / `config.guess`:** refreshed from GNU savannah.
2. **`gcc/config.gcc`:** x86_64 host handling (two case-statement additions,
   cloned from i386 entries).
3. **`gcc/config/arm/arm.c:8946`:** `DECL_RTL (sym) = new;` →
   `SET_DECL_RTL (sym, new);`. gcc-3.0 migrated `DECL_RTL` to a ternary
   expression but missed updating this arm.c call site.
4. **`gcc/collect2.c:1613`:** add `, 0666` to `open()` call.
5. **`gcc/config/arm/elf.h` `ASM_OUTPUT_ALIGN`:** same zero-fill patch as
   the 2.96 version.

## Modern host compatibility

Three build-script behaviors (in `build-296.sh` / `build.sh`) keep the
2000-era source compiling cleanly on increasingly aggressive modern hosts:

1. **`-std=gnu17` / `-std=gnu++17`** added to host CFLAGS/CXXFLAGS. gcc-15+
   defaults to C23, which makes implicit-int and K&R-style declarations
   hard errors that `-Wno-implicit-int` etc. cannot silence. Pinning the
   standard back to C17 restores the pre-C23 leniency.
2. **`-fcommon`** added to host CFLAGS for gcc-2.96 (not needed for 3.0).
   gcc-10 flipped the default to `-fno-common`; some 2.96 tentative
   definitions need the old merge semantics.
3. **Generator-input timestamp pin** (Stage 0). `git clone` does not
   preserve mtimes. After a fresh clone, `configure.in` / `*.y` / `*.gperf`
   can randomly land newer than their pre-shipped `configure` / `.c` /
   `.h` outputs, which makes `make` try to re-run `autoconf` / `bison` /
   `gperf`. Modern m4 (1.4.19+) hits its 1024-call recursion limit on the
   old `AC_*` macros; modern bison rejects 2.96's midrule typing; gperf
   may not even be installed. Stage 0 stamps the inputs OLD and the
   outputs NEW so make sees them as up-to-date and these tools never run.

The Stage-4 `make` invocation also passes `CFLAGS=...` as a command-line
make variable instead of a shell environment prefix; gcc's `Makefile.in`
hard-codes its own `CFLAGS = -O2 -g`, and per make precedence rules a
Makefile internal assignment beats inherited environment but not a
command-line override.

## Vendored tree contents

The `gcc-2.96/` and `gcc-3.0/` trees ship only what's needed to build a
C-only `arm-elf` / `arm-agb-elf` cross-compiler. Removed from the upstream
sources: C++/Fortran/Java/Chill/Objective-C frontends, libstdc++, libio,
libf2c, libjava, libffi, boehm-gc, zlib, fastjar, libobjc, libchill,
texinfo, gcc's testsuite, NLS catalogs in `gcc/po/`, and `fixinc/` build
products. Each tree is ~37 MB (down from upstream's ~89 MB / ~105 MB).
Generator inputs (`configure.in`, `*.y`, `*.gperf`, `acconfig.h`) are kept
in tree but timestamp-pinned old at build time; see "Modern host
compatibility" above.

## Compile flags the goldensun Makefile uses

Discovered by Karathan via Compiler Explorer (`cexplore.karathan.at/z/ylD5Df`):

```
-O2 -mthumb -mthumb-interwork -mcpu=arm7tdmi
-fno-builtin -nostdinc -ffreestanding
-fcall-used-r4
```

`-fcall-used-r4` marks r4 caller-clobbered (Camelot's ABI convention).

The gcc-3.0 install pipeline additionally sets `-ffixed-r7` (reserves r7
from register allocation); gcc-2.96 naturally avoids r7 for the same
allocation patterns and doesn't need the flag.

## Camelot codegen fingerprint summary

| # | Pattern | Solved by |
|---|---|---|
| 1 | r4 is caller-saved | `-fcall-used-r4` flag (both compilers) |
| 2 | Reverse `REG_ALLOC_ORDER` | Inherent to gcc-2.95+ Thumb backend |
| 3 | Thumb instruction scheduling | Inherent to gcc-2.95+ Thumb scheduler |
| 4 | Small-const literal-pool preference | `unsigned short` halfword target triggers `ldrh from pool` natively in both compilers |
| 5 | MULT-by-non-power-of-2 → shift-add | gcc-2.96 cost model (gcc-3.0 cannot reach) |
| 6 | `.align` padding = `0000` (not Thumb-nop) | `elf.h` patch (both compilers) |
| 7 | r7 reserved | `-ffixed-r7` flag (gcc-3.0) / inherent (gcc-2.96) |
| 8 | No STMIA merge on 3 consecutive stores | Source-side: array indexing instead of byte-pointer cast |
| 9 | Small-const pooling in the animation/VFX subsystem | No patch needed; SOLVED + demonstrated: the constants are absolute asset-symbols |

#4 in particular was open for a long time and is worth highlighting: it is
triggered specifically by `unsigned short` halfword stores of small (≤255)
immediates. Both stock gcc-2.96 and gcc-3.0 will emit `ldrh rX, .Lpool` +
`.word <value>` at pool slot 0 (displacing source-ordered symbol entries)
rather than `mov rX, #imm; strh`. Variants with `unsigned char` or
`unsigned int` targets emit the inline `mov` and don't trigger the
fingerprint. No special compiler patch needed; sieves and decompilers
just need to emit the correct halfword type for halfword globals.

#9 is a separate shape (previously lumped under #4): a *word* `ldr rX, =<small const>`
for a small (≤255) value where stock gcc-2.96 would emit an inline `mov rX, #imm`. It is
concentrated in the battle-animation / VFX subsystem (~424 functions, ~1,110 sites) and
cleanly partitions the ROM (every byte-matched function is free from #9). The cause is **named
absolute symbols** in Camelot's source: the pooled values are asset/file/message IDs, and
since a symbol can't be an 8-bit immediate, gcc *must* pool it as a word `ldr` (no patch, no
flag, and it's not register pressure, so the permuter can't reach it from a plain literal).
The fix mirrors that: define `_NAME = value;` in a `.sym` INCLUDEd by the linker script plus a
`#define NAME ((int)&_NAME)` macro, and reference it from C as `NAME`; gcc emits the pooled
`ldr`, which links to the exact ROM byte. No byte-comparison change was needed (the
goldensun-decomp judge already diffs with `objdump -dr`). Confirmed end-to-end 2026-06-01 on
`Func_8091d94` (LearnInnateMove): judge PASS + `compare-rom` OK, committed to `src/`. Homes:
file IDs (gFileTable indices, incl. the VFX bulk) → `file_table.sym` / `include/file_table.h`
(`FILE_*`); message/text IDs → `message.sym` / `include/message.h` (`MSG_*`). It stays a
"theory" only because the proving relocation was link-erased (a literal and a resolved symbol
give identical bytes), but it's the working no-patch mechanism.

## Scope

- **GS1 (Golden Sun, 2001):** byte-identical match validated under gcc-2.96.
  gcc-3.0 builds but is not currently wired into the decomp (see Validation).
- **GS2 (The Lost Age, 2002):** Camelot used a *fork* of GCC for GS2, not
  stock. Custom optimizations (BL→BLX inline, magic-number divide). Patches
  for GS2 reproduction haven't been written. The gcc-3.0 baseline in this
  repo is likely the right starting point when that work begins.
- **Other Camelot GBA games** (Mario Tennis, Mario Golf): newer Camelot
  fork (switch jump tables in `.data` instead of function body). Same
  story; out of scope today.

## Credits

- **FutureFractal:** identified GS1 compiler as stock GCC 3.0-era,
  distinguished from GS2's Camelot fork.
- **Tarpman:** 2021 forum thread documenting Camelot fingerprints #1-#5;
  2026 repro candidate that pinned down fingerprint #4's trigger.
- **Karathan:** published the working flag set (`-fcall-used-r4 -ffixed-r7`)
  on Compiler Explorer.
- The GBA decomp community at large for the pret/agbcc pattern this repo
  imitates.
