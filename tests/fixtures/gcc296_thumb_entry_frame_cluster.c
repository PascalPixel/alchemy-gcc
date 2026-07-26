typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned char u8;

extern u8 *fixture_state_pointer;
extern s16 fixture_table[];

s32 fixture_lookup_pair (s16, s16);
void fixture_measure (s32, s32 *, s32 *, s32 *, s32 *);
s32 fixture_create (s32, s32, s32, s32, s32);
void fixture_attach (s32, void *, s32, s32);
s32 fixture_schedule (const void *, s32);

void
order_thumb_entry_frame_cluster (void)
{
    register u8 *base;
    s32 fourth;
    s32 third;
    s32 y;
    s32 x;
    s32 resource;
    s32 object;
    u16 *field;

    base = fixture_state_pointer;
    x = 8;
    y = 8;
    resource = fixture_lookup_pair (fixture_table[224], fixture_table[225])
        + 0x99b;
    fixture_measure (resource, &x, &y, &third, &fourth);
    x = (30 - third) >> 1;
    y = (10 - fourth) >> 1;
    object = fixture_create (x, y, third, fourth, 2);
    *(s32 *)(base + 0x230) = object;
    fixture_attach (resource, (void *)object, 0, 0);
    field = (u16 *)(base + 0x234);
    {
        register s32 ninety = 90;
        *field = ninety;
    }
    fixture_schedule ((void *)0x0801c3e9, 0xc80);
}

void
keep_unrelated_entry_frame_cluster (void)
{
    register u8 *base;
    s32 fourth;
    s32 third;
    s32 y;
    s32 x;
    s32 resource;
    s32 object;
    u16 *field;

    base = fixture_state_pointer;
    x = 7;
    y = 7;
    resource = fixture_lookup_pair (fixture_table[224], fixture_table[225])
        + 0x99b;
    fixture_measure (resource, &x, &y, &third, &fourth);
    x = (30 - third) >> 1;
    y = (10 - fourth) >> 1;
    object = fixture_create (x, y, third, fourth, 2);
    *(s32 *)(base + 0x230) = object;
    fixture_attach (resource, (void *)object, 0, 0);
    field = (u16 *)(base + 0x234);
    {
        register s32 ninety = 90;
        *field = ninety;
    }
    fixture_schedule ((void *)0x0801c3e9, 0xc80);
}
