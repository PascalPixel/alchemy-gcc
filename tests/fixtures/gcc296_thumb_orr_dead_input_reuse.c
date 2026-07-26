typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

s32 fixture_curve(s32, s32);

extern volatile u16 fixture_sample_a;
extern volatile u16 fixture_sample_b;

void
order_thumb_orr_dead_input_reuse (void)
{
    u8 counter;
    u8 start;
    u32 result;

    if (*(volatile u8 *) 0x03001c98 != 0)
      {
        if (*(volatile u8 *) 0x03001cd4 != 0)
          {
            u16 sample = fixture_sample_a;
            result = (u32) sample | 0x80;
          }
        else
          {
            u16 sample = fixture_sample_b;
            result = (u32) sample | 0xc0;
          }
        *(volatile u16 *) 0x04000050 = (u16) result;
        *(volatile u8 *) 0x03001ac0 += 0xff;
        start = *(volatile u8 *) 0x03001ca8;
        *(volatile u16 *) 0x04000054 = start + fixture_curve (
            (*(volatile u8 *) 0x03001aec
                - *(volatile u8 *) 0x03001ca8)
              * *(volatile u8 *) 0x03001ac0,
            *(volatile u8 *) 0x03001c98);
        counter = *(volatile u8 *) 0x03001ac0;
        if (counter == 0)
          *(volatile u8 *) 0x03001c98 = counter;
      }
}

void
keep_nonvolatile_halfword_store (void)
{
    u8 counter;
    u8 start;
    u32 result;

    if (*(volatile u8 *) 0x03001c98 != 0)
      {
        if (*(volatile u8 *) 0x03001cd4 != 0)
          {
            u16 sample = fixture_sample_a;
            result = (u32) sample | 0x80;
          }
        else
          {
            u16 sample = fixture_sample_b;
            result = (u32) sample | 0xc0;
          }
        *(u16 *) 0x04000050 = (u16) result;
        *(volatile u8 *) 0x03001ac0 += 0xff;
        start = *(volatile u8 *) 0x03001ca8;
        *(volatile u16 *) 0x04000054 = start + fixture_curve (
            (*(volatile u8 *) 0x03001aec
                - *(volatile u8 *) 0x03001ca8)
              * *(volatile u8 *) 0x03001ac0,
            *(volatile u8 *) 0x03001c98);
        counter = *(volatile u8 *) 0x03001ac0;
        if (counter == 0)
          *(volatile u8 *) 0x03001c98 = counter;
      }
}
