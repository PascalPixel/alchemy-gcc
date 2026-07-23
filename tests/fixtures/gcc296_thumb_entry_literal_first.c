typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;
typedef signed int s32;

extern u16 fixture_queue_count;
extern u16 fixture_interrupt_enable;

void enqueue_fixture_pair(void *first, void *second)
{
    register u16 *count = &fixture_queue_count;
    u32 first_value = (u32)first;
    u32 second_value = (u32)second;
    u32 saved_enable;
    u32 index;

    second = &fixture_interrupt_enable;
    saved_enable = *(volatile u16 *)second;
    *(volatile u16 *)second = (u16)(u32)second;
    index = *count;
    if ((s32)index <= 31) {
        volatile u32 *entry = (u32 *)((u8 *)count + 4 + index * 12);
        *entry++ = second_value;
        *count = index + 1;
        *entry++ = first_value;
        *entry = 0xa0000;
    }
    *(volatile u16 *)second = saved_enable;
}
