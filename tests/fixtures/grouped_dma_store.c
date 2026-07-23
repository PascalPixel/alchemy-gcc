typedef unsigned int u32;

extern void inspect_object (void *);
extern void wait_for_transfer (const void *, u32);

void
write_descriptor (u32 *destination, u32 source, u32 target)
{
  destination[0] = source;
  destination[1] = target;
  destination[2] = 0x85000012;
}

void
write_preserved_descriptor (void *destination)
{
  void *object;
  u32 zero;
  u32 *source;
  u32 *descriptor;

  object = *(void **) destination;
  if (object != 0)
    inspect_object (object);

  source = &zero;
  *source = 0;
  descriptor = (u32 *) 0x050000d4;
  descriptor[0] = (u32) source;
  descriptor[1] = (u32) destination;
  descriptor[2] = 0x85000012;
}

void
write_descriptor_then_wait (u32 *destination, u32 source, u32 target)
{
  destination[0] = source;
  destination[1] = target;
  destination[2] = 0x85000012;
  wait_for_transfer ((const void *) 0x08123457, 0xc80);
}
