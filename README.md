# 🌋 Alchemy GCC

The compilers that build [Alchemy](https://github.com/PascalPixel/alchemy), the byte-for-byte reconstruction of the Golden Sun games for the Game Boy Advance.

| Compiler | Source | Builds |
| --- | --- | --- |
| Alchemy GCC | The GCC 2.96 snapshot of 2000-07-31, with host fixes and three Thumb rules | Both games' Thumb C and libgcc |
| GCC 2.95.2 | The GNU release, unmodified in `gcc-2.95.2/` | Both games' ARM C |
| old_agbcc | [pret/agbcc](https://github.com/pret/agbcc), unmodified in `agbcc/` | The sound and save code |

`binutils-2.10/` holds GNU's binutils 2.10 release, unmodified, from which Alchemy builds its assembler. These are reconstruction choices, not Camelot's or Nintendo's own tools: matching shows that they produce the games' code, not that they are the exact compilers Camelot ran.

## Build

Alchemy builds these the first time you run its `make`. To build them on their own:

```sh
git clone --recurse-submodules https://github.com/PascalPixel/alchemy-gcc
cd alchemy-gcc
make
```

It needs a C compiler, Make and patch, and no network.

## Licence

Preserve the upstream COPYING and COPYING.LIB notices and provide the corresponding source when distributing compiler binaries. No game data belongs in this repository.
