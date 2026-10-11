extern void hit (void);

void z80 (unsigned char *p) { if ((*p << 24) == 0x80000000) hit (); }
void zff (unsigned char *p) { if ((*p << 24) == 0xff000000) hit (); }
void zc3 (unsigned char *p) { if (((unsigned) *p << 24) != 0xc3000000u) hit (); }
void z7f (unsigned char *p) { if ((*p << 24) == 0x7f000000) hit (); }
void z01 (unsigned char *p) { if ((*p << 24) == 0x01000000) hit (); }
void s80 (signed char *p) { if ((*p << 24) == (int) 0x80000000) hit (); }
void u80 (unsigned char *p) { if (((unsigned) *p << 24) >= 0x80000000u) hit (); }
int  r80 (unsigned char *p) { return (*p << 24) == 0x80000000; }
struct s { char pad[3]; unsigned char b; };
void m80 (struct s *q) { if ((q->b << 24) == 0x80000000) hit (); }
void mfe (struct s *q) { while ((q->b << 24) != 0xfe000000) q++; }
