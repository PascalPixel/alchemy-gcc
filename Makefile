# Alchemy's three admitted C generators. See README.md.
.DEFAULT_GOAL := all
ROOT := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
include $(ROOT)/config/host.mk
HEADERS := auto-host.h config.h hconfig.h tm_p.h options.h specs.h gencheck.h
CONFIG := $(addprefix build/gcc/,$(HEADERS)) build/gcc/tconfig.h build/gcc/tm.h build/libiberty/config.h
GENERATED := insn-attrtab.c insn-emit.c insn-extract.c insn-opinit.c insn-output.c insn-peep.c insn-recog.c insn-attr.h insn-codes.h insn-config.h insn-flags.h genrtl.c genrtl.h tree-check.h multilib.h
SHA256SUM := $(shell command -v sha256sum >/dev/null 2>&1 && echo sha256sum || echo shasum -a 256)
# The two GNU releases, vendored unpacked and unmodified from
# gcc-2.95.2.tar.gz (SHA-256 064e1cb06ea5d2f4a07ec46c1c64d771f74d04f404b6a6766bca2477f7d72482)
# and binutils-2.10.tar.gz (SHA-256 fd7d227c0dd15cf5448385e56b8ad8313cd491839834b57c0c086ac7b7819a15).
# Each pin is the SHA-256 of the sorted list of the tree's file sums, which
# tree_sha256 prints; source-check refuses a tree that differs from it.
GCC2952_SHA256 := 6d21215da27c37a7dc6940f0673bfa63563159ab22416ab9556a78f2266cca3c
BINUTILS210_SHA256 := 3974cbbb76b02730f9d7266b52915ccb94a6f5f2879305f9ba8c31301fc175f1
tree_sha256 = $$(cd $(ROOT)/$(1) && find . -type f ! -name .DS_Store | LC_ALL=C sort | xargs $(SHA256SUM) | $(SHA256SUM) | cut -c1-64)
# pret's agbcc, vendored unmodified from github.com/pret/agbcc at commit
# da598c1d918402c42c0c0d7128ba14567f3175e9. It builds in place, so its pin
# sums only the files git tracks under agbcc/, never what the build leaves.
AGBCC_SHA256 := f40f4b985d443e47cbc85ae399a3ec5464a460f00905557d5711264315a919f9
agbcc_sha256 = $$(cd $(ROOT) && git ls-files -z agbcc | LC_ALL=C xargs -0 $(SHA256SUM) | $(SHA256SUM) | cut -c1-64)
.PHONY: all clean gcc libiberty arm old-agbcc source-check generated-check
all: gcc arm old-agbcc
arm:
	$(MAKE) -C arm
old-agbcc: source-check
	$(MAKE) -C agbcc/gcc old -j1 CC="$(CC) $(HOST_MODEL)"
source-check:
	@test "$(agbcc_sha256)" = '$(AGBCC_SHA256)' || { printf 'agbcc differs from pret/agbcc at da598c1\n'; exit 1; }
	@test "$(call tree_sha256,gcc-2.95.2)" = '$(GCC2952_SHA256)' || { printf 'gcc-2.95.2 differs from the GNU release\n'; exit 1; }
	@test "$(call tree_sha256,binutils-2.10)" = '$(BINUTILS210_SHA256)' || { printf 'binutils-2.10 differs from the GNU release\n'; exit 1; }
libiberty: $(CONFIG)
	$(MAKE) -C build/libiberty -f $(ROOT)/config/libiberty-build.mk
gcc: libiberty
	$(MAKE) -C build/gcc -f $(ROOT)/config/arm-build.mk
build/gcc/tconfig.h: config/arm/tconfig.h
	mkdir -p build/gcc
	cp $< $@
build/gcc/tm.h: config/arm/tm.h
	mkdir -p build/gcc
	cp $< $@
build/gcc/%: config/host/%
	mkdir -p build/gcc
	cp $< $@
build/libiberty/config.h: config/host/libiberty-config.h
	mkdir -p build/libiberty
	cp $< $@
# The tables the host generators write from arm.md, rtl.def and tree.def must
# be the same text on every host: a difference here is a host leaking into
# the compiler before it has compiled anything. They must also name no
# directory of the machine that built them.
generated-check: gcc
	@cd build/gcc && if grep -l -F -e '$(ROOT)' -e '"/' $(GENERATED); then printf 'generated tables name an absolute path\n'; exit 1; fi
	@cd build/gcc && $(SHA256SUM) -c $(ROOT)/config/generated.sha256 >/dev/null || { printf 'generated tables differ from config/generated.sha256\n'; exit 1; }
	@printf 'generated tables match config/generated.sha256\n'
clean:
	rm -rf build
	$(MAKE) -C arm clean
	$(MAKE) -C agbcc/gcc clean
