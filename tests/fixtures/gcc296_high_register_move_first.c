typedef signed char s8;
typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;

extern void *fixture_registry;
extern void remove_fixture_entry(void *);

void scan_fixture_registry(s32 unused)
{
    s32 value_a;
    s32 value_b;
    s32 cached_link;
    s32 lower_x;
    s32 upper_x;
    s32 lower_y;
    s32 upper_y;
    s32 entry_x;
    s32 entry_y;
    s32 counter;
    void *bounds;
    void *entry;
    void *metadata;
    void **slot;

    bounds = *(void **)((u8 *)fixture_registry + 0x1e0);
    value_a = *(s32 *)((u8 *)bounds + 8);
    lower_x = value_a + 0xff600000;
    upper_x = value_a + 0x00a00000;
    value_b = *(s32 *)((u8 *)bounds + 0x10);
    lower_y = value_b + 0xff380000;
    upper_y = value_b + 0x00640000;
    slot = (void **)((u8 *)fixture_registry + 0x34);
    counter = 57;

    do {
        entry = *slot;
        if (entry != 0
            && ((entry_x = *(s32 *)((u8 *)entry + 8),
                 entry_y = *(u32 *)((u8 *)entry + 0x10),
                 entry_x != 0)
                || entry_y != 0)
            && (entry_x < lower_x || entry_x > upper_x
                || entry_y < lower_y || entry_y > upper_y)) {
            *(s8 *)((u8 *)entry + 0x54) = 1;
            cached_link = *(s32 *)((u8 *)entry + 0x50);
            metadata = (void *)cached_link;
            *(s8 *)((u8 *)metadata + 0x1d)
                = (u8)(*(s8 *)((u8 *)metadata + 0x1d) & ~1);
            remove_fixture_entry(entry);
            cached_link = 0;
            *slot = (void *)cached_link;
        }
        slot += 1;
        counter -= 1;
    } while (counter >= 0);
}
