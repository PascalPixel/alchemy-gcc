#!/usr/bin/env bash
# Build patched gcc-2.96 20000731 (arm-elf target) for Camelot GBA matching
# decomp. The vendored gcc-2.96/ tree already has all 6 patches applied (see
# README). After this script lands cc1/xgcc/cpp/tradcpp under build-296/gcc/,
# run ./install-296.sh path/to/goldensun-decomp to deploy.
#
# Pre-reqs (Debian/Ubuntu): bison flex texinfo build-essential
# Host: tested on Ubuntu 22.04 + gcc-11 via WSL2.
#
# 2.96 deltas vs 3.0 build.sh:
#   - target = arm-elf (not arm-agb-elf); tarpman's CE setup matches this
#   - artifacts named cc1/xgcc/cpp/tradcpp (no `0` suffix)
#   - we build `make cc1` directly, not `make all-gcc` (fixinc has a
#     static-vs-extern collision with modern gcc; we don't need fixinc
#     for a freestanding cross-compile)

set -e

cd "$(dirname "$0")"
HERE="$PWD"
SRC="$HERE/gcc-2.96"
BUILD="$HERE/build-296"

if [ ! -d "$SRC" ]; then
  echo "error: $SRC not found"; exit 2
fi

NPROC="$(nproc 2>/dev/null || echo 4)"

HOST_CFLAGS="-O2 -fno-pie -no-pie -Wno-narrowing -Wno-implicit-int -Wno-implicit-function-declaration -Wno-pointer-arith -Wno-int-conversion -Wno-format -Wno-error -fcommon"
HOST_CXXFLAGS="-O2 -fno-pie -no-pie -Wno-narrowing -Wno-error"
HOST_LDFLAGS="-no-pie"

# `-fcommon` required for gcc-10+ host (default flipped to -fno-common in 10).
# Some 2.96 tentative definitions need the old merge behavior.
# (Not needed for gcc-3.0; gcc-3.0 builds clean without it.)

# Some configure / install helpers lose +x via Windows-side editing / archive
# extraction. Restore them defensively.
find "$SRC" \( -name configure -o -name config.sub -o -name config.guess \
              -o -name install-sh -o -name mkinstalldirs -o -name move-if-change \
              -o -name missing -o -name ltconfig -o -name ltmain.sh \
              -o -name mkdep \) -exec chmod +x {} \;

mkdir -p "$BUILD"
cd "$BUILD"

# --- Stage 1: top-level configure (produces dispatch Makefile only) ---
if [ ! -f Makefile ]; then
  echo "[1/4] top-level configure"
  CFLAGS="$HOST_CFLAGS" CXXFLAGS="$HOST_CXXFLAGS" LDFLAGS="$HOST_LDFLAGS" \
    "$SRC/configure" \
      --prefix="$BUILD/install" \
      --target=arm-elf --with-cpu=arm7tdmi \
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
      --target=arm-elf --disable-shared --disable-nls
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
      --target=arm-elf --with-cpu=arm7tdmi \
      --enable-multilib --enable-interwork --enable-languages=c \
      --without-headers --disable-shared --disable-threads --disable-nls \
      --with-gnu-as --with-gnu-ld
  cd ..
fi

# --- Stage 4: build cc1 directly (skip make all-gcc; fixinc collides) ---
if [ ! -x gcc/cc1 ] || [ ! -x gcc/xgcc ] || [ ! -x gcc/cpp ] || [ ! -x gcc/tradcpp ]; then
  echo "[4/4] make cc1 + xgcc + cpp + tradcpp"
  cd gcc
  CFLAGS="$HOST_CFLAGS" CXXFLAGS="$HOST_CXXFLAGS" LDFLAGS="$HOST_LDFLAGS" \
    make -j"$NPROC" cc1 xgcc cpp tradcpp
  cd ..
fi

echo
if [ -x gcc/cc1 ] && [ -x gcc/xgcc ] && [ -x gcc/cpp ] && [ -x gcc/tradcpp ]; then
  echo "BUILD OK"
  ls -la gcc/cc1 gcc/xgcc gcc/cpp gcc/tradcpp
  echo
  echo "next: ./install-296.sh path/to/goldensun-decomp"
else
  echo "BUILD FAILED: artifacts missing in $BUILD/gcc/"
  ls -la gcc/ 2>&1 | head -20
  exit 1
fi
