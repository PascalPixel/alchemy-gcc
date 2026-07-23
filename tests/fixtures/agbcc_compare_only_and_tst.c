typedef unsigned char u8;

struct TestNode {
    u8 flags;
    u8 padding[0x33];
    struct TestNode *next;
};

struct TestContext {
    u8 active;
    u8 padding[0x1f];
    struct TestNode *head;
};

extern void visit_test_node(void *);
extern void visit_relational_mask(int);

void walk_test_nodes(void *unused, struct TestContext *context)
{
    struct TestNode *node;

    node = context->head;
    while (node != 0) {
        u8 flags;

        flags = node->flags;
        if (flags & 0xc7) {
            flags |= 0x40;
            node->flags = flags;
        }
        visit_test_node(node);
        node = node->next;
    }
    context->active = 0;
}

int retain_masked_value(int value, int mask, int *output)
{
    int filtered = value & mask;

    if (filtered != 0)
        *output = filtered;
    return filtered;
}

void keep_relational_compare(int value, int mask)
{
    int filtered = value & mask;

    if (filtered >= 0)
        visit_relational_mask(1);
}
