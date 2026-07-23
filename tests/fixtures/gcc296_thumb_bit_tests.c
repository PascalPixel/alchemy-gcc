typedef unsigned char u8;
typedef signed int s32;

typedef void (*ValueCallback)(s32);

struct CallbackTable {
    u8 padding[44];
    ValueCallback callback;
};

extern struct CallbackTable *fixture_callback_table;
extern void fixture_low_bit_callback(void);

void test_fixture_low_bit(unsigned int value)
{
    if ((value & 1) != 0)
        fixture_low_bit_callback();
}

void scan_fixture_records(s32 mask, u8 *state)
{
    u8 flags = state[0];
    u8 *record;

    mask = 0x80;
    if ((mask & flags) != 0) {
        record = *(u8 **)(state + 0x20);
        if (record != 0) {
            s32 zero = 0;

            do {
                s32 kind = record[0];

                if (kind != 0) {
                    kind = record[1];
                    kind &= 7;
                    if (kind != 0)
                        fixture_callback_table->callback(kind);
                    record[0] = zero;
                }
                *(s32 *)(record + 0x2c) = zero;
                record = *(u8 **)(record + 0x34);
            } while (record != 0);
        }
        *(u8 **)(state + 0x20) = record;
    }
}
