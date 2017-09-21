#ifndef _EZIO_H_
#define _EZIO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

#include <glitter.h>

typedef __attribute__ ((nonnull (1, 2, 4), /*nothrow,*/ warn_unused_result))
int (*ezio_cb_t) (
   void *restrict dest,
   void const *restrict src, size_t srcsz, size_t *restrict destsz) ;

int ezio (
   fd_t in, fd_t out,
   size_t in_bufsz, size_t out_bufsz,
   ezio_cb_t cb)
__attribute__ ((leaf, nonnull (5), nothrow, warn_unused_result)) ;

#ifdef __cplusplus
}
#endif

#endif /* _EZIO_H_ */