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

Both reproduce the full goldensun ROM byte-identically. **gcc-2.96 is the
default for GS1 work** because it natively reproduces several ASM 
fingerprints, which stock gcc-3.0 cannot reach via any flag combination.
gcc-3.0 stays around for cross-checking and as a starting point for the
eventual GS2 compiler (Camelot forked their toolchain around the GS1 → GS2
transition).

This repo mirrors the [pret/agbcc](https://github.com/pret/agbcc) shape:
vendored compiler source, a build script per compiler, an install script
per compiler that copies binaries into a sibling decomp checkout.

## Quick start (gcc-2.96, default for GS1)

```sh
sudo apt install -y bison flex texinfo build-essential   # one-time
./build-296.sh                                           # ~5-10 min
./install-296.sh <YOUR GOLDENSUN-DECOMP LOCATION>        # copy binaries
```

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

Both compilers, against their respective Makefile flag sets, produce SHA1
`5c4695205413df7db52b9a184815a07783999971` for the full byte-identical 
Golden Sun ROM.

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

`build-296.sh` builds `cc1` / `xgcc` / `cpp` / `tradcpp` directly via
`make cc1 xgcc cpp tradcpp` (not `make all-gcc`), because fixinc has a
static-vs-extern collision with modern gcc and we don't need fixinc for a
freestanding cross-compile.

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

#4 in particular was open for a long time and is worth highlighting: it is
triggered specifically by `unsigned short` halfword stores of small (≤255)
immediates. Both stock gcc-2.96 and gcc-3.0 will emit `ldrh rX, .Lpool` +
`.word <value>` at pool slot 0 (displacing source-ordered symbol entries)
rather than `mov rX, #imm; strh`. Variants with `unsigned char` or
`unsigned int` targets emit the inline `mov` and don't trigger the
fingerprint. No special compiler patch needed; sieves and decompilers
just need to emit the correct halfword type for halfword globals.

## Scope

- **GS1 (Golden Sun, 2001):** byte-identical match validated under both
  compilers; gcc-2.96 is the default.
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
