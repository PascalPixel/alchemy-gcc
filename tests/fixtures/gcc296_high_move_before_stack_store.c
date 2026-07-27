typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct TestDmaTransfer {
    const void *source;
    void *destination;
    u32 control;
};

struct TestEffectState {
    u8 data[0x1f80];
    u16 timer;
    u16 enabled;
};

extern u8 *test_display;

extern void *test_allocate(s32 kind, s32 size);
extern s32 test_setup(s32 kind, s32 source, s32 destination, s32 enabled);
extern void test_merge(u16 *first, u16 *second, u16 *output, s32 count);
extern s32 test_schedule(void (*callback)(void), s32 period);
extern void test_callback(void);
extern void test_consume_pointer(void *pointer);

void order_high_move_before_stack_store(s32 first_kind, s32 second_kind)
{
    struct TestEffectState *effect;
    u8 *display;
    u32 zero;
    u16 enabled;
    u32 *source;
    void *destination;
    struct TestDmaTransfer *dma;

    destination = test_allocate(30, 0x1f88);
    effect = destination;
    display = test_display;

    source = &zero;
    enabled = 0;
    *source = enabled;
    dma = (struct TestDmaTransfer *)0x040000d4;
    dma->source = source;
    dma->destination = destination;
    dma->control = 0x850007e2;

    test_setup(first_kind, (s32)display, (s32)effect, 1);
    test_setup(second_kind, (s32)display, (s32)effect + 0xa80, 1);
    test_merge((u16 *)((u8 *)effect + 0xa80),
               (u16 *)effect,
               (u16 *)((u8 *)effect + 0x1500),
               12);
    test_setup((s32)effect, 0, (s32)display + 0xe00, 1);

    effect->timer = 0x78;
    effect->enabled = enabled;
    test_schedule(test_callback, 0xc80);
}

void keep_nonstack_zero_store(u32 *destination)
{
    *destination = 0;
    test_consume_pointer(destination);
}
