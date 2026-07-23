typedef signed int s32;

struct FixtureState {
    s32 padding[4];
    s32 value;
};

extern volatile struct FixtureState *fixture_state;
extern void prepare_fixture(void);
extern void consume_fixture_value(s32);

void schedule_fixture_frame(void)
{
    register s32 value;
    register volatile struct FixtureState *state;
    volatile s32 scratch[3];

    state = fixture_state;
    value = state->value;
    prepare_fixture();
    consume_fixture_value(value);
}
