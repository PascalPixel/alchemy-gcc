extern int take (char *name, int count);
struct pair { int first, second; };

int err_undeclared (void) { return missing_name + 1; }
int err_args (void) { return take ("one"); }
int err_member (struct pair *p) { return p->third; }
int err_type (struct pair p) { return p + 1; }
int err_size[-4718];
