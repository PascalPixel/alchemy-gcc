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

compile_gcc296_fixture() {
  local fixture="$1" output="$2"
  shift 2
  "$ROOT/build-296/gcc/xgcc" -B"$ROOT/build-296/gcc/" \
    -O2 -mthumb -mthumb-interwork -mcpu=arm7tdmi \
    -fno-builtin -nostdinc -ffreestanding "$@" \
    -S "$ROOT/tests/fixtures/$fixture" -o "$output"
}

extract_function() {
  local input="$1" function_name="$2" output="$3"
  awk -v label="$function_name:" -v function_name="$function_name" \
    '$0 == label { copy = 1 }
     copy { print }
     copy && $0 ~ ("^[[:space:]]*\\.size[[:space:]]+" function_name ",") { exit }' \
    "$input" > "$output"
}

require_count() {
  local expected="$1" pattern="$2" file="$3" actual
  actual="$(grep -Ec "$pattern" "$file" || true)"
  if [ "$actual" -ne "$expected" ]; then
    echo "error: expected $expected matches for '$pattern' in $file, found $actual" >&2
    exit 1
  fi
}

require_sequence() {
  local file="$1" next_line=1 pattern line
  shift
  for pattern in "$@"; do
    line="$(awk -v start="$next_line" -v pattern="$pattern" \
      'NR >= start && $0 ~ pattern { print NR; exit }' "$file")"
    if [ -z "$line" ]; then
      echo "error: expected '$pattern' after line $((next_line - 1)) in $file" >&2
      exit 1
    fi
    next_line=$((line + 1))
  done
}

for build_dir in build build-gs2; do
  for binary in cc1 xgcc cpp0 tradcpp0; do
    [ -x "$build_dir/gcc/$binary" ] || {
      echo "error: $build_dir/gcc/$binary missing; run ./build.sh gcc3 and ./build.sh gs2 first" >&2
      exit 2
    }
  done
done

for binary in cc1 xgcc cpp tradcpp; do
  [ -x "build-296/gcc/$binary" ] || {
    echo "error: build-296/gcc/$binary missing; run ./build.sh gcc296 first" >&2
    exit 2
  }
done

[ -x "agbcc/gcc/old_agbcc" ] || {
  echo "error: agbcc/gcc/old_agbcc missing; run ./build.sh agbcc first" >&2
  exit 2
}

"$ROOT/agbcc/gcc/old_agbcc" \
  "$ROOT/tests/fixtures/agbcc_literal_before_shift.c" \
  -mthumb-interwork -O2 -fno-builtin -ffreestanding \
  -o "$TMP_DIR/agbcc-literal-stock.s"
"$ROOT/agbcc/gcc/old_agbcc" \
  "$ROOT/tests/fixtures/agbcc_literal_before_shift.c" \
  -mthumb-interwork -O2 -fno-builtin -ffreestanding \
  -mliteral-before-shift -o "$TMP_DIR/agbcc-literal-opt-in.s"
require_sequence "$TMP_DIR/agbcc-literal-stock.s" \
  'lsl[[:space:]]+r0, r0, #2' \
  'ldr[[:space:]]+r1,'
require_sequence "$TMP_DIR/agbcc-literal-opt-in.s" \
  'ldr[[:space:]]+r1,' \
  'lsl[[:space:]]+r0, r0, #2'

"$ROOT/agbcc/gcc/old_agbcc" \
  "$ROOT/tests/fixtures/agbcc_commutative_copy_constant.c" \
  -mthumb-interwork -O1 -fno-builtin -ffreestanding \
  -o "$TMP_DIR/agbcc-commutative-stock.s"
"$ROOT/agbcc/gcc/old_agbcc" \
  "$ROOT/tests/fixtures/agbcc_commutative_copy_constant.c" \
  -mthumb-interwork -O1 -fno-builtin -ffreestanding \
  -mcommutative-copy-constant -o "$TMP_DIR/agbcc-commutative-opt-in.s"
require_sequence "$TMP_DIR/agbcc-commutative-stock.s" \
  'mov[[:space:]]+r[0-7], #64' \
  'add[[:space:]]+r0, r1, #0' \
  'and[[:space:]]+r0, r0, r[0-7]'
require_sequence "$TMP_DIR/agbcc-commutative-opt-in.s" \
  'mov[[:space:]]+r([0-7]), #64' \
  'add[[:space:]]+r0, r[0-7], #0' \
  'and[[:space:]]+r0, r0, r1'

"$ROOT/agbcc/gcc/old_agbcc" \
  "$ROOT/tests/fixtures/agbcc_prologue_next_high_reg.c" \
  -mthumb-interwork -O2 -fno-builtin -ffreestanding \
  -o "$TMP_DIR/agbcc-prologue-stock.s"
"$ROOT/agbcc/gcc/old_agbcc" \
  "$ROOT/tests/fixtures/agbcc_prologue_next_high_reg.c" \
  -mthumb-interwork -O2 -fno-builtin -ffreestanding \
  -mprologue-next-high-reg -o "$TMP_DIR/agbcc-prologue-opt-in.s"
require_count 1 'mov[[:space:]]+r[0-7], r9' "$TMP_DIR/agbcc-prologue-stock.s"
require_count 1 'mov[[:space:]]+r9, r[0-7]' "$TMP_DIR/agbcc-prologue-stock.s"
require_count 0 'mov[[:space:]]+r[0-7], sl' "$TMP_DIR/agbcc-prologue-stock.s"
require_count 0 'mov[[:space:]]+sl, r[0-7]' "$TMP_DIR/agbcc-prologue-stock.s"
require_count 2 'mov[[:space:]]+r[0-7], r9' "$TMP_DIR/agbcc-prologue-opt-in.s"
require_count 2 'mov[[:space:]]+r9, r[0-7]' "$TMP_DIR/agbcc-prologue-opt-in.s"
require_count 1 'mov[[:space:]]+r[0-7], sl' "$TMP_DIR/agbcc-prologue-opt-in.s"
require_count 1 'mov[[:space:]]+sl, r[0-7]' "$TMP_DIR/agbcc-prologue-opt-in.s"

"$ROOT/agbcc/gcc/old_agbcc" \
  "$ROOT/tests/fixtures/agbcc_compare_only_and_tst.c" \
  -mthumb-interwork -O2 -fno-builtin -ffreestanding \
  -o "$TMP_DIR/agbcc-tst-stock.s"
"$ROOT/agbcc/gcc/old_agbcc" \
  "$ROOT/tests/fixtures/agbcc_compare_only_and_tst.c" \
  -mthumb-interwork -O2 -fno-builtin -ffreestanding \
  -mcompare-only-and-tst -o "$TMP_DIR/agbcc-tst-opt-in.s"
"$ROOT/agbcc/gcc/old_agbcc" \
  "$ROOT/tests/fixtures/agbcc_compare_only_and_tst.c" \
  -mthumb-interwork -O2 -fno-builtin -ffreestanding \
  -mno-compare-only-and-tst -o "$TMP_DIR/agbcc-tst-opt-out.s"
cmp "$TMP_DIR/agbcc-tst-stock.s" "$TMP_DIR/agbcc-tst-opt-out.s"
extract_function "$TMP_DIR/agbcc-tst-stock.s" walk_test_nodes \
  "$TMP_DIR/agbcc-tst-stock-walk.s"
extract_function "$TMP_DIR/agbcc-tst-opt-in.s" walk_test_nodes \
  "$TMP_DIR/agbcc-tst-opt-in-walk.s"
extract_function "$TMP_DIR/agbcc-tst-opt-in.s" retain_masked_value \
  "$TMP_DIR/agbcc-tst-opt-in-live.s"
extract_function "$TMP_DIR/agbcc-tst-opt-in.s" keep_relational_compare \
  "$TMP_DIR/agbcc-tst-opt-in-relational.s"
require_count 0 'tst[[:space:]]' "$TMP_DIR/agbcc-tst-stock-walk.s"
require_count 1 'tst[[:space:]]+r0, r1' "$TMP_DIR/agbcc-tst-opt-in-walk.s"
require_sequence "$TMP_DIR/agbcc-tst-stock-walk.s" \
  'and[[:space:]]+r0, r0, r1' \
  'cmp[[:space:]]+r0, #0'
require_sequence "$TMP_DIR/agbcc-tst-opt-in-live.s" \
  'and[[:space:]]+r0, r0, r1' \
  'cmp[[:space:]]+r0, #0'
require_sequence "$TMP_DIR/agbcc-tst-opt-in-relational.s" \
  'and[[:space:]]+r0, r0, r1' \
  'cmp[[:space:]]+r0, #0' \
  'blt[[:space:]]'

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

"$ROOT/build-296/gcc/xgcc" -B"$ROOT/build-296/gcc/" \
  -O2 -mthumb -mthumb-interwork -mcpu=arm7tdmi -fno-builtin -nostdinc \
  -ffreestanding -fcall-used-r4 -S \
  "$ROOT/tests/fixtures/grouped_dma_store.c" -o "$TMP_DIR/grouped-stock.s"
"$ROOT/build-296/gcc/xgcc" -B"$ROOT/build-296/gcc/" \
  -O2 -mthumb -mthumb-interwork -mcpu=arm7tdmi -fno-builtin -nostdinc \
  -ffreestanding -fcall-used-r4 -mgrouped-dma-store -S \
  "$ROOT/tests/fixtures/grouped_dma_store.c" -o "$TMP_DIR/grouped-opt-in.s"
require_count 0 'stmia[[:space:]].*[{]r0, r1, r2[}]' "$TMP_DIR/grouped-stock.s"
require_count 3 'stmia[[:space:]].*[{]r0, r1, r2[}]' "$TMP_DIR/grouped-opt-in.s"
require_count 3 'sub[[:space:]]+r3, r3, #12' "$TMP_DIR/grouped-opt-in.s"
require_sequence "$TMP_DIR/grouped-stock.s" \
  'mov[[:space:]]+r2, sp' \
  'str[[:space:]]+r2, [[]r3[]]' \
  'ldr[[:space:]]+r2, .*4' \
  'str[[:space:]]+r5, [[]r3, #4[]]' \
  'str[[:space:]]+r2, [[]r3, #8[]]'
require_sequence "$TMP_DIR/grouped-opt-in.s" \
  'mov[[:space:]]+r1, r5' \
  'ldr[[:space:]]+r3,' \
  'ldr[[:space:]]+r2,' \
  'stmia[[:space:]].*[{]r0, r1, r2[}]'
require_sequence "$TMP_DIR/grouped-stock.s" \
  'mov[[:space:]]+r1, #200' \
  'str[[:space:]]+r2, [[]r0, #4[]]' \
  'str[[:space:]]+r3, [[]r0, #8[]]' \
  'lsl[[:space:]]+r1, r1, #4' \
  'ldr[[:space:]]+r0,'
require_sequence "$TMP_DIR/grouped-opt-in.s" \
  'mov[[:space:]]+r1, #200' \
  'lsl[[:space:]]+r1, r1, #4' \
  'ldr[[:space:]]+r0,'

compile_gcc296_fixture gcc296_legacy_peephole_numbering.c \
  "$TMP_DIR/legacy-peephole-numbering.s" -fcall-used-r4
compile_gcc296_fixture gcc296_legacy_peephole_numbering.c \
  "$TMP_DIR/legacy-peephole-disabled.s" -fcall-used-r4 -fno-peephole
require_sequence "$TMP_DIR/legacy-peephole-numbering.s" \
  'ldrb[[:space:]]+r1, [[]r0[]]' \
  'mov[[:space:]]+r3, #128' \
  'lsl[[:space:]]+r3, r3, #1'
require_sequence "$TMP_DIR/legacy-peephole-disabled.s" \
  'mov[[:space:]]+r3, #128' \
  'ldrb[[:space:]]+r1, [[]r0[]]' \
  'lsl[[:space:]]+r3, r3, #1'
if cmp -s "$TMP_DIR/legacy-peephole-numbering.s" \
  "$TMP_DIR/legacy-peephole-disabled.s"; then
  echo "error: -fno-peephole did not disable the legacy ordering peephole" >&2
  exit 1
fi

compile_gcc296_fixture gcc296_grouped_dma_extended.c \
  "$TMP_DIR/grouped-extended-stock.s" -fcall-used-r4
compile_gcc296_fixture gcc296_grouped_dma_extended.c \
  "$TMP_DIR/grouped-extended-opt-in.s" -fcall-used-r4 \
  -mgrouped-dma-store
compile_gcc296_fixture gcc296_grouped_dma_extended.c \
  "$TMP_DIR/grouped-extended-opt-out.s" -fcall-used-r4 \
  -mno-grouped-dma-store
compile_gcc296_fixture gcc296_grouped_dma_extended.c \
  "$TMP_DIR/grouped-extended-saved-r4.s" -mgrouped-dma-store
cmp "$TMP_DIR/grouped-extended-stock.s" \
  "$TMP_DIR/grouped-extended-opt-out.s"

for function in grouped_literal_descriptor grouped_stack_descriptor \
  grouped_four_word_records grouped_four_word_records_short \
  grouped_four_word_records_nonzero_lane \
  grouped_four_word_records_live_scratch; do
  extract_function "$TMP_DIR/grouped-extended-opt-in.s" "$function" \
    "$TMP_DIR/grouped-extended-opt-in-$function.s"
done
extract_function "$TMP_DIR/grouped-extended-stock.s" \
  grouped_four_word_records "$TMP_DIR/grouped-extended-stock-four.s"
extract_function "$TMP_DIR/grouped-extended-saved-r4.s" \
  grouped_four_word_records "$TMP_DIR/grouped-extended-saved-r4-four.s"

require_sequence \
  "$TMP_DIR/grouped-extended-opt-in-grouped_literal_descriptor.s" \
  'ldr[[:space:]]+r0,' \
  'ldr[[:space:]]+r1,' \
  'ldr[[:space:]]+r2,' \
  'stmia[[:space:]]+r3!, [{]r0, r1, r2[}]'
require_sequence \
  "$TMP_DIR/grouped-extended-opt-in-grouped_stack_descriptor.s" \
  'ldr[[:space:]]+r4,' \
  'mov[[:space:]]+r0, sp'
require_count 12 'str[[:space:]]' \
  "$TMP_DIR/grouped-extended-stock-four.s"
require_count 0 'str[[:space:]]' \
  "$TMP_DIR/grouped-extended-opt-in-grouped_four_word_records.s"
require_count 3 \
  'stmia[[:space:]]+r0!, [{]r1, r2, r3, r4[}]' \
  "$TMP_DIR/grouped-extended-opt-in-grouped_four_word_records.s"
require_sequence \
  "$TMP_DIR/grouped-extended-opt-in-grouped_four_word_records.s" \
  'mov[[:space:]]+r0, r3' \
  'mov[[:space:]]+r3, #0' \
  'mov[[:space:]]+r4, #0' \
  'lsl[[:space:]]+r1, r1, #9' \
  'stmia[[:space:]]+r0!, [{]r1, r2, r3, r4[}]'
require_count 0 \
  'stmia[[:space:]]+r0!, [{]r1, r2, r3, r4[}]' \
  "$TMP_DIR/grouped-extended-opt-in-grouped_four_word_records_short.s"
require_count 0 \
  'stmia[[:space:]]+r0!, [{]r1, r2, r3, r4[}]' \
  "$TMP_DIR/grouped-extended-opt-in-grouped_four_word_records_nonzero_lane.s"
require_count 0 \
  'stmia[[:space:]]+r0!, [{]r1, r2, r3, r4[}]' \
  "$TMP_DIR/grouped-extended-opt-in-grouped_four_word_records_live_scratch.s"
require_count 0 \
  'stmia[[:space:]]+r0!, [{]r1, r2, r3, r4[}]' \
  "$TMP_DIR/grouped-extended-saved-r4-four.s"
require_count 12 'str[[:space:]]' \
  "$TMP_DIR/grouped-extended-saved-r4-four.s"

compile_gcc296_fixture gcc296_thumb_bit_tests.c "$TMP_DIR/thumb-bits-stock.s"
compile_gcc296_fixture gcc296_thumb_bit_tests.c "$TMP_DIR/thumb-bits-preserve.s" \
  -mpreserve-single-bit-test
compile_gcc296_fixture gcc296_thumb_bit_tests.c "$TMP_DIR/thumb-bits-entry.s" \
  -mpreserve-single-bit-test -mentry-low-register-order
compile_gcc296_fixture gcc296_thumb_bit_tests.c "$TMP_DIR/thumb-bits-all.s" \
  -mpreserve-single-bit-test -mentry-low-register-order -mthumb-and-sets-cc
compile_gcc296_fixture gcc296_thumb_bit_tests.c "$TMP_DIR/thumb-bits-opt-out.s" \
  -mno-preserve-single-bit-test -mno-entry-low-register-order \
  -mno-thumb-and-sets-cc
cmp "$TMP_DIR/thumb-bits-stock.s" "$TMP_DIR/thumb-bits-opt-out.s"
extract_function "$TMP_DIR/thumb-bits-preserve.s" test_fixture_low_bit \
  "$TMP_DIR/thumb-bits-preserve-low.s"
require_sequence "$TMP_DIR/thumb-bits-preserve-low.s" \
  'mov[[:space:]]+r3, #1' \
  'tst[[:space:]]+r3, r0'
require_sequence "$TMP_DIR/thumb-bits-stock.s" \
  'ldrb[[:space:]]+r3, [[]r5[]]' \
  'lsr[[:space:]]+r3, r3, #7' \
  'cmp[[:space:]]+r3, #0'
require_sequence "$TMP_DIR/thumb-bits-preserve.s" \
  'ldrb[[:space:]]+r2, [[]r5[]]' \
  'mov[[:space:]]+r3, #128' \
  'tst[[:space:]]+r3, r2'
require_sequence "$TMP_DIR/thumb-bits-entry.s" \
  'ldrb[[:space:]]+r1, [[]r5[]]' \
  'mov[[:space:]]+r0, #128' \
  'tst[[:space:]]+r0, r1'
require_sequence "$TMP_DIR/thumb-bits-entry.s" \
  'and[[:space:]]+r0, r0, r3' \
  'cmp[[:space:]]+r0, #0' \
  'beq[[:space:]]'
require_sequence "$TMP_DIR/thumb-bits-all.s" \
  'and[[:space:]]+r0, r0, r3' \
  'beq[[:space:]]'
require_count 1 'cmp[[:space:]]+r0, #0' "$TMP_DIR/thumb-bits-all.s"
awk '/beq[[:space:]]+\\.L3/ { copy = 1 } copy' \
  "$TMP_DIR/thumb-bits-preserve.s" > "$TMP_DIR/thumb-bits-preserve-tail.s"
awk '/beq[[:space:]]+\\.L3/ { copy = 1 } copy' \
  "$TMP_DIR/thumb-bits-entry.s" > "$TMP_DIR/thumb-bits-entry-tail.s"
cmp "$TMP_DIR/thumb-bits-preserve-tail.s" "$TMP_DIR/thumb-bits-entry-tail.s"

compile_gcc296_fixture gcc296_early_frame_allocation.c \
  "$TMP_DIR/early-frame-stock.s" -fcall-used-r4
compile_gcc296_fixture gcc296_early_frame_allocation.c \
  "$TMP_DIR/early-frame-opt-in.s" -fcall-used-r4 -mearly-frame-allocation
compile_gcc296_fixture gcc296_early_frame_allocation.c \
  "$TMP_DIR/early-frame-opt-out.s" -fcall-used-r4 -mno-early-frame-allocation
cmp "$TMP_DIR/early-frame-stock.s" "$TMP_DIR/early-frame-opt-out.s"
require_sequence "$TMP_DIR/early-frame-stock.s" \
  'ldr[[:space:]]+r3, [[]r3[]]' \
  'ldr[[:space:]]+r5, [[]r3, #16[]]' \
  'sub[[:space:]]+sp, sp, #12'
require_sequence "$TMP_DIR/early-frame-opt-in.s" \
  'ldr[[:space:]]+r3, [[]r3[]]' \
  'sub[[:space:]]+sp, sp, #12' \
  'ldr[[:space:]]+r5, [[]r3, #16[]]'

compile_gcc296_fixture gcc296_high_register_move_first.c \
  "$TMP_DIR/high-move-stock.s" -fcall-used-r4
compile_gcc296_fixture gcc296_high_register_move_first.c \
  "$TMP_DIR/high-move-opt-in.s" -fcall-used-r4 -mhigh-register-move-first
compile_gcc296_fixture gcc296_high_register_move_first.c \
  "$TMP_DIR/high-move-opt-out.s" -fcall-used-r4 -mno-high-register-move-first
cmp "$TMP_DIR/high-move-stock.s" "$TMP_DIR/high-move-opt-out.s"
require_sequence "$TMP_DIR/high-move-stock.s" \
  'mov[[:space:]]+r6, #57' \
  'mov[[:space:]]+fp, r1'
require_sequence "$TMP_DIR/high-move-opt-in.s" \
  'mov[[:space:]]+fp, r1' \
  'mov[[:space:]]+r6, #57'

compile_gcc296_fixture gcc296_call_arg0_move_first.c \
  "$TMP_DIR/call-arg0-stock.s" -fcall-used-r4
compile_gcc296_fixture gcc296_call_arg0_move_first.c \
  "$TMP_DIR/call-arg0-opt-in.s" -fcall-used-r4 -mcall-arg0-move-first
compile_gcc296_fixture gcc296_call_arg0_move_first.c \
  "$TMP_DIR/call-arg0-opt-out.s" -fcall-used-r4 -mno-call-arg0-move-first
cmp "$TMP_DIR/call-arg0-stock.s" "$TMP_DIR/call-arg0-opt-out.s"
extract_function "$TMP_DIR/call-arg0-stock.s" \
  order_independent_call_arguments "$TMP_DIR/call-arg0-stock-order.s"
extract_function "$TMP_DIR/call-arg0-opt-in.s" \
  order_independent_call_arguments "$TMP_DIR/call-arg0-opt-in-order.s"
extract_function "$TMP_DIR/call-arg0-stock.s" \
  keep_dependent_call_arguments "$TMP_DIR/call-arg0-stock-dependent.s"
extract_function "$TMP_DIR/call-arg0-opt-in.s" \
  keep_dependent_call_arguments "$TMP_DIR/call-arg0-opt-in-dependent.s"
require_sequence "$TMP_DIR/call-arg0-stock-order.s" \
  'mov[[:space:]]+r1, #15' \
  'mov[[:space:]]+r0, r5' \
  'bl[[:space:]]+consume_result'
require_sequence "$TMP_DIR/call-arg0-opt-in-order.s" \
  'mov[[:space:]]+r0, r5' \
  'mov[[:space:]]+r1, #15' \
  'bl[[:space:]]+consume_result'
cmp "$TMP_DIR/call-arg0-stock-dependent.s" \
  "$TMP_DIR/call-arg0-opt-in-dependent.s"
require_sequence "$TMP_DIR/call-arg0-opt-in-dependent.s" \
  'mov[[:space:]]+r0, r1' \
  'mov[[:space:]]+r1, #15' \
  'bl[[:space:]]+consume_pair'

compile_gcc296_fixture gcc296_thumb_entry_literal_first.c \
  "$TMP_DIR/entry-literal-stock.s" -fcall-used-r4 -fno-schedule-insns2
compile_gcc296_fixture gcc296_thumb_entry_literal_first.c \
  "$TMP_DIR/entry-literal-opt-in.s" -fcall-used-r4 -fno-schedule-insns2 \
  -mthumb-entry-literal-first
compile_gcc296_fixture gcc296_thumb_entry_literal_first.c \
  "$TMP_DIR/entry-literal-opt-out.s" -fcall-used-r4 -fno-schedule-insns2 \
  -mno-thumb-entry-literal-first
cmp "$TMP_DIR/entry-literal-stock.s" "$TMP_DIR/entry-literal-opt-out.s"
require_sequence "$TMP_DIR/entry-literal-stock.s" \
  'mov[[:space:]]+r6, r0' \
  'ldr[[:space:]]+r4,'
require_sequence "$TMP_DIR/entry-literal-opt-in.s" \
  'ldr[[:space:]]+r4,' \
  'mov[[:space:]]+r6, r0'

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
