# alchemy-gcc -- the compilers Golden Sun was built with.
#
#   gs1cc   Golden Sun's compiler       gcc 2.96 snapshot, 2000-07-31
#   gs2cc   The Lost Age's compiler     gcc 3.0.0
#   agbcc   the Thumb audio compiler    pret/agbcc  (old_agbcc)
#
# The first commit of this repository is those three trees, UNTOUCHED, straight
# from their upstreams. Every change since is a commit with a reason, so
# `git log' answers "what did we change" and PROVENANCE.txt answers "where did
# this come from". That is the whole design.
#
#   make            build and stage gs1cc into dist/
#   make test       codegen regression tests
#   make ours       show every line we changed, per tree
#   make install    install into a decomp checkout: make install DECOMP=../alchemy
#   make clean      remove build trees and dist/

CARGO  ?= cargo
DRIVER := $(CARGO) run --release --quiet --
UPSTREAM := 4087bd2bd7c064da935c2a1bf798b814a125eded

.PHONY: all build stage install test ours clean

all: stage
build:
	$(DRIVER) build gs1cc
stage: build
	$(DRIVER) stage gs1cc
install: stage
	@test -n "$(DECOMP)" || { echo "usage: make install DECOMP=<path to decomp checkout>"; exit 1; }
	$(DRIVER) install "$(DECOMP)" gs1cc
test:
	$(DRIVER) test gs1cc

# Everything this project changed, against untouched upstream. Modified files
# only -- the prune of the non-C subprojects is a deletion, not a change to a
# compiler, and listing 5000 removed zlib files answers nothing.
ours:
	@for t in gs1cc gs2cc agbcc; do \
		n=$$(git diff --name-only --diff-filter=M $(UPSTREAM) -- $$t | wc -l | tr -d ' '); \
		printf "  %-8s %s files modified\n" "$$t" "$$n"; \
	done
	@echo
	@git diff --stat --diff-filter=M $(UPSTREAM) -- gs1cc gs2cc agbcc | tail -40

clean:
	rm -rf build-gs1cc build-gs2cc dist
