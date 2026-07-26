typedef void (*Handler)(void);

extern Handler gHandlers[];
extern void DefaultHandler(void);

void order_thumb_literal_before_index_shift(unsigned index, Handler handler)
{
    if (handler != 0)
        gHandlers[index] = handler;
    else
        gHandlers[index] = DefaultHandler;
}

void keep_unrelated_literal_shift(unsigned index)
{
    extern unsigned gValues[];
    extern unsigned gDefault;
    gValues[index] = gDefault;
}
