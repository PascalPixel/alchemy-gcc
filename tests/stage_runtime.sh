#!/usr/bin/env bash

set -eu

cd "$(dirname "$0")/.."
ROOT="$PWD"
TEMPORARY="$(mktemp -d "${TMPDIR:-/tmp}/alchemy-gcc-stage-test.XXXXXX")"
trap 'rm -rf "$TEMPORARY"' EXIT

BUILD_296="$TEMPORARY/build-296/gcc"
BUILD_GS2="$TEMPORARY/build-gs2/gcc"
DIST="$TEMPORARY/dist"
mkdir -p "$BUILD_296" "$BUILD_GS2"

fixture() {
  local path="$1" content="$2"
  printf '#!/bin/sh\n# %s\n' "$content" > "$path"
  chmod 755 "$path"
}

fixture "$BUILD_296/xgcc" gs1-xgcc
fixture "$BUILD_296/cc1" gs1-cc1
fixture "$BUILD_296/cpp" gs1-cpp
fixture "$BUILD_296/tradcpp" gs1-tradcpp
fixture "$BUILD_GS2/xgcc" gs2-xgcc
fixture "$BUILD_GS2/cc1" gs2-cc1
fixture "$BUILD_GS2/cpp0" gs2-cpp0
fixture "$BUILD_GS2/tradcpp0" gs2-tradcpp0

run_stage() {
  ALCHEMY_GCC_DIST_ROOT="$DIST" \
  ALCHEMY_GCC_BUILD_296="$BUILD_296" \
  ALCHEMY_GCC_BUILD_GS2="$BUILD_GS2" \
    "$ROOT/stage.sh" "$@"
}

run_stage all
cmp "$BUILD_296/xgcc" "$DIST/xgcc"
cmp "$BUILD_296/cc1" "$DIST/cc1"
cmp "$BUILD_296/cpp" "$DIST/cpp"
cmp "$BUILD_296/tradcpp" "$DIST/tradcpp"
cmp "$BUILD_GS2/xgcc" "$DIST/gs2/xgcc"
cmp "$BUILD_GS2/cc1" "$DIST/gs2/cc1"
cmp "$BUILD_GS2/cpp0" "$DIST/gs2/cpp0"
cmp "$BUILD_GS2/tradcpp0" "$DIST/gs2/tradcpp0"
[ ! -e "$DIST/gs2/cpp" ]
[ ! -e "$DIST/gs2/tradcpp" ]
run_stage --check all

# Restaging GS2 is a complete replacement, so stale runtime files cannot
# silently survive.
fixture "$DIST/gs2/stale" stale
run_stage gs2
[ ! -e "$DIST/gs2/stale" ]

# A missing build artifact must fail before replacing a valid existing stage.
mv "$BUILD_GS2/cpp0" "$BUILD_GS2/cpp0.missing"
if run_stage gs2 >/dev/null 2>&1; then
  echo "error: staging accepted a missing GS2 preprocessor" >&2
  exit 1
fi
cmp "$BUILD_GS2/cpp0.missing" "$DIST/gs2/cpp0"

# The replacement operation is restricted to an explicitly named dist root.
if ALCHEMY_GCC_DIST_ROOT="$TEMPORARY" \
  ALCHEMY_GCC_BUILD_GS2="$BUILD_GS2" \
  "$ROOT/stage.sh" gs2 >/dev/null 2>&1; then
  echo "error: staging accepted a broad runtime root" >&2
  exit 1
fi

echo "runtime staging regressions passed"
