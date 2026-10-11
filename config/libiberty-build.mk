# The admitted host library: preserve member order and libc replacements.
.DEFAULT_GOAL := all
# The parsers and the keyword table are checked in. Make's built-in rules
# would rebuild c-parse.c or tradcif.c with the host's yacc whenever a
# checkout leaves the grammar newer than its output, so there are none.
.SUFFIXES:
%.c: %.y
%.c: %.l
include ../../config/native-flags.mk
OBJS := argv.o choose-temp.o concat.o cplus-dem.o cp-demangle.o dyn-string.o fdmatch.o fnmatch.o getopt.o getopt1.o getpwd.o getruntime.o hashtab.o hex.o floatformat.o objalloc.o obstack.o partition.o pexecute.o sort.o spaces.o splay-tree.o strerror.o strsignal.o xatexit.o xexit.o xmalloc.o xmemdup.o xstrdup.o xstrerror.o strncmp.o
all: libiberty.a
libiberty.a: $(OBJS)
	rm -f $@
	ar rc $@ $(OBJS)
	ranlib $@
%.o: $(ROOT)/libiberty/%.c config.h ../../config/libiberty-build.mk ../../config/native-flags.mk ../../config/host.mk
	$(CC) -c -DHAVE_CONFIG_H $(CFLAGS) -I. -I$(ROOT)/libiberty/../include -W -Wall -Wtraditional -pedantic -MMD -MP $<
-include $(OBJS:.o=.d)
