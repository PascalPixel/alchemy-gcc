# Host probes

Small C files written for this purpose (no game code) that reach the places
where a host could change what GCC 2.95.2 writes. `make -C arm probe`
compiles each with the admitted ARM profile and compares the assembler text
and the diagnostics, byte for byte, with the files beside it.

The expected files were written by a 32-bit Linux build of the pinned
archive with only the cast-as-lvalue fix (Debian bookworm i386, GCC 12.2,
default x87 arithmetic): the host this compiler was written for. `cc1` reads
the files directly, so they hold no comments or directives.

| Probe | Reaches |
|---|---|
| `cmpz.c` | Comparisons of a byte shifted left 24 with constants that are negative as a 32-bit `HOST_WIDE_INT` (`0x80000000`, `0xff000000`, `0xc3000000`). |
| `warn.c` | Five warnings formatted through the variadic `warning` functions with string and integer arguments; the file still compiles. |
| `error.c` | Five errors formatted through the variadic `error` functions; `cc1` exits 33 with exactly this text. |

Results on 2026-10-11: the 32-bit Linux reference, the x86-64 binary run
through Rosetta and the native arm64 binary agree on all three.
