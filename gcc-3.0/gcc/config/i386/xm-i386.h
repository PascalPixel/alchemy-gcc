/* Configuration for GNU C-compiler for Intel 80386.
   Copyright (C) 1988, 1993 Free Software Foundation, Inc.

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/* This host descriptor is selected for every non-x86 build host under
   build.sh's host override, including native arm64 macOS. There
   __i386__ is legitimately undefined but __arm64__/__aarch64__ is
   defined; blindly defining __i386__ then makes both families of
   Apple's <libkern/_OSByteOrder.h> arch dispatch (i386 and arm) true
   simultaneously, a hard redefinition error under Clang. Apply the
   shim only when no 64-bit/ARM host macro is present, matching the
   original behavior on real 32-bit x86 hosts. Same fix as the
   gcc-2.96 tree. */
#if !defined(__i386__) && !defined(__x86_64__) && !defined(__arm64__) && !defined(__aarch64__) && !defined(__arm__)
#define __i386__ 1
#endif

/* This describes the machine the compiler is hosted on.  */
#define HOST_BITS_PER_CHAR 8
#define HOST_BITS_PER_SHORT 16
#define HOST_BITS_PER_INT 32
#define HOST_BITS_PER_LONG 32
#define HOST_BITS_PER_LONGLONG 64

/* Arguments to use with `exit'.  */
#define SUCCESS_EXIT_CODE 0
#define FATAL_EXIT_CODE 33

/* target machine dependencies.
   tm.h is a symbolic link to the actual target specific file.   */

#include "tm.h"
