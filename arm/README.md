# Stock ARM compiler

This builds the C frontend and ARM backend of GNU GCC 2.95.2 (version banner
`2.95.2 19991024 (release)`). It is the admitted ARM compiler; the GCC 2.96 Thumb
compiler and The Lost Age's two Thumb options are unchanged.

Run `make -C arm`. The output is `arm/build/gcc/cc1`. The recipe downloads
the official GNU source archive and checks its SHA-256 before extraction.
It builds only host tools, without target runtime libraries or headers.
It builds a native executable with the system C compiler (`CC`, default
`cc`): on Apple Silicon an arm64 program that needs no Rosetta. The
historical i686 descriptor selects GCC's host integer model (a 32-bit
`HOST_WIDE_INT`), not the host or target CPU, and every host compiles under
the same model: signed `char`, wrapping arithmetic, no type-based aliasing,
no fused multiply-add. On i386 pass `CC='cc -msse2 -mfpmath=sse'`.

`host.patch` has one headed section per change, each saying where it is
needed and why it cannot change output:

1. Assign the underlying `arm_prgmode` variable instead of its cast macro;
   current host compilers no longer accept cast expressions as lvalues.
2. Match Darwin's `const int sys_nerr` declaration in its system headers.
3. Declare the generator table `insn_gen_function` unprototyped, as
   `genoutput.c` defines it. Apple's arm64 calling convention passes
   variadic arguments on the stack, and the generators are not variadic.
4. Compile-time asserts of the host model in `xm-i386.h`.
5. Copy a floating constant's two ints out of, and into, its `CONST_DOUBLE`
   one operand slot at a time. The stock code block-copies them from
   `&CONST_DOUBLE_LOW`; a slot is as wide as a host pointer, so on a 64-bit
   host the second int came from unused, uninitialised memory. On a 32-bit
   host the loop copies the same bytes as before.

None changes target instruction selection, allocation or scheduling.
`make -C arm probe` compares small probes with the output of a 32-bit Linux
build (`probe/README.md`).

The host compiler and the host model come from `../config/host.mk`, the file
the GCC 2.96 and old_agbcc recipes read. The shipped parser is never
regenerated: its files are touched after extraction and the make step names
`false` as its Bison.

Measured on 2026-10-11 with Alchemy 4e1f8feede, on four builds of this
recipe (macOS arm64 and macOS x86-64 with Apple clang; Debian 12 aarch64
and i386 with GCC 12.2, glibc 2.36), beside the earlier x86-64 binary and a
32-bit Linux build of the archive with only fixes 1 and 2:

- The 30 compiles of Alchemy's ARM route in its twelve editions give the
  same assembler text from every one of them, and with the macOS arm64
  binary all twelve ROMs match.
- Every C file of both games compiled with the ARM profile (1,875 files,
  11,500 file/edition pairs, 4,133 distinct preprocessed units), on the
  three 64-bit builds and both comparison binaries: 4,014 give the same
  assembler text from all of them, 107 fail in all of them with the same
  status and diagnostics, and 12 differ.
- Those 12 are the only units with floating constants (`dou.c` and
  `runpa_jo.c` of The Broken Seal in six editions; neither is on the ARM
  route). Before fix 5, every 64-bit build of this source, the earlier
  x86-64 binary included, wrote uninitialised memory into such a constant
  and could write a different value on the next run; the 32-bit builds
  wrote the right one. With fix 5 the probe `const.c` (double, float and
  long long constants) gives the 32-bit build's assembler text on every
  build listed in the top-level README.
The source retains GNU's license notices. Distributing a compiler binary
requires providing its corresponding source and these host changes.

The 2026-10-10 study found that the separately consumed agbcc ARM compiler
identifies itself as `2.9-arm-000512` and lacks the general zero-cost
anti/output-dependence scheduling rule already present in upstream GCC
2.95.2 and agscc's GCC 2.96. Adding that rule to an isolated agbcc prototype
identified the scheduling difference; the prototype is not used here.

Stock GCC 2.95.2, with one setting for all game ARM C,
`-O2 -mthumb-interwork -fomit-frame-pointer -fcall-used-r4`, matches
`UiText_DrawGlyphArm` in all six TBS editions and `Tile_BuildMetatiles`
in all twelve editions. The glyph candidate removes several source devices;
it contains no inline assembly, fixed-register variables or asm barriers.
The current compiler-shaped game ARM corpus consists of these two routines.
The earlier seven-routine comparison also included five routines subsequently
proved handwritten; those are not evidence about compiler output.

The expanded release/history study independently rebuilt untouched GNU source
in a pinned 32-bit environment. GCC 2.95, 2.95.1, 2.95.2 and 2.95.2.1 all
match those same 18 edition cases. This recipe pins 2.95.2 as a practical
representative of that family, not as a uniquely identified original release.
A January 4, 2000 CSE change on the 2.95 maintenance branch loses the six
glyph matches; fresh builds reproduce both sides of that boundary.

Pascal approved this route on 2026-10-10. The Alchemy bundle uses it in place
of agbcc_arm. The native build is a host-adapted build with
a stock target/optimizer; the documented host edits above remain part
of its corresponding source.

GCC 2.96 already contains the scheduler rule, but its ARM backend is not a
drop-in replacement for these sources: it changes both routines with stock
ARM flags, including with `-mno-apcs-frame`. This does not rule out different
source forms matching 2.96, nor establish Camelot's exact historical version.
Alchemy's full linked ROM comparisons and Pascal's compiler decision remain
separate gates; object matches alone do not admit a new compiler.
