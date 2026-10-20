#!/bin/sh
# Compatibility entry point for the explicit admitted native build.
exec make -C "$(dirname "$0")" -j"${ALCHEMY_GCC_JOBS:-8}"
