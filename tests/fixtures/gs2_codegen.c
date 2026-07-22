typedef unsigned int u32;
typedef signed int s32;

u32 CallIndirect(u32 (*function)(u32), u32 value)
{
    return function(value);
}

u32 UnsignedDiv3(u32 value)
{
    return value / 3U;
}

s32 SignedDiv3(s32 value)
{
    return value / 3;
}

u32 UnsignedDiv16(u32 value)
{
    return value / 16U;
}

s32 SignedDiv16(s32 value)
{
    return value / 16;
}

u32 UnsignedDivVariable(u32 value, u32 divisor)
{
    return value / divisor;
}

s32 SignedDivVariable(s32 value, s32 divisor)
{
    return value / divisor;
}
