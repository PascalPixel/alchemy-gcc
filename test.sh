#!/usr/bin/env bash

set -eu

cd "$(dirname "$0")"
ROOT="$PWD"
TMP_DIR="$(mktemp -d "${TMPDIR:-/tmp}/alchemy-gcc-test.XXXXXX")"
trap 'rm -rf "$TMP_DIR"' EXIT

"$ROOT/tests/stage_runtime.sh"

COMMON_FLAGS="-O2 -mthumb -mthumb-interwork -mcpu=arm7tdmi -fno-builtin -nostdinc -ffreestanding -fcall-used-r4 -ffixed-r7"

compile_fixture() {
  local build_dir="$1" fixture="$2" output="$3"
  shift 3
  "$ROOT/$build_dir/gcc/xgcc" -B"$ROOT/$build_dir/gcc/" \
    $COMMON_FLAGS "$@" -S "$ROOT/tests/fixtures/$fixture" -o "$output"
}

require_count() {
  local expected="$1" pattern="$2" file="$3" actual
  actual="$(grep -Ec "$pattern" "$file" || true)"
  if [ "$actual" -ne "$expected" ]; then
    echo "error: expected $expected matches for '$pattern' in $file, found $actual" >&2
    exit 1
  fi
}

for build_dir in build build-gs2; do
  for binary in cc1 xgcc cpp0 tradcpp0; do
    [ -x "$build_dir/gcc/$binary" ] || {
      echo "error: $build_dir/gcc/$binary missing; run ./build.sh gcc3 and ./build.sh gs2 first" >&2
      exit 2
    }
  done
done

if [ "$(uname -s)" = Darwin ] && [ "$(uname -m)" = arm64 ]; then
  for build_dir in build build-gs2; do
    file "$build_dir/gcc/cc1" "$build_dir/gcc/xgcc" \
      "$build_dir/gcc/cpp0" "$build_dir/gcc/tradcpp0" | grep -qv 'arm64' && {
        echo "error: $build_dir contains a non-arm64 host executable" >&2
        exit 1
      }
  done
fi

compile_fixture build native_codegen.c "$TMP_DIR/native_codegen.s"
cmp tests/expected/native_codegen.s "$TMP_DIR/native_codegen.s"

compile_fixture build native_float_codegen.c "$TMP_DIR/native_float_codegen.s"
grep -Eq '\.word[[:space:]]+0x3fc00000' "$TMP_DIR/native_float_codegen.s"
grep -Eq '\.long[[:space:]]+0x400a0000, 0x0' "$TMP_DIR/native_float_codegen.s"

compile_fixture build gs2_codegen.c "$TMP_DIR/stock.s"
require_count 1 'bl[[:space:]]+_call_via_' "$TMP_DIR/stock.s"
require_count 4 'bl[[:space:]]+__(u)?divsi3' "$TMP_DIR/stock.s"
require_count 0 '\.short[[:space:]]+0xf800' "$TMP_DIR/stock.s"

compile_fixture build-gs2 gs2_codegen.c "$TMP_DIR/gs2.s"
compile_fixture build gs2_codegen.c "$TMP_DIR/gs2_opt_in.s" -mcamelot-gs2
compile_fixture build-gs2 gs2_codegen.c "$TMP_DIR/gs2_opt_out.s" -mno-camelot-gs2
compile_fixture build gs2_codegen.c "$TMP_DIR/stock_arm.s" -marm
compile_fixture build-gs2 gs2_codegen.c "$TMP_DIR/gs2_arm.s" -marm
cmp "$TMP_DIR/gs2.s" "$TMP_DIR/gs2_opt_in.s"
cmp "$TMP_DIR/stock.s" "$TMP_DIR/gs2_opt_out.s"
cmp "$TMP_DIR/stock_arm.s" "$TMP_DIR/gs2_arm.s"
require_count 0 '_call_via_' "$TMP_DIR/gs2.s"
require_count 1 'bl[[:space:]]+__udivsi3' "$TMP_DIR/gs2.s"
require_count 1 'bl[[:space:]]+__divsi3' "$TMP_DIR/gs2.s"
require_count 1 '\.short[[:space:]]+0xf800' "$TMP_DIR/gs2.s"
grep -Eq 'mov[[:space:]]+lr, r([0-9]|1[0-3])' "$TMP_DIR/gs2.s"
grep -Eq '\.word[[:space:]]+-1431655765' "$TMP_DIR/gs2.s"
grep -Eq '\.word[[:space:]]+1431655766' "$TMP_DIR/gs2.s"

mul_count="$(grep -Ec '^[[:space:]]*mul[[:space:]]' "$TMP_DIR/gs2.s" || true)"
if [ "$mul_count" -lt 8 ]; then
  echo "error: GS2 constant division emitted only $mul_count limb multiplies" >&2
  exit 1
fi

if command -v arm-none-eabi-as >/dev/null 2>&1; then
  arm-none-eabi-as -mcpu=arm7tdmi -mthumb-interwork "$TMP_DIR/gs2.s" -o "$TMP_DIR/gs2.o"
fi

if command -v cc >/dev/null 2>&1; then
  cc -std=c99 -Wall -Wextra -Werror tests/mulhigh_oracle.c -o "$TMP_DIR/mulhigh_oracle"
  "$TMP_DIR/mulhigh_oracle"
fi

echo "native gcc3 and GS2 codegen regressions passed"
