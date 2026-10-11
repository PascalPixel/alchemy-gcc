double d_table[] = { 0.0, 1.0, 2.0, -1.0, 0.1, 4718.592, 8912896.0, -2.5e-3, 1e300, 4.9e-324 };
float f_table[] = { 0.5f, 3.14159274f, -16777216.0f, 1e-45f };
long long ll_table[] = { 0x123456789abcdef0LL, -1LL, 0x80000000LL, -0x80000000LL, 0x7fffffffffffffffLL };
unsigned long long ull_table[] = { 0xfedcba9876543210ULL, 0xffffffff00000000ULL };

double d_load (void) { return 4718.592; }
double d_scale (double x) { return x * 8912896.0 + 0.1; }
double d_fold (void) { return 3.0 * 0.1 - 1e-7 / 3.0; }
float f_load (void) { return 3.14159274f; }
int d_to_int (void) { return (int) (4718.592 * 1000.0); }
double i_to_d (int i) { return i / 7.0; }
int d_cmp (double x) { return x > 2.0 ? 1 : x == 1.0 ? 2 : x < -1.0 ? 3 : 0; }

long long ll_load (void) { return 0x123456789abcdef0LL; }
long long ll_add (long long x) { return x + 0x100000001LL; }
long long ll_mask (long long x) { return x & 0xffffffff00000000LL; }
unsigned long long ull_shift (unsigned long long x) { return (x >> 33) | 0x8000000000000000ULL; }
long long ll_fold (void) { return 0x7fffffffLL * 0x10001LL - 0x80000000LL; }
long long ll_neg (void) { return -0x80000000LL; }
void ll_store (long long *p) { p[0] = 0x80000000LL; p[1] = 0xffffffff80000000LL; p[2] = 0x100000000LL; }
int big_int (int x) { return x + 0x80000000 + (x & 0xff00ff00) + (x ^ 0x12345678); }
