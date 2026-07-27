typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

struct PoolDefinition {
    u8 padding_00[2];
    u8 placement;
};

extern u8 effect_base_marker;
extern u8 present_mask_marker;

struct PoolDefinition *lookup_pool_definition(s32 effect_id);
void place_pool_effect(s32 effect_id, s32 owner_id, s32 layer, s32 position);

void order_three_word_pool(s32 owner_id, void *slot_data)
{
    s32 effect_base = (s32)&effect_base_marker;
    s32 present;
    s32 effect_id;
    s32 index;
    u16 *effect_slots;
    u16 slot;
    u8 placement;

    effect_slots = slot_data;
    index = 14;
    do
    {
        slot = *effect_slots;
        present = slot & (s32)&present_mask_marker;
        effect_slots++;
        if (present != 0)
        {
            effect_id = slot & 0x1ff;
            placement = lookup_pool_definition(effect_id)->placement;
            switch (placement)
            {
            case 1:
                place_pool_effect(effect_id + effect_base, owner_id, 8, 8);
                break;
            case 2:
                place_pool_effect(effect_id + effect_base, owner_id, 8, 56);
                break;
            case 3:
                place_pool_effect(effect_id + effect_base, owner_id, 8, 40);
                break;
            case 4:
                place_pool_effect(effect_id + effect_base, owner_id, 8, 24);
                break;
            }
        }
        index--;
    } while (index >= 0);
}

u32 keep_two_word_pool(u32 value)
{
    value += (u32)&effect_base_marker;
    value += (u32)&present_mask_marker;
    return value;
}
