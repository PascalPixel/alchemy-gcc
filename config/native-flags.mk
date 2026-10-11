# Same native options and path normalization as the admitted build.sh.
ROOT := $(abspath ../..)
CC = gcc
CFLAGS = -O2 -fno-pie -no-pie -Wno-narrowing -Wno-implicit-int -Werror=implicit-function-declaration -Wno-pointer-arith -Werror=int-conversion -Wno-format -Wno-error -std=gnu89 -Wno-incompatible-pointer-types -fcommon -ffile-prefix-map=$(ROOT)/build=agscc/build -ffile-prefix-map=$(ROOT)=agscc
LDFLAGS = -no-pie
