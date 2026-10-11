#include "auto-host.h"
#ifdef IN_GCC
#include "gansidecl.h"
#endif
#ifdef IN_GCC
/* The host model.  Every host builds this compiler as the i686 GNU/Linux
   host the descriptor below names, whatever machine it really is, so the
   facts the descriptor and the source take for granted are checked here
   and a host that cannot provide them fails to build.  Double arithmetic
   must be IEEE without excess precision: on an i386 host that means SSE2,
   which the x87 default does not give.  This test comes first because
   xm-i386.h may define __i386__ itself.  */
#if defined (__i386__) && !defined (__SSE2_MATH__)
#error "agscc host model: an i386 host needs -msse2 -mfpmath=sse"
#endif
#if defined (__FLT_EVAL_METHOD__) && __FLT_EVAL_METHOD__ != 0
#error "agscc host model: double arithmetic has excess precision"
#endif
#if !defined (__BYTE_ORDER__) || __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__
#error "agscc host model: the host must be little-endian"
#endif
#include "i386/xm-i386.h"
#endif
#ifdef IN_GCC
#include "hwint.h"
#ifndef AGSCC_HOST_MODEL_CHECKED
#define AGSCC_HOST_MODEL_CHECKED
typedef char agscc_host_int_is_32_bits[sizeof (int) == 4 ? 1 : -1];
typedef char agscc_host_wide_int_is_32_bits[sizeof (HOST_WIDE_INT) == 4 ? 1 : -1];
typedef char agscc_host_plain_char_is_signed[(char) -1 < 0 ? 1 : -1];
#endif
#endif
#ifndef HAVE_ATEXIT
#define HAVE_ATEXIT
#endif
#ifndef POSIX
#define POSIX
#endif
#ifndef BSTRING
#define BSTRING
#endif
