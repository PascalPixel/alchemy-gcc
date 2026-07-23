typedef unsigned char u8;
typedef signed int s32;

s32 literal_before_shift(s32 index)
{
    return *(s32 *)(0x080fba48 + ((s32)index << 2));
}
