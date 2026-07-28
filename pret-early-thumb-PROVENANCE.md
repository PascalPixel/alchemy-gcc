# Experimental early public pret Thumb family

This tree is an experimental reconstruction from the approved public
pret/agbcc compiler sources. It is named for that demonstrable source and is
not assigned an authenticated vendor revision identity.

## Public source

- Repository: `https://github.com/pret/agbcc`
- Public commit: `da598c1d918402c42c0c0d7128ba14567f3175e9`
- License: see `pret-early-thumb/gcc/COPYING`
- Imported paths: `gcc_arm/` as `pret-early-thumb/gcc/`, plus the public
  top-level `config.if`, `config.sub`, `install.sh`, `include/`, and
  `libiberty/` build support

The public pret tree contains several preserved backend snapshots. Inspection
established that the coherent Thumb target is configured as
`thumb-elf`, selecting `thumb.c`, `thumb.md`, and `telf.h`; `telf.h` includes
`thumb.h`. The experimental tree selects the earliest mutually compatible
public snapshots:

- `gcc/version.c` from `gcc/version_000513.c`
- `gcc/config/arm/thumb.h` from `gcc/config/arm/thumb_000513.h`
- `gcc/config/arm/thumb.c` from `gcc/config/arm/thumb_010110a.c`
- `gcc/config/arm/thumb.md` from `gcc/config/arm/thumb_010110a.md`

The copied canonical files and their source snapshots are byte-identical:

| selected file and pret source | SHA-256 |
|---|---|
| `gcc/version.c`, `gcc/version_000513.c` | `d0bc856cf16c94bfe0e80fbb4b2f4acc6eca8f81e271f53662dfaca5d7dbdae5` |
| `gcc/config/arm/thumb.h`, `gcc/config/arm/thumb_000513.h` | `77c25ea75ebb11d0fc9d4256c19814c537aa6a32f06c3623941afa63abbf210b` |
| `gcc/config/arm/thumb.c`, `gcc/config/arm/thumb_010110a.c` | `faf65ab44cdf18ff97d378e3cd59952e1c884253b0b291eaafc7c0deb28d511b` |
| `gcc/config/arm/thumb.md`, `gcc/config/arm/thumb_010110a.md` | `e85a861f9051fbbed94ac435b19c51f5fc8389e0d7ecef0763baa578dbfd4b2e` |

The historical word “Cygnus” is present in the imported pret material itself,
including `config.sub`'s `CYGNUS LOCAL` markers and source copyright/authorship
comments. It is not evidence for a particular numbered compiler revision and
is therefore deliberately absent from the family identifier.

The header and machine description consistently predate the later long-call
feature. The nearest public C and machine-description snapshots are dated
after the header, however, and the selected version source still emits the
`2.9-arm-000512` banner. Public git history imported all snapshots together and
cannot establish a finer revision history. Consequently this is only an
**early-public-snapshot experiment**. The `000513` strings above are original
pret filenames and are not asserted to identify the resulting compiler.

`pret-early-thumb-SHA256SUMS` records every incorporated file after snapshot
selection. Regenerate it from the repository root with:

```sh
find pret-early-thumb -type f -print0 | LC_ALL=C sort -z |
  xargs -0 shasum -a 256 > pret-early-thumb-SHA256SUMS
```
