# Stock GCC 2.95.2 ARM compiler. Host compatibility only; no target changes.
.DEFAULT_GOAL := all
ROOT := $(abspath .)
VERSION := 2.95.2
SHA256 := 064e1cb06ea5d2f4a07ec46c1c64d771f74d04f404b6a6766bca2477f7d72482
ARCHIVE := sources/gcc-$(VERSION).tar.gz
SOURCE := sources/gcc-$(VERSION)
BUILD := build
JOBS ?= 8
CC ?= cc
SHA256SUM := $(shell command -v sha256sum >/dev/null 2>&1 && echo sha256sum || echo shasum -a 256)
# One host model on every host, the historical i386 one: signed plain char,
# wrapping arithmetic, no type-based aliasing, no fused multiply-add.
HOST_MODEL := -fsigned-char -fwrapv -fno-strict-aliasing -fno-delete-null-pointer-checks -ffp-contract=off
HOST_CFLAGS := -O2 -std=gnu89 $(HOST_MODEL) -Wno-implicit-function-declaration -Wno-int-conversion -Wno-incompatible-pointer-types -Wno-deprecated-non-prototype -fcommon
# Only the make step refuses an undeclared function: in CC it would break
# configure's own probes, which call functions without declaring them.
MAKE_CFLAGS := -O2 -Werror=implicit-function-declaration
# libiberty of 1999 calls strcpy, strlen, exit and abort without a header, and
# declares memcpy itself, which a fortified <string.h> turns into a macro.
LIBIBERTY_CFLAGS := $(MAKE_CFLAGS) -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=0 -include string.h -include stdlib.h

.PHONY: all clean verify-source
all: $(BUILD)/Makefile
	$(MAKE) -C $(BUILD) all-libiberty CFLAGS='$(LIBIBERTY_CFLAGS)'
	$(MAKE) -C $(BUILD)/gcc -j$(JOBS) cc1 CFLAGS='$(MAKE_CFLAGS)'

$(ARCHIVE):
	mkdir -p sources
	curl --fail --location --silent --show-error https://ftp.gnu.org/gnu/gcc/gcc-$(VERSION).tar.gz --output $@.download
	printf '%s  %s\n' '$(SHA256)' '$@.download' | $(SHA256SUM) -c -
	mv $@.download $@

verify-source: $(ARCHIVE)
	printf '%s  %s\n' '$(SHA256)' '$(ARCHIVE)' | $(SHA256SUM) -c -

# The shipped parser and keyword table are touched after extraction so that
# no host Bison or gperf ever runs.
$(SOURCE)/.prepared: $(ARCHIVE) host.patch
	printf '%s  %s\n' '$(SHA256)' '$(ARCHIVE)' | $(SHA256SUM) -c -
	rm -rf $(SOURCE)
	tar -xzf $(ARCHIVE) -C sources
	cd $(SOURCE) && patch -p1 < $(ROOT)/host.patch
	touch $(SOURCE)/gcc/c-parse.y
	touch $(SOURCE)/gcc/c-parse.c $(SOURCE)/gcc/c-parse.h $(SOURCE)/gcc/cexp.c $(SOURCE)/gcc/c-gperf.h
	touch $@

$(BUILD)/Makefile: $(SOURCE)/.prepared Makefile
	mkdir -p $(BUILD)
	cd $(BUILD) && CC='$(CC) $(HOST_CFLAGS)' CFLAGS='-O2' $(ROOT)/$(SOURCE)/configure --target=arm-elf --host=i686-pc-linux-gnu --build=i686-pc-linux-gnu --enable-languages=c --disable-nls --without-headers

clean:
	rm -rf $(BUILD)
