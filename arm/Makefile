# Stock GCC 2.95.2 ARM compiler. Host compatibility only; no target changes.
.DEFAULT_GOAL := all
ROOT := $(abspath .)
VERSION := 2.95.2
SHA256 := 064e1cb06ea5d2f4a07ec46c1c64d771f74d04f404b6a6766bca2477f7d72482
ARCHIVE := sources/gcc-$(VERSION).tar.gz
SOURCE := sources/gcc-$(VERSION)
BUILD := build
JOBS ?= 8
# The host compiler and the host model, the same file the GCC 2.96 and
# old_agbcc recipes read: one model for every compiler and every host.
include $(ROOT)/../config/host.mk
SHA256SUM := $(shell command -v sha256sum >/dev/null 2>&1 && echo sha256sum || echo shasum -a 256)
HOST_CFLAGS := -O2 -std=gnu89 $(HOST_MODEL) -Wno-implicit-function-declaration -Wno-int-conversion -Wno-incompatible-pointer-types -Wno-deprecated-non-prototype -fcommon
# configure and both make steps are handed the same compiler string. A CC
# given on make's command line would otherwise reach the sub-makes bare,
# without the language standard and the host model.
HOST_CC := $(CC) $(HOST_CFLAGS)
# Only the make step refuses an undeclared function: in CC it would break
# configure's own probes, which call functions without declaring them.
MAKE_CFLAGS := -O2 -Werror=implicit-function-declaration
# libiberty of 1999 calls strcpy, strlen, exit and abort without a header, and
# declares memcpy itself, which a fortified <string.h> turns into a macro.
LIBIBERTY_CFLAGS := $(MAKE_CFLAGS) -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=0 -include string.h -include stdlib.h
# The admitted ARM profile, for the probes.
PROFILE := -O2 -mthumb-interwork -fomit-frame-pointer -fcall-used-r4
PROBES := cmpz warn error

.PHONY: all clean verify-source probe
all: $(BUILD)/Makefile
	$(MAKE) -C $(BUILD) all-libiberty CC='$(HOST_CC)' CFLAGS='$(LIBIBERTY_CFLAGS)'
	$(MAKE) -C $(BUILD)/gcc -j$(JOBS) cc1 CC='$(HOST_CC)' CFLAGS='$(MAKE_CFLAGS)' BISON=false

$(ARCHIVE):
	mkdir -p sources
	curl --fail --location --silent --show-error https://ftp.gnu.org/gnu/gcc/gcc-$(VERSION).tar.gz --output $@.download
	printf '%s  %s\n' '$(SHA256)' '$@.download' | $(SHA256SUM) -c -
	mv $@.download $@

verify-source: $(ARCHIVE)
	printf '%s  %s\n' '$(SHA256)' '$(ARCHIVE)' | $(SHA256SUM) -c -

# The shipped parser and keyword table are touched after extraction so that
# no host Bison or gperf ever runs, and the make step names `false` as its
# Bison so that a regeneration would stop the build instead of writing a
# different parser. GCC's own Makefile clears make's built-in suffix rules.
$(SOURCE)/.prepared: $(ARCHIVE) host.patch
	printf '%s  %s\n' '$(SHA256)' '$(ARCHIVE)' | $(SHA256SUM) -c -
	rm -rf $(SOURCE)
	tar -xzf $(ARCHIVE) -C sources
	cd $(SOURCE) && patch -p1 < $(ROOT)/host.patch
	touch $(SOURCE)/gcc/c-parse.y
	touch $(SOURCE)/gcc/c-parse.c $(SOURCE)/gcc/c-parse.h $(SOURCE)/gcc/cexp.c $(SOURCE)/gcc/c-gperf.h
	touch $@

$(BUILD)/Makefile: $(SOURCE)/.prepared Makefile ../config/host.mk
	mkdir -p $(BUILD)
	cd $(BUILD) && CC='$(HOST_CC)' CFLAGS='-O2' $(ROOT)/$(SOURCE)/configure --target=arm-elf --host=i686-pc-linux-gnu --build=i686-pc-linux-gnu --enable-languages=c --disable-nls --without-headers

# Each probe must give, byte for byte, the assembler text and the diagnostics
# recorded from a 32-bit Linux build of the same source (probe/README.md).
probe: $(PROBES:%=probe-%)
probe-%: all
	mkdir -p $(BUILD)/probe
	-cd probe && $(ROOT)/$(BUILD)/gcc/cc1 $*.c -quiet -dumpbase $*.c $(PROFILE) -o $(ROOT)/$(BUILD)/probe/$*.s 2> $(ROOT)/$(BUILD)/probe/$*.err
	cmp probe/$*.s $(BUILD)/probe/$*.s
	cmp probe/$*.err $(BUILD)/probe/$*.err

clean:
	rm -rf $(BUILD)
