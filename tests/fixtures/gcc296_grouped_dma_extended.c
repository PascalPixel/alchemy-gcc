typedef unsigned int u32;

struct FourWordRecord {
    u32 value;
    u32 zero4;
    u32 zero8;
    u32 zeroC;
};

void grouped_literal_descriptor(void)
{
    u32 *descriptor = (u32 *)0x04000120;
    u32 source = 0x08001234;
    u32 destination = 0x05000340;
    u32 control = 0x80000070;

    descriptor[0] = source;
    descriptor[1] = destination;
    descriptor[2] = control;
}

void grouped_stack_descriptor(void)
{
    u32 zero;
    u32 *source;
    u32 *state;
    u32 *descriptor;

    state = (u32 *)0x03001240;
    source = &zero;
    *source = 0;
    descriptor = (u32 *)0x04000120;
    descriptor[0] = (u32)source;
    descriptor[1] = (u32)state;
    descriptor[2] = 0x85000020;
    state[1] = 0x03002100;
    state[0] = 0x02003100;
}

void grouped_four_word_records(void)
{
    struct FourWordRecord *records =
        (struct FourWordRecord *)0x03001280;

    records[0].value = 0x10000;
    records[0].zero4 = 0;
    records[0].zero8 = 0;
    records[0].zeroC = 0;
    records[1].value = 0x10000;
    records[1].zero4 = 0;
    records[1].zero8 = 0;
    records[1].zeroC = 0;
    records[2].value = 0x10000;
    records[2].zero4 = 0;
    records[2].zero8 = 0;
    records[2].zeroC = 0;
}

void grouped_four_word_records_short(void)
{
    struct FourWordRecord *records =
        (struct FourWordRecord *)0x030012c0;

    records[0].value = 0x10000;
    records[0].zero4 = 0;
    records[0].zero8 = 0;
    records[0].zeroC = 0;
    records[1].value = 0x10000;
    records[1].zero4 = 0;
    records[1].zero8 = 0;
    records[1].zeroC = 0;
    records[2].value = 0x10000;
    records[2].zero4 = 0;
    records[2].zero8 = 0;
}

void grouped_four_word_records_nonzero_lane(void)
{
    struct FourWordRecord *records =
        (struct FourWordRecord *)0x03001300;

    records[0].value = 0x10000;
    records[0].zero4 = 1;
    records[0].zero8 = 1;
    records[0].zeroC = 1;
    records[1].value = 0x10000;
    records[1].zero4 = 1;
    records[1].zero8 = 1;
    records[1].zeroC = 1;
    records[2].value = 0x10000;
    records[2].zero4 = 1;
    records[2].zero8 = 1;
    records[2].zeroC = 1;
}

struct FourWordRecord *grouped_four_word_records_live_scratch(void)
{
    struct FourWordRecord *records =
        (struct FourWordRecord *)0x03001340;

    records[0].value = 0x10000;
    records[0].zero4 = 0;
    records[0].zero8 = 0;
    records[0].zeroC = 0;
    records[1].value = 0x10000;
    records[1].zero4 = 0;
    records[1].zero8 = 0;
    records[1].zeroC = 0;
    records[2].value = 0x10000;
    records[2].zero4 = 0;
    records[2].zero8 = 0;
    records[2].zeroC = 0;
    return records;
}
