typedef unsigned int u32;

extern u32 External(u32);

u32 NativeCodegen(u32 x, u32 *out)
{
    u32 mixed = (x ^ 0x89ABCDEFU) * 13U;
    out[0] = mixed;
    out[1] = mixed / 10U;
    return External(mixed);
}
