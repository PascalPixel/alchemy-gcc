typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

struct fixture_selection {
    u8 padding0[8];
    s32 index;
    u8 padding_c[4];
    s32 selected;
    u8 padding14[4];
    s32 tile;
};

struct fixture_state {
    u8 padding0[0x20];
    u8 *object;
    u8 padding24[8];
    void *owner;
    u8 padding30[0x198];
    u16 tiles[1];
};

extern struct fixture_state *fixture_state_pointer;
extern u8 fixture_graphics[];

void prepare_fixture_owner(void *);
void set_fixture_mode(s32);
void draw_fixture_graphic(s32, void *, s32, s32);
void draw_fixture_row(u8 *, s32, s32, s32, s32, u32);
void consume_fixture_pair(s32, s32);

s32
order_low_constant_before_high_move (
    s32 unused0, s32 unused1, struct fixture_selection *selection)
{
    struct fixture_state *state = fixture_state_pointer;
    s32 row;
    s32 column;
    s32 height;
    s32 tile;
    u16 test;
    s32 condition;
    s32 graphic;

    selection->tile = selection->index * 5 + selection->selected;
    prepare_fixture_owner (state->owner);
    set_fixture_mode (1);
    tile = state->tiles[selection->tile];
    test = tile;
    condition = test;
    if (condition != 0)
      {
        graphic = 0x1ff;
        graphic &= tile;
        graphic += (s32) fixture_graphics;
        draw_fixture_graphic (graphic, state->owner, 0, 0);
      }

    height = 1;
    row = 0;
    column = 1;
    do
      {
        if (row == selection->selected)
          draw_fixture_row (state->object, 1, column, 14, height, 14);
        else
          draw_fixture_row (state->object, 1, column, 14, height, 15);
        row++;
        column += 2;
      }
    while (row <= 4);

    set_fixture_mode (1);
    return 1;
}

void
keep_unrelated_low_constants (s32 value)
{
    consume_fixture_pair (value, 1);
}

struct bounded_child {
    u8 padding0[5];
    s8 value;
    u8 padding6[16];
    u8 flags : 8;
};

struct bounded_record {
    u8 padding0[39];
    u8 child_count;
    struct bounded_child *first_child;
    struct bounded_child *children[1];
};

struct bounded_record *lookup_bounded_record (void *, s32);

struct bounded_record *
order_bounded_initializer_run (void *object, s32 value)
{
    u32 first_mask;
    void *saved_object;
    s32 saved_value;
    s32 object_index;
    struct bounded_record *record;

    first_mask = (u8) ((u32) object | ~(u32) object);
    saved_object = (void *) ((u32) object
        + (((u32) object | ~(u32) object) + 1));
    saved_value = value + (((u32) object | ~(u32) object) + 1);
    object_index = 0;
    while ((record = lookup_bounded_record (saved_object, object_index)) != 0)
      {
        struct bounded_child *child;
        struct bounded_child **children;
        s32 child_count;
        s32 zero;
        u32 inner_mask;
        s32 remaining;

        child = record->first_child;
        children = record->children;
        child->flags |= first_mask;
        child_count = record->child_count;
        child->value = saved_value;
        if (child_count > 1)
          {
            zero = 0;
            inner_mask = 0xff;
            remaining = child_count - 1;
            do
              {
                child = *children++;
                child->value = zero;
                child->flags |= inner_mask;
                remaining--;
              }
            while (remaining != 0);
          }
        object_index++;
      }
    return record;
}
