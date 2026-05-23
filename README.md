# camelot-gcc

Stock GCC 3.0 (arm-agb-elf target) patched to reproduce Camelot's GBA-era
codegen byte-identically. Used by the [goldensun decomp](https://github.com/Coaltergeist/goldensun-decomp) and,
in principle, by any other Camelot GBA matching-decomp project (Mario
Tennis / Mario Golf would need different patches that haven't been written
yet; see "Scope" below).

This repo mirrors the [pret/agbcc](https://github.com/pret/agbcc) shape:
vendored compiler source, `build.sh` to build it, `install.sh` to deploy the
binaries into a sibling decomp checkout.

## Quick start

```sh
sudo apt install -y bison flex texinfo build-essential   # one-time
./build.sh                                               # ~5-10 min
./install.sh ../goldensun-decomp                         # copy binaries to your goldensun-decomp location
```

After install, the goldensun Makefile finds the compiler at `tools/gcc3/`
by default (`GCC3_DIR ?= tools/gcc3`).

## Why stock GCC 3.0

Validated end-to-end: building the full goldensun ROM with this compiler
produces SHA1 `5c4695205413df7db52b9a184815a07783999971`, byte-identical to
the original ROM.

## Patches applied to the vendored gcc-3.0 source

Five small patches against pristine `gcc-3.0.tar.gz`. The first four make
the 2001 source compile on a modern host (Ubuntu 22.04 + gcc-11). The fifth
is the only Camelot-flavor patch.

1. **`config.sub` / `config.guess`:** refreshed from GNU savannah. Originals
   predate x86_64 standardization.
2. **`gcc/config.gcc`:** x86_64 host handling (two case-statement additions,
   cloned from i386 entries; safe because host config only affects the cc1
   binary itself, not its output).
3. **`gcc/config/arm/arm.c:8946`:** `DECL_RTL (sym) = new;` →
   `SET_DECL_RTL (sym, new);`. gcc-3.0 migrated `DECL_RTL` to a ternary
   expression but missed updating this arm.c call site.
4. **`gcc/collect2.c:1613`:** add `, 0666` to `open()` call. Modern glibc
   `_FORTIFY_SOURCE` rejects `O_CREAT` without a mode argument.
5. **`gcc/config/arm/elf.h` `ASM_OUTPUT_ALIGN`:** emit `.align N, 0`
   instead of `.align N`. Forces zero-fill on alignment padding bytes in
   `.text`. Modern `arm-none-eabi-as` fills alignment gaps with Thumb nops
   (`46c0`); Camelot's binutils filled with zeros. This is the only
   codegen-affecting patch.

## Compile flags the goldensun Makefile uses

Discovered by Karathan via Compiler Explorer (`cexplore.karathan.at/z/ylD5Df`):

```
-O2 -mthumb -mthumb-interwork -mcpu=arm7tdmi
-fno-builtin -nostdinc -ffreestanding
-fcall-used-r4 -ffixed-r7
```

- `-fcall-used-r4`: marks r4 caller-clobbered (Camelot's ABI convention).
- `-ffixed-r7`: reserves r7 from register allocation (Camelot uses r7 for
  a runtime convention we don't yet know the purpose of).

## Scope

- **GS1 (Golden Sun, 2001):** byte-identical match validated.
- **GS2 (The Lost Age, 2002):** Camelot used a *fork* of GCC for GS2, not
  stock 3.0. Custom optimizations (BL→BLX inline, magic-number divide).
  Patches for GS2 reproduction haven't been written. This repo will likely
  grow a separate patch set + build target for GS2 when that work begins.
- **Other Camelot GBA games** (Mario Tennis, Mario Golf): newer Camelot
  fork (switch jump tables in `.data` instead of function body). Same
  story; out of scope today.

## Open compiler fingerprints (not yet reproduced for GS1)

Even with the 5 patches above, ~30% of decomp candidates still fail to
byte-match. Two known compiler-side gaps:

- **#4: Small-constant literal-pool preference.** Camelot loads small
  constants (e.g. `mov r3, #0`) via `ldr` from a literal pool. Stock GCC 3.0
  + the patches above prefers `mov #imm`. Affects ~950 sieve candidates.
  Likely a cost-model patch in `gcc/config/arm/arm.c::arm_rtx_costs`, OR
  (per Tarpman's 2021 forum theory) a separate post-compile pool-rewriter
  in Camelot's build pipeline that we'd need to reproduce as a `.s` pass.
- **#5: MULT cost model.** Camelot emits shift-add chains for
  multiplication by non-power-of-2 constants (e.g. `*20` → `<<2; +x; <<2`).
  Stock GCC emits `muls`. Affects ~17 sieve candidates. Probable cause:
  a Camelot tweak to `FL_FAST_MULT` flag handling in arm7tdmi cpu entry.

If you investigate either of these and have findings, please open an issue
or PR.

## Credits

- **FutureFractal:** identified GS1 compiler as stock GCC 3.0, distinguished
  from GS2's Camelot fork.
- **Tarpman:** 2021 forum thread documenting Camelot fingerprints #1-#5.
- **Karathan:** published the working flag set (`-fcall-used-r4 -ffixed-r7`)
  on Compiler Explorer.
- The GBA decomp community at large for the pret/agbcc pattern this repo
  imitates.
