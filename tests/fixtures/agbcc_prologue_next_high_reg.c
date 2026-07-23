typedef signed int s32;

s32 prologue_after_r8(s32 value)
{
    register s32 held_r8 __asm__("r8") = value;
    return held_r8 + 1;
}

s32 prologue_after_r9(s32 left, s32 right)
{
    register s32 held_r8 __asm__("r8") = left;
    register s32 held_r9 __asm__("r9") = right;
    return held_r8 + held_r9;
}
