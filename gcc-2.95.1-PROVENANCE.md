# Stock GCC 2.95.1 Thumb compiler

This family comes from the official GNU GCC 2.95.1 release.

- Release: GCC 2.95.1, 1999-08-19
- Archive: `gcc-2.95.1.tar.gz`
- Official archive SHA-256:
  `2cb193385782e9a6901d86e7fe6266f2f36b60e9ddf620625e6565e4dc6a307c`
- Public source: `https://gcc.gnu.org/pub/gcc/releases/gcc-2.95.1/`
- License: GNU GPL; see `gcc-2.95.1/gcc/COPYING`

Only the C compiler, libiberty, shared headers, and required root build helpers
are incorporated. `gcc-2.95.1-SHA256SUMS` records every incorporated file.

Stock GCC 2.95.1 does not offer a Thumb/ELF configuration. Its Thumb backend
is the separate `thumb-coff` target. Alchemy treats it as a historical
experimental comparison family: its emitted Thumb assembly is accepted by the
GNU ARM ELF assembler, but it must not be described as a Thumb/ELF compiler.

The target compiler sources are unmodified. One host-only compatibility change
is applied in `libiberty/strerror.c`: modern macOS declares `sys_nerr` and
`sys_errlist` as const, so the legacy redeclarations are made const-compatible.
This does not participate in target code generation. Native Apple Silicon
exposes unresolved 32-bit-host assumptions in this release, so the macOS build
produces x86_64 host tools and runs them through Rosetta.

Regenerate the incorporated-file manifest from the repository root with:

```sh
find gcc-2.95.1 -type f -print0 | LC_ALL=C sort -z |
  xargs -0 shasum -a 256 > gcc-2.95.1-SHA256SUMS
```
