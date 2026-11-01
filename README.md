# 🌋 Alchemy GCC

The compilers that build [Alchemy](https://github.com/PascalPixel/alchemy),
the byte-for-byte reconstruction of Golden Sun: The Broken Seal and The Lost
Age. Three C generators, built from this one repository:

| Generator | Source | Builds |
| --- | --- | --- |
| Alchemy GCC | The GCC 2.96 snapshot of 2000-07-31, with host ports and three Thumb rules | Both games' Thumb C and libgcc |
| GCC 2.95.2 ARM | The GNU release, pinned by SHA-256 in `arm/` | Both games' ARM C |
| old_agbcc | [pret/agbcc](https://github.com/pret/agbcc), pinned and unmodified in `agbcc/` | The sound and flash libraries |

These are reconstruction choices, not Camelot's or Nintendo's own tools.
Matching shows that they produce the games' code; it does not show that they
are the exact compilers Camelot ran. Alchemy's `AGENTS.md` (K1 to K3) owns
which options each game uses and how a compiler change is approved.

## Build

```sh
git submodule update --init --recursive
make            # or: sh build.sh
```

Needs Git, a C compiler, Make, curl, patch and tar; no Bison, flex or gperf,
and no Rosetta. The outputs are `build/gcc/cc1` (with `xgcc`, `cpp0` and
`tradcpp0`), `arm/build/gcc/cc1` and `agbcc/gcc/old_agbcc`. Nothing is
installed or replaced. `ALCHEMY_GCC_JOBS` sets build.sh's parallelism
(default 8).

- `make source-check` refuses a missing, changed or dirty nested compiler.
- `make generated-check` compares the tables the host generators write with
  recorded hashes; they are the same text on every host.
- `make -C arm probe` checks the ARM compiler against text recorded from a
  32-bit build.
- `make clean` removes generated output.

The [ARM compiler recipe](arm/README.md) builds GCC 2.95.2 beside this one
without changing it; its source pin, host fixes (`arm/host.patch`) and
recipe live under `arm/`.

## One host model on every host

Every host builds with one configuration, `config/host`, and one host model,
`config/host.mk`: a 32-bit `HOST_WIDE_INT` (the historical i686 descriptor,
which describes the compiler's integer model, not the host CPU), signed plain
`char`, wrapping signed arithmetic, no type-based aliasing and no fused
multiply-add. `config.h` refuses at compile time a host that cannot provide
it; an i386 host passes `CC="cc -msse2 -mfpmath=sse"`.

The host model matters. A compiler built with a 64-bit `HOST_WIDE_INT` treats
a constant with bit 31 set differently: it loads every such constant from the
literal pool, where The Lost Age builds 584 of them inline and loads none.

Measured on 2026-10-11 by replaying every compile of Alchemy's twelve
editions and comparing the assembler text byte for byte with the reference
build's:

| Host | How it ran | Result |
| --- | --- | --- |
| macOS arm64, Apple clang 21 | native | Every compile identical; all twelve ROMs match from a toolchain built from this source |
| Linux aarch64, Debian 12 (GCC 12.2) | native, in a container | From a clean clone: all twelve ROMs match, Alchemy's tests pass |
| macOS x86-64 | Rosetta 2, not a real Intel Mac | Every compile identical |
| Linux x86-64, Debian 12 | QEMU user emulation | Every distinct compile identical |
| Linux i386, Debian 12 | QEMU user emulation | Every distinct compile identical |
| Linux armv7 (armhf), Debian 12 | QEMU user emulation | Every distinct compile identical |

"Every distinct compile" is all ARM and library compiles, every game compile
whose preprocessed input and options differ, and one whole edition compiled
from source so that the host's own `cpp0` ran too. No real Intel or 32-bit
machine was available; the emulated rows say what they are. The Lost Age's
Thumb rules changed after these measurements, and the hosts have not been
remeasured with them.

## What is in the source

The build enables only C and the ARM backend. The other front ends, target
backends, configure scripts, installation machinery and translation files are
removed; only `i386/xm-i386.h` remains from the i386 backend, for the host
integer model. Native Makefiles list the front end, backend, host library and
generators directly, `config/arm/tconfig.h` and `config/arm/tm.h` replace
what configure generated, and the parsers stay the pinned Bison 1.28 output.
The C tests, test support and upstream licence notices are kept.

## Provenance

The root commit imports GCC upstream revision
`04179d4a511b13cef92eacdb10a51bcd124fea7a` from
[gcc-mirror](https://github.com/gcc-mirror/gcc), the 2000-07-31 snapshot.
Each later commit is one change with its reason in its message:

- **Removing unused source:** the other front ends and backends, without
  changing a retained file.
- **Building on current hosts:** parsers from unmodified GNU Bison 1.28,
  fixed-arity generator calls for Apple's ARM64 calling convention,
  real-constant copies one operand slot at a time for 64-bit host pointers,
  internal linkage for the keyword lookup, Darwin header compatibility, a
  bound on a read of `call_used_regs` in regmove that depended on the host's
  linker, cselib hashing symbols and labels by content rather than address,
  and the garbage collector disabled in cc1.
- **Reproducible builds:** one host configuration and model, binaries
  independent of the folder they were built in, and checked generated tables.
- **The Lost Age's three Thumb rules**, below.

No other allocator, scheduler, literal-pool or alignment change is in the
July compiler. old_agbcc is pret's source and identity, unmodified. All
compiler source lives here, under the GPL, outside Alchemy's game tree.

## The Lost Age's rules

The Broken Seal uses `-O2 -mthumb -mthumb-interwork -nostdinc -fcall-used-r4`.
The Lost Age drops `-mthumb-interwork` (its returns are `pop {pc}`, The Broken
Seal's are `bx`) and adds `-mtune=arm9tdmi`. Its options are spelled as stock,
but their behaviour here is not, and a reader must not assume stock behaviour
from them. This source gates three rules found in no public GCC on those two
choices: `-mtune=arm9tdmi` here means a table line no public GCC has and split
constants, and plain `-mthumb` without interworking emits a call no public GCC
emits.

| Rule | Gated on | What the ROM shows |
| --- | --- | --- |
| Split constants (`thumb_split_const`) | `arm_ld_sched`, set by `-mtune=arm9tdmi` | 8,064 constants built inline from mov, shift and add, where every public GCC loads them from the literal pool |
| Calls through lr (`arm.md`) | No `-mthumb-interwork`, and no `-mcaller-super-interworking` | 2,495 indirect calls through a lone BL suffix to lr, where every public GCC calls a `_call_via_rX` stub |
| One load and store line (`arm.md`) | `arm_ld_sched`, set by `-mtune=arm9tdmi` | Loads that wait after a store; an approximation, described under [Scheduling](#scheduling) |

`arm_ld_sched` is only the bit that is set in this game. It is no reason to
split constants: GCC's own `arm.c` calls a constant load cheap under load
scheduling and synthesizes fewer constants there.

The first two were searched for in all 417 changes to `gcc/config/arm` from
1999-12 to 2002-12, on trunk and the 2.95, 3.0 and 3.1 branches: none builds
such a constant or makes such a call. Neither habit appears in The Broken
Seal. Measured on 2026-10-10, without both rules 875 of the 1,255 The Lost Age objects that match
with them still match.

## Which compiler built The Lost Age

The Lost Age (2002) was built by the same compiler family as The Broken Seal
(2001): GCC from before 6 September 2000, consistent with this 2000-07-31
snapshot, or a vendor build of it. It was not public GCC 3.0.4 or 3.1, and no
rewriting of the C can make it so. A panel of four independent analyses
settled this on 2026-10-26, from evidence that does not depend on Alchemy's
C:

- **Constant multiplies.** The ROM builds multiplies by 6, 10, 12, 20, 24, 28
  and 56 from shifts and adds, 862 times in 445 functions, and never uses
  `mul` with one of those constants. Commit r36354 (2000-09-12) redefined
  `COSTS_N_INSNS` in `rtl.h`, overriding `arm.c`'s cheaper multiply cost; from
  then on GCC emits `movs` and `muls` for them. Applying r36354 alone to this
  snapshot switches the habit off.
- **Stack addresses held in a register.** In 364 of The Lost Age's 959
  framed functions the code keeps an `sp`-relative address in a register and
  loads and stores through it (The Broken Seal: 228 of 690). Commit r36192
  (2000-09-06) changed `find_best_addr` in `cse.c` to fold such addresses into
  each access; applying it alone to this snapshot switches the habit off on C
  written for no particular compiler. In GCC 3.0.4 only a `volatile` pointer
  or `register asm` brings the habit back.
- **Block order.** GCC 3.0.4 reorders blocks by default at `-O2` and leaves
  code after the epilogue in 48% of functions; The Lost Age does so in 1 of
  7,657. This snapshot doesn't reorder blocks.
- **Instruction order.** The two compilers' Thumb scheduling cost models are
  identical. In the 265 functions where both emit exactly the ROM's
  instructions, compiled from The Broken Seal's unchanged C, this snapshot
  puts them in the ROM's order in 23 and GCC 3.0.4 in 1.
- **Blind C.** C written from the ROM listings without reading Alchemy's
  sources came closer under this snapshot in 9 of 17 functions, under GCC
  3.0.4 in 1.

A GCC 3.0.4 port with the first two rules (once Alchemy's `gcc3` branch,
now the `gcc-3.0.4-study` tag) reached 16.94% of The Lost Age's code against
the July compiler's 43.89%.

The two dating commits come from one author's cost rework within six days, so
they are one event rather than two. A vendor GCC 3.0 that reverted both, also
turned block reordering off and reproduced the July compiler's order
tie-breaks would fit; nothing points to one.

## Scheduling

The Lost Age is tuned for the ARM9: replaying the ROM's own instruction order
against GCC's scheduler with no C involved, the `arm9tdmi` model fits best
(5.26% of decisions differ, against 6.82% for `arm7tdmi` and 7.45% for
XScale); The Broken Seal fits `arm7tdmi` best. On top of the ARM9 model, the
ROM waits before a load that is not from `sp` or the literal pool whenever it
follows a store. No public GCC from 1997 to 2003 has that cost; its Thumb
units and `arm_adjust_cost` did not change in that time, apart from XScale
clauses that never apply to Thumb. Between this snapshot and 2000-09-05,
`haifa-sched.c` did not change either; the one dependence change, John
Wehle's of 2000-08-18 (a read from a label or the constant pool depends on no
store), changes no compile of The Lost Age's drafts, twins or matched
objects, so no snapshot of that window shows the habit.

One table line in `arm.md` approximates it. Under load-scheduled tuning, loads
and stores share a core line with a ready delay of 3 and an issue delay of 2,
in place of stock's two lines (a load's 2 1, a store's 1 1). The ready delay
takes a load's critical path from 2 to 3 and a store's from 1 to 3; the issue
delay gives back the slot after a load, which alone would cost 94 twins.
`haifa-sched.c` and `arm_adjust_cost` are stock; the line is not, and
`-mtune=arm9tdmi` selects it here through `arm_ld_sched`.

The line replaces `-mthumb-slow-loads`, a ranking in the scheduler and a store
rule in `arm_adjust_cost` that fitted more of the matched C. The Lost Age moved
to the line on 2026-11-01: the C of the 25 files it broke was redone, some of it
with tagged devices, and all twelve editions compare OK. A simpler compiler may
replace a more fitted one when the C it breaks is redone.

Evidence: 25 objects, 29 functions redone; 3 2 table: 645 to 678 of 701 twins (33 up, 0 down, about 25 independent), best of 225 tables on ROM replay.

## Why someone might have made these changes

**This section is reconstruction, not evidence.** The ROM shows what the
compiler did and says nothing about why. These are guesses at what a toolchain
engineer may have been thinking, written to help a reader remember the rules.
No measurement above depends on them, and they settle no compiler question.

Split constants: speed in cartridge ROM. A literal pool load is a
data read from slow cartridge ROM, and it breaks sequential instruction fetch.
A constant built inline from mov, shift and add stays in the instruction stream
at about the same size. The saving was not measured. It covers only constants
of the shape the rule can split; addresses still come from the pool. It also
does not apply to overlays, which run from RAM, though the habit is in them too.

Calls through lr: one branch less per indirect call. Thumb on this CPU has
no `blx`, so a call through a register goes to a `_call_via_rX` stub, which
branches again. Moving the target into `lr` and using a lone BL suffix takes
the same space and needs no stub. That suffix cannot change state, so the rule
goes with dropping `-mthumb-interwork`: perhaps one decision, that the game's
Thumb C stops paying for interworking. The game is not all Thumb. ARM routines
remain, reached through Thumb entries that switch state themselves (`bx pc`),
and the sound and flash libraries and some assembly still use stubs.

The load and store line: a write-buffer cost, and a hypothesis still under test.
GCC's own `arm_adjust_cost` already sorts a load after a store into hits (from
`sp`, the frame pointer or the literal pool) and misses, the others; a miss
would wait for pending stores. Under `arm7tdmi` tuning a store costs 2, so stock
GCC already charges a miss 2; stock `arm9tdmi` tuning costs a store 1, and the
line raises it. Four things do not fit:

- The Game Boy Advance's ARM7TDMI has no cache or write buffer, so this cost
  would describe some other CPU, as `-mtune=arm9tdmi` does.
- Treating the pool as a hit contradicts the reason given above for split
  constants, that pool loads are slow.
- The compiler sees only stores a load may read, where a real buffer would hold
  up a miss after any store.
- It explains the wait after a store, not the longer critical paths of a load
  (2 to 3) and a store (1 to 3).

## Licence

Preserve the upstream COPYING and COPYING.LIB notices and provide the
corresponding source when distributing compiler binaries. Building a
compiler is not proof of a matching ROM: Alchemy owns compiler selection and
verifies every linked byte. No game data belongs in this repository.
