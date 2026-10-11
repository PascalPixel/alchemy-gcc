extern int take (char *name, int count);

int warn_arg (void) { return take (7, 3); }
int warn_ptr (int *p) { char *q = p; return *q; }
int warn_shift (int x) { return x << 40; }
int warn_overflow (void) { return 0x7fffffff + 1; }
int warn_trunc (void) { char c = 4718; return c; }
