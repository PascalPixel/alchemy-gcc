#!/usr/bin/env bash
# Install the built gcc-2.96 binaries into a goldensun-decomp checkout.
# Parallel to install.sh (which installs the gcc-3.0 binaries to tools/gcc3/).
#
# Usage:  ./install-296.sh ../goldensun-decomp
#
# After install, the decomp's Makefile (GCC296_DIR ?= tools/gcc296) finds
# cc1/xgcc/cpp/tradcpp at <decomp>/tools/gcc296/.

set -e

cd "$(dirname "$0")"
HERE="$PWD"
BUILD="$HERE/build-296"

TARGET="${1:-}"
if [ -z "$TARGET" ]; then
  echo "usage: $0 path/to/goldensun-decomp"
  exit 2
fi
if [ ! -d "$TARGET" ]; then
  echo "error: target directory does not exist: $TARGET"
  exit 2
fi

for f in cc1 xgcc cpp tradcpp; do
  if [ ! -x "$BUILD/gcc/$f" ]; then
    echo "error: $BUILD/gcc/$f missing. Run ./build-296.sh first."
    exit 2
  fi
done

DEST="$TARGET/tools/gcc296"
mkdir -p "$DEST"
cp "$BUILD/gcc/cc1"      "$DEST/"
cp "$BUILD/gcc/xgcc"     "$DEST/"
cp "$BUILD/gcc/cpp"      "$DEST/"
cp "$BUILD/gcc/tradcpp"  "$DEST/"
chmod +x "$DEST/cc1" "$DEST/xgcc" "$DEST/cpp" "$DEST/tradcpp"

echo "installed gcc-2.96 binaries into $DEST"
ls -la "$DEST"
