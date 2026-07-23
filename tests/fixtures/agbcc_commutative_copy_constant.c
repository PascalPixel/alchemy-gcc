typedef unsigned char u8;
typedef signed int s32;

void consume(u8 *);

void commutative_copy_constant(u8 *state)
{
    s32 count = state[8];
    u8 *entry = *(u8 **)(state + 44);

    if (count > 0) {
        s32 high_mask = 0x80;

        do {
            s32 flags = entry[0];

            if ((high_mask & flags) != 0) {
                s32 low_mask = 0x40;

                if ((low_mask & flags) != 0) {
                    consume(entry);
                    entry[0] = high_mask;
                    entry[1] = low_mask;
                }
            }
            count--;
            entry += 80;
        } while (count > 0);
    }
}
