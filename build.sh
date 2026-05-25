#!/usr/bin/env bash
# Build patched stock GCC 3.0 (arm-agb-elf target) for Camelot GBA matching
# decomp. The vendored gcc-3.0/ tree already has all 5 patches applied (see
# README). After this script lands cc1/xgcc/cpp0/tradcpp0 under build/gcc/,
# run ./install.sh path/to/goldensun-decomp to deploy.
#
# Pre-reqs (Debian/Ubuntu): bison flex texinfo build-essential
# Host: tested on Ubuntu 22.04 + gcc-11 via WSL2.

set -e

cd "$(dirname "$0")"
HERE="$PWD"
SRC="$HERE/gcc-3.0"
BUILD="$HERE/build"

if [ ! -d "$SRC" ]; then
  echo "error: $SRC not found"; exit 2
fi

NPROC="$(nproc 2>/dev/null || echo 4)"

# Conservative host flags: gcc-11 emits warnings that gcc-3.0 source treats as
# errors without these silencers. -no-pie is required because gcc-3.0's
# build infrastructure produces non-PIE executables.
#
# `-std=gnu17` / `-std=gnu++17` pin C/C++ standard. gcc-15+ defaults to C23,
# which makes implicit-int and K&R declarations hard errors (not warnings
# the `-Wno-*` flags above can silence). 2001-era source predates C99.
HOST_CFLAGS="-O2 -fno-pie -no-pie -Wno-narrowing -Wno-implicit-int -Wno-implicit-function-declaration -Wno-pointer-arith -Wno-int-conversion -Wno-format -Wno-error -std=gnu17 -Wno-incompatible-pointer-types"
HOST_CXXFLAGS="-O2 -fno-pie -no-pie -Wno-narrowing -Wno-error -std=gnu++17"
HOST_LDFLAGS="-no-pie"

# Some configure / install helpers lose +x via Windows-side editing / archive
# extraction. Restore them defensively.
find "$SRC" \( -name configure -o -name config.sub -o -name config.guess \
              -o -name install-sh -o -name mkinstalldirs -o -name move-if-change \
              -o -name missing -o -name ltconfig -o -name ltmain.sh \
              -o -name mkdep \) -exec chmod +x {} \;

# Pin timestamps on pre-shipped generated files. git clone does not preserve
# mtimes, so checkout order can leave generator inputs (configure.in, *.y,
# *.gperf) looking newer than their outputs. When that happens, make tries to
# re-run autoconf/bison/gperf against modern tools that no longer accept the
# 2001-era inputs:
#   - autoconf+m4 (1.4.19+) hits the 1024 recursion limit on old AC_* macros
#   - bison 3.x rejects 2.96/3.0-era *.y midrule typing
#   - gperf may not be installed
# Stamp the inputs OLD and the outputs NEW so make sees them as up-to-date.
find "$SRC" \( -name configure.in -o -name "*.y" -o -name "*.gperf" \
            -o -name acconfig.h \) -exec touch -t 200001010000 {} \;
find "$SRC" \( -name configure -o -name "c-parse.c" -o -name "c-parse.h" \
            -o -name "c-gperf.h" -o -name "cstamp-h.in" -o -name "config.in" \
            -o -name "tradcif.c" \) -exec touch {} \;

mkdir -p "$BUILD"
cd "$BUILD"

# --- Stage 1: top-level configure (produces dispatch Makefile only) ---
if [ ! -f Makefile ]; then
  echo "[1/4] top-level configure"
  CFLAGS="$HOST_CFLAGS" CXXFLAGS="$HOST_CXXFLAGS" LDFLAGS="$HOST_LDFLAGS" \
    "$SRC/configure" \
      --prefix="$BUILD/install" \
      --target=arm-agb-elf --with-cpu=arm7tdmi \
      --enable-multilib --enable-interwork --enable-languages=c \
      --without-headers --disable-shared --disable-threads \
      --disable-libstdc++-v3 --disable-nls --disable-win32-registry \
      || true   # top-level libiberty/gcc configure stub failures are expected
fi

# --- Stage 2: libiberty (configured + built manually) ---
if [ ! -f libiberty/libiberty.a ]; then
  echo "[2/4] libiberty"
  rm -rf libiberty && mkdir libiberty && cd libiberty
  CFLAGS="$HOST_CFLAGS" LDFLAGS="$HOST_LDFLAGS" \
    "$SRC/libiberty/configure" \
      --srcdir="$SRC/libiberty" \
      --prefix="$BUILD/install" \
      --build=x86_64-unknown-linux-gnu --host=x86_64-unknown-linux-gnu \
      --target=arm-agb-elf --disable-shared --disable-nls
  make -j"$NPROC"
  cd ..
fi

# --- Stage 3: gcc/ subdir configure ---
if [ ! -f gcc/Makefile ]; then
  echo "[3/4] gcc/ configure"
  mkdir -p gcc && cd gcc
  CFLAGS="$HOST_CFLAGS" CXXFLAGS="$HOST_CXXFLAGS" LDFLAGS="$HOST_LDFLAGS" \
    "$SRC/gcc/configure" \
      --srcdir="$SRC/gcc" \
      --prefix="$BUILD/install" \
      --build=x86_64-unknown-linux-gnu --host=x86_64-unknown-linux-gnu \
      --target=arm-agb-elf --with-cpu=arm7tdmi \
      --enable-multilib --enable-interwork --enable-languages=c \
      --without-headers --disable-shared --disable-threads --disable-nls \
      --with-gnu-as --with-gnu-ld
  cd ..
fi

# --- Stage 4: build cc1 + xgcc + cpp0 + tradcpp0 directly via gcc/ Makefile ---
# We deliberately bypass the top-level Makefile's `all-gcc` umbrella target
# because the top-level configure stub depends on `configure.in`, which we
# don't ship. Targeting the four host binaries directly from $BUILD/gcc/
# mirrors what build-296.sh does and avoids the libgcc tail (which would
# fail anyway without binutils/newlib).
if [ ! -x gcc/cc1 ] || [ ! -x gcc/xgcc ] || [ ! -x gcc/cpp0 ] || [ ! -x gcc/tradcpp0 ]; then
  echo "[4/4] make cc1 + xgcc + cpp0 + tradcpp0"
  cd gcc
  # Stamp config.status NEW so its --recheck rule (which re-runs configure's
  # compiler probe with hardcoded flags lacking -std=gnu17) does not fire
  # if $SRC/gcc/configure has a fresher mtime after a re-clone.
  [ -f config.status ] && touch config.status
  # Pass CFLAGS as make variables, NOT shell env-vars: gcc's Makefile.in
  # hard-codes its own CFLAGS = -O2 -g, and per make's precedence rules,
  # an internal Makefile assignment beats an inherited environment variable.
  # Only a command-line `make CFLAGS=...` override wins.
  make -j"$NPROC" \
    CFLAGS="$HOST_CFLAGS" CXXFLAGS="$HOST_CXXFLAGS" LDFLAGS="$HOST_LDFLAGS" \
    cc1 xgcc cpp0 tradcpp0
  cd ..
fi

echo
if [ -x gcc/cc1 ] && [ -x gcc/xgcc ] && [ -x gcc/cpp0 ] && [ -x gcc/tradcpp0 ]; then
  echo "BUILD OK"
  ls -la gcc/cc1 gcc/xgcc gcc/cpp0 gcc/tradcpp0
  echo
  echo "next: ./install.sh path/to/goldensun-decomp"
else
  echo "BUILD FAILED: artifacts missing in $BUILD/gcc/"
  ls -la gcc/ 2>&1 | head -20
  exit 1
fi
