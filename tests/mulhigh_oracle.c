#include <stdint.h>
#include <stdio.h>

static uint32_t
thumb_unsigned_high(uint32_t left, uint32_t right)
{
    uint32_t left_high = left >> 16;
    uint32_t left_low = (left << 16) >> 16;
    uint32_t right_high = right >> 16;
    uint32_t right_low = (right << 16) >> 16;
    uint32_t low_high = (left_low * right_low) >> 16;
    uint32_t cross = left_high * right_low + low_high;
    uint32_t other_cross = left_low * right_high + (uint16_t)cross;

    return left_high * right_high + (cross >> 16) + (other_cross >> 16);
}

static uint32_t
thumb_signed_high(uint32_t left, uint32_t right)
{
    uint32_t high = thumb_unsigned_high(left, right);

    high -= right & (uint32_t)((int32_t)left >> 31);
    high -= left & (uint32_t)((int32_t)right >> 31);
    return high;
}

static int
check_pair(uint32_t left, uint32_t right)
{
    uint32_t unsigned_expected = (uint32_t)(((uint64_t)left * right) >> 32);
    int64_t signed_product = (int64_t)(int32_t)left * (int64_t)(int32_t)right;
    uint32_t signed_expected = (uint32_t)((uint64_t)signed_product >> 32);

    if (thumb_unsigned_high(left, right) != unsigned_expected
        || thumb_signed_high(left, right) != signed_expected) {
        fprintf(stderr, "multiply-high mismatch for %08x * %08x\n", left, right);
        return 0;
    }
    return 1;
}

int
main(void)
{
    static const uint32_t boundaries[] = {
        0U, 1U, 2U, 0x7fffU, 0x8000U, 0xffffU, 0x10000U,
        0x7fffffffU, 0x80000000U, 0xfffffffeU, 0xffffffffU
    };
    uint32_t state = 0x6d2b79f5U;
    unsigned int left_index;
    unsigned int right_index;
    unsigned int iteration;

    for (left_index = 0; left_index < sizeof boundaries / sizeof boundaries[0];
         left_index++)
        for (right_index = 0;
             right_index < sizeof boundaries / sizeof boundaries[0];
             right_index++)
            if (!check_pair(boundaries[left_index], boundaries[right_index]))
                return 1;

    for (iteration = 0; iteration < 100000; iteration++) {
        uint32_t left;
        uint32_t right;

        state ^= state << 13;
        state ^= state >> 17;
        state ^= state << 5;
        left = state;
        state ^= state << 13;
        state ^= state >> 17;
        state ^= state << 5;
        right = state;
        if (!check_pair(left, right))
            return 1;
    }

    return 0;
}
