#!/usr/bin/env bash
#
# Stage locally built compilers into the ignored runtime layout consumed by
# downstream projects.
#
#   ./stage.sh gcc296       build-296/gcc -> dist/ (the existing GS1 contract)
#   ./stage.sh gs2          build-gs2/gcc -> dist/gs2/
#   ./stage.sh all
#   ./stage.sh --check gs2  validate an existing stage without changing it

set -eu

cd "$(dirname "$0")"
ROOT="$PWD"
DIST_ROOT="${ALCHEMY_GCC_DIST_ROOT:-$ROOT/dist}"
BUILD_296="${ALCHEMY_GCC_BUILD_296:-$ROOT/build-296/gcc}"
BUILD_GS2="${ALCHEMY_GCC_BUILD_GS2:-$ROOT/build-gs2/gcc}"

usage() {
  echo "usage: $0 [--check] <gcc296|gs1|gs2|all>" >&2
  exit 2
}

validate_dist_root() {
  if [ -z "$DIST_ROOT" ] || [ "$DIST_ROOT" = "/" ] || [ "${DIST_ROOT##*/}" != "dist" ]; then
    echo "error: runtime stage root must be a directory named dist: $DIST_ROOT" >&2
    exit 1
  fi
}

require_artifact() {
  local path="$1"
  if [ ! -f "$path" ] || [ ! -x "$path" ]; then
    echo "error: required executable is missing: $path" >&2
    exit 1
  fi
}

copy_artifact() {
  local source="$1" destination="$2"
  require_artifact "$source"
  cp "$source" "$destination"
  chmod 755 "$destination"
}

check_artifact() {
  local source="$1" destination="$2"
  require_artifact "$source"
  require_artifact "$destination"
  if ! cmp -s "$source" "$destination"; then
    echo "error: staged executable differs from local build: $destination" >&2
    exit 1
  fi
}

stage_gs1() {
  require_artifact "$BUILD_296/xgcc"
  require_artifact "$BUILD_296/cc1"
  require_artifact "$BUILD_296/cpp"
  require_artifact "$BUILD_296/tradcpp"
  mkdir -p "$DIST_ROOT"
  copy_artifact "$BUILD_296/xgcc" "$DIST_ROOT/xgcc"
  copy_artifact "$BUILD_296/cc1" "$DIST_ROOT/cc1"
  copy_artifact "$BUILD_296/cpp" "$DIST_ROOT/cpp"
  copy_artifact "$BUILD_296/tradcpp" "$DIST_ROOT/tradcpp"
  echo "staged gcc296 runtime in $DIST_ROOT"
}

check_gs1() {
  check_artifact "$BUILD_296/xgcc" "$DIST_ROOT/xgcc"
  check_artifact "$BUILD_296/cc1" "$DIST_ROOT/cc1"
  check_artifact "$BUILD_296/cpp" "$DIST_ROOT/cpp"
  check_artifact "$BUILD_296/tradcpp" "$DIST_ROOT/tradcpp"
  echo "gcc296 runtime stage is current: $DIST_ROOT"
}

stage_gs2() {
  local temporary destination
  destination="$DIST_ROOT/gs2"
  mkdir -p "$DIST_ROOT"
  temporary="$(mktemp -d "$DIST_ROOT/.gs2-stage.XXXXXX")"
  trap 'rm -rf "$temporary"' EXIT

  copy_artifact "$BUILD_GS2/xgcc" "$temporary/xgcc"
  copy_artifact "$BUILD_GS2/cc1" "$temporary/cc1"
  # Preserve GCC 3.0's helper names: xgcc locates cpp0 and tradcpp0 by those
  # basenames under its -B runtime prefix.
  copy_artifact "$BUILD_GS2/cpp0" "$temporary/cpp0"
  copy_artifact "$BUILD_GS2/tradcpp0" "$temporary/tradcpp0"

  rm -rf "$destination"
  mv "$temporary" "$destination"
  trap - EXIT
  echo "staged GS2 runtime in $destination"
}

check_gs2() {
  local destination="$DIST_ROOT/gs2"
  check_artifact "$BUILD_GS2/xgcc" "$destination/xgcc"
  check_artifact "$BUILD_GS2/cc1" "$destination/cc1"
  check_artifact "$BUILD_GS2/cpp0" "$destination/cpp0"
  check_artifact "$BUILD_GS2/tradcpp0" "$destination/tradcpp0"
  if [ "$(find "$destination" -mindepth 1 -maxdepth 1 | wc -l | tr -d ' ')" -ne 4 ]; then
    echo "error: GS2 runtime stage must contain exactly four executables" >&2
    exit 1
  fi
  echo "GS2 runtime stage is current: $destination"
}

CHECK=0
if [ "${1:-}" = "--check" ]; then
  CHECK=1
  shift
fi

TARGET="${1:-}"
[ "$#" -eq 1 ] || usage
validate_dist_root

case "$TARGET" in
  gcc296|gs1)
    if [ "$CHECK" -eq 1 ]; then check_gs1; else stage_gs1; fi
    ;;
  gs2)
    if [ "$CHECK" -eq 1 ]; then check_gs2; else stage_gs2; fi
    ;;
  all)
    if [ "$CHECK" -eq 1 ]; then
      check_gs1
      check_gs2
    else
      stage_gs1
      stage_gs2
    fi
    ;;
  *) usage ;;
esac
