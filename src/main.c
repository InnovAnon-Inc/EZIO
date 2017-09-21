#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#include <stdlib.h>
#include <string.h>

#include <ezio.h>

TODO (this macro has been moved to glitter.h)
#ifndef min
#define min(A, B) ((A) < (B) ? (A) : (B))
#endif

__attribute__ ((nonnull (1, 2, 4), nothrow, warn_unused_result))
static int ezio_cb (
   void *restrict dest,
   void const *restrict src,
   size_t srcsz, size_t *restrict destsz) {
   *destsz = min (srcsz, *destsz);
   memcpy (dest, src, *destsz);
   return 0;
}

__attribute__ ((nothrow, warn_unused_result))
int main (void) {
   error_check (ezio ((size_t) 10, (size_t) 8, ezio_cb) != 0)
      return EXIT_FAILURE;
   return EXIT_SUCCESS;
}