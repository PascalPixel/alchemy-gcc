typedef signed int s32;
typedef unsigned char u8;

void *make_result(s32, s32, s32, s32);
void consume_result(void *, s32);
void consume_pair(s32, s32);

void *order_independent_call_arguments(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    u8 *result = make_result(arg3, arg0, arg1, arg2);

    if (result != 0) {
        u8 *object = *(u8 **)(result + 0x50);
        s32 flags;
        s32 mask = 13;

        flags = object[9];
        mask = -mask;
        mask &= flags;
        mask |= 4;
        object[9] = mask;
        result[0x55] = 0;
        result[0x59] = 8;
        consume_result(result, 0);
        consume_result(result, 15);
        result[0x23] = (result[0x23] & 0xfe) | 2;
    }
    return result;
}

void keep_dependent_call_arguments(s32 unused, s32 value)
{
    consume_pair(value, 15);
}
