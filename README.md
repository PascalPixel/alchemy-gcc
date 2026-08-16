# alchemy-gcc

The compilers *Golden Sun* was built with, for
[Alchemy](https://github.com/PascalPixel/alchemy).

| | | |
|---|---|---|
| `gs1cc` | Golden Sun's compiler | a 2000-07-31 gcc 2.96 development snapshot |
| `gs2cc` | The Lost Age's compiler | gcc 3.0.0 |
| `agbcc` | the Thumb audio compiler | `pret/agbcc`, built as `old_agbcc` |

Named for the job they do. A version number in a compiler's name is a lie
waiting to happen: "gcc 2.96" was never an FSF release, and in an earlier
arrangement a GS2 build was routed under the family name `gcc296` while
actually running the gcc-3.0-derived binary.

## Where this came from, and what we changed

**The first commit of this repository is those three trees, untouched, straight
from their upstreams.** Everything after it is a commit with a reason. So:

```sh
make ours     # every file we modified, per tree, against untouched upstream
git log       # why each one changed
```

`PROVENANCE.txt` records the exact upstream commit behind each tree. Two of the
three were identified by measurement rather than inheritance: gcc 3.0.0 matches
1441 of 1464 shared files against 1332 for 3.0.1, and `da598c1d` is the best
match across all 203 commits in `pret/agbcc`'s history.

This matters because the repository this replaced could not answer either
question. Its compilers arrived already patched, and auditing them afterwards
turned up 120 invented compiler options in the 2.96 tree, an invented
`-mcamelot-gs2` in the 3.0 tree, and ten more in agbcc — five of which were
dead and have since been removed at no cost to the match.

## One compiler, one configuration

No build modes, no environment switches, and no compiler option gcc did not
ship. When a function will not match, the answer is in the C. An invented
option does not solve an unmatched function; it makes that function permanently
unsolvable, because nothing outside this repository can reproduce it.

Exactly one change in this repository alters emitted bytes: `ASM_OUTPUT_ALIGN`
emits `.align N, 0`, forcing zero-fill padding. It is alone in its own commit
so that measuring it is a one-line revert. It has never actually been measured.

## Build

Requirements: Rust/Cargo, a host C toolchain with `make`, and ARM binutils
(`arm-none-eabi-as`, `arm-none-eabi-ar`, or devkitARM).

```sh
make                      # build and stage gs1cc into dist/
make test                 # codegen regressions
make install DECOMP=../alchemy
```

The build driver is Rust (`src/main.rs`) where `pret/agbcc` uses shell. `dist/`
is a staged runtime, not source.

## Acknowledgements

**The GCC developers**, for gcc 2.96 and 3.0 — the compilers themselves, and a
back end still legible twenty-five years later. Sources come from
[gcc-mirror/gcc](https://github.com/gcc-mirror/gcc); notices remain in each
tree's `COPYING` and `COPYING.LIB`.

**[pret](https://github.com/pret)**, whose `agbcc` is vendored here directly,
and whose decompilation projects are the model this one follows: one compiler,
one flag set, per-file overrides counted on one hand, and the discipline that
the difference belongs in the source rather than behind a switch. `pokeemerald`
is the reference for how a decomp survives years rather than months.

**[Coaltergeist](https://github.com/Coaltergeist)**, who did the original work
of identifying which compiler built Golden Sun and assembling a toolchain that
could reproduce it — including the determination, from testing, that GS1
shipped with 2.96 rather than 3.0. Independent measurement here reached the
same conclusion. This repository was rebuilt from upstream rather than
inherited so that its provenance is checkable, which is a statement about
records, not about that work.

**The Golden Sun community**, for the documentation and reverse engineering
that make any of this legible.

## Source and publication boundary

The vendored trees are the corresponding source for the runtimes built here.
Do not publish a staged binary without them. Keep `COPYING*` and the upstream
notices with the source; this README is not a licence statement.
