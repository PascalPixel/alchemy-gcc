# The host compiler and the host model, shared by every recipe in this
# package and by whoever builds the assembler beside it.
#
# Every host compiles these compilers as the same machine: plain char is
# signed (it is unsigned by default on ARM GNU/Linux), signed arithmetic
# wraps, objects may be read through another type, and a null pointer is
# not assumed away. The sources were written for compilers that behaved so;
# config/host/config.h checks the facts no flag can supply.
#
# An i386 host must add its SSE2 flags to CC itself, for example
# CC="cc -msse2 -mfpmath=sse": config.h refuses x87 arithmetic.
CC ?= cc
HOST_MODEL := -fsigned-char -fwrapv -fno-strict-aliasing -fno-delete-null-pointer-checks
