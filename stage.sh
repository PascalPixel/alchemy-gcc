#!/usr/bin/env bash
#
# Stage locally built compilers into the ignored runtime layout consumed by
# downstream projects.
#
#   ./stage.sh gcc296       build-296/gcc -> dist/ (the existing GS1 contract)
#   ./stage.sh gs2          build-gs2/gcc -> dist/gs2/
#   ./stage.sh agbcc        agbcc/gcc/old_agbcc -> dist/agbcc/
#   ./stage.sh all
#   ./stage.sh --check gs2  validate an existing stage without changing it

set -eu

cd "$(dirname "$0")"
ROOT="$PWD"
DIST_ROOT="${ALCHEMY_GCC_DIST_ROOT:-$ROOT/dist}"
BUILD_296="${ALCHEMY_GCC_BUILD_296:-$ROOT/build-296/gcc}"
BUILD_GS2="${ALCHEMY_GCC_BUILD_GS2:-$ROOT/build-gs2/gcc}"
BUILD_AGBCC="${ALCHEMY_GCC_BUILD_AGBCC:-$ROOT/agbcc/gcc}"
BUILD_PRET_EARLY_THUMB="${ALCHEMY_GCC_BUILD_PRET_EARLY_THUMB:-$ROOT/build-pret-early-thumb/gcc}"
BUILD_2951="${ALCHEMY_GCC_BUILD_2951:-$ROOT/build-2951/gcc}"

usage() {
  echo "usage: $0 [--check] <gcc296|gs1|gs2|agbcc|pretearlythumb|gcc2951|all>" >&2
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

stage_agbcc() {
  local temporary destination
  destination="$DIST_ROOT/agbcc"
  mkdir -p "$DIST_ROOT"
  temporary="$(mktemp -d "$DIST_ROOT/.agbcc-stage.XXXXXX")"
  trap 'rm -rf "$temporary"' EXIT
  copy_artifact "$BUILD_AGBCC/old_agbcc" "$temporary/old_agbcc"
  rm -rf "$destination"
  mv "$temporary" "$destination"
  trap - EXIT
  echo "staged old_agbcc runtime in $destination"
}

check_agbcc() {
  local destination="$DIST_ROOT/agbcc"
  check_artifact "$BUILD_AGBCC/old_agbcc" "$destination/old_agbcc"
  if [ "$(find "$destination" -mindepth 1 -maxdepth 1 | wc -l | tr -d ' ')" -ne 1 ]; then
    echo "error: old_agbcc runtime stage must contain exactly one executable" >&2
    exit 1
  fi
  echo "old_agbcc runtime stage is current: $destination"
}

# The two comparison compilers are single-artifact bundles: downstream tooling
# only ever invokes their cc1 directly and drives preprocessing through the
# gcc296 runtime, so neither needs its own xgcc/cpp. build.sh has always built
# them; without these they could not be staged, and a decomp checkout that
# validates dist/pret-early-thumb/cc1 and dist/gcc2951/cc1 fails its own
# self-test with the bundle simply absent.
stage_single() {
  local name="$1" source="$2" destination="$3"
  local temporary
  mkdir -p "$DIST_ROOT"
  temporary="$(mktemp -d "$DIST_ROOT/.${name}-stage.XXXXXX")"
  trap 'rm -rf "$temporary"' EXIT
  copy_artifact "$source" "$temporary/cc1"
  rm -rf "$destination"
  mv "$temporary" "$destination"
  trap - EXIT
  echo "staged $name runtime in $destination"
}

check_single() {
  local name="$1" source="$2" destination="$3"
  check_artifact "$source" "$destination/cc1"
  if [ "$(find "$destination" -mindepth 1 -maxdepth 1 | wc -l | tr -d ' ')" -ne 1 ]; then
    echo "error: $name runtime stage must contain exactly one executable" >&2
    exit 1
  fi
  echo "$name runtime stage is current: $destination"
}

stage_pret_early_thumb() {
  stage_single pret-early-thumb "$BUILD_PRET_EARLY_THUMB/cc1" "$DIST_ROOT/pret-early-thumb"
}

check_pret_early_thumb() {
  check_single pret-early-thumb "$BUILD_PRET_EARLY_THUMB/cc1" "$DIST_ROOT/pret-early-thumb"
}

stage_2951() {
  stage_single gcc2951 "$BUILD_2951/cc1" "$DIST_ROOT/gcc2951"
}

check_2951() {
  check_single gcc2951 "$BUILD_2951/cc1" "$DIST_ROOT/gcc2951"
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
  agbcc)
    if [ "$CHECK" -eq 1 ]; then check_agbcc; else stage_agbcc; fi
    ;;
  pretearlythumb)
    if [ "$CHECK" -eq 1 ]; then check_pret_early_thumb; else stage_pret_early_thumb; fi
    ;;
  gcc2951)
    if [ "$CHECK" -eq 1 ]; then check_2951; else stage_2951; fi
    ;;
  all)
    if [ "$CHECK" -eq 1 ]; then
      check_gs1
      check_gs2
      check_agbcc
    else
      stage_gs1
      stage_gs2
      stage_agbcc
    fi
    # The comparison compilers stay optional in "all": they are probe-only, and
    # a tree built with ./build.sh gcc296 alone must still stage cleanly. Named
    # explicitly they are strict, exactly like every other token.
    for optional in pret-early-thumb:"$BUILD_PRET_EARLY_THUMB" gcc2951:"$BUILD_2951"; do
      name="${optional%%:*}"
      built="${optional#*:}"
      if [ ! -f "$built/cc1" ]; then
        echo "skipping $name: $built/cc1 not built"
        continue
      fi
      case "$name" in
        pret-early-thumb)
          if [ "$CHECK" -eq 1 ]; then check_pret_early_thumb; else stage_pret_early_thumb; fi ;;
        gcc2951)
          if [ "$CHECK" -eq 1 ]; then check_2951; else stage_2951; fi ;;
      esac
    done
    ;;
  *) usage ;;
esac
