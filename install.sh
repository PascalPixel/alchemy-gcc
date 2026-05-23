#!/usr/bin/env bash
# Install the built gcc-3.0 binaries into a goldensun-decomp checkout.
# Mirrors pret/agbcc's install.sh shape.
#
# Usage:  ./install.sh ../goldensun-decomp
#
# After install, the decomp's Makefile (which defaults GCC3_DIR ?= tools/gcc3)
# can find cc1/xgcc/cpp0/tradcpp0 at <decomp>/tools/gcc3/.

set -e

cd "$(dirname "$0")"
HERE="$PWD"
BUILD="$HERE/build"

TARGET="${1:-}"
if [ -z "$TARGET" ]; then
  echo "usage: $0 path/to/goldensun-decomp"
  exit 2
fi
if [ ! -d "$TARGET" ]; then
  echo "error: target directory does not exist: $TARGET"
  exit 2
fi

for f in cc1 xgcc cpp0 tradcpp0; do
  if [ ! -x "$BUILD/gcc/$f" ]; then
    echo "error: $BUILD/gcc/$f missing. Run ./build.sh first."
    exit 2
  fi
done

DEST="$TARGET/tools/gcc3"
mkdir -p "$DEST"
cp "$BUILD/gcc/cc1"      "$DEST/"
cp "$BUILD/gcc/xgcc"     "$DEST/"
cp "$BUILD/gcc/cpp0"     "$DEST/"
cp "$BUILD/gcc/tradcpp0" "$DEST/"
chmod +x "$DEST/cc1" "$DEST/xgcc" "$DEST/cpp0" "$DEST/tradcpp0"

echo "installed gcc-3.0 binaries into $DEST"
ls -la "$DEST"
