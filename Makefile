# Alchemy's three admitted C generators. See README.md.
.DEFAULT_GOAL := all
ROOT := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
HEADERS := auto-host.h config.h hconfig.h tm_p.h options.h specs.h gencheck.h
CONFIG := $(addprefix build/gcc/,$(HEADERS)) build/gcc/tconfig.h build/gcc/tm.h build/libiberty/config.h
GENERATED := insn-attrtab.c insn-emit.c insn-extract.c insn-opinit.c insn-output.c insn-peep.c insn-recog.c insn-attr.h insn-codes.h insn-config.h insn-flags.h genrtl.c genrtl.h tree-check.h multilib.h
SHA256SUM := $(shell command -v sha256sum >/dev/null 2>&1 && echo sha256sum || echo shasum -a 256)
.PHONY: all clean gcc libiberty arm old-agbcc source-check generated-check
all: gcc arm old-agbcc
arm:
	$(MAKE) -C arm
old-agbcc: source-check
	$(MAKE) -C agbcc/gcc old -j1
source-check:
	@set -e; approved=$$(git rev-parse :agbcc); \
	  test "$$(git -C agbcc rev-parse HEAD)" = "$$approved" || { printf 'agbcc checkout does not match its gitlink\n'; exit 1; }; \
	  state=$$(git -C agbcc status --porcelain --untracked-files=all -- . ':(exclude,glob)**/.DS_Store'); \
	  test -z "$$state" || { printf 'agbcc compiler source is dirty\n'; exit 1; }
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
