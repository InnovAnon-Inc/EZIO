#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#include <stdlib.h>

#include <restart.h>

#include <ezio.h>

TODO (ezio_alloc)

__attribute__ ((leaf, nonnull (5), nothrow, warn_unused_result))
int ezio (
   fd_t in, fd_t out,
   size_t in_bufsz, size_t out_bufsz,
   ezio_cb_t cb) {
   char *restrict in_buf;
   char *restrict out_buf;
   in_buf = malloc (in_bufsz + 1);
   error_check (in_buf == NULL) return -1;
   out_buf = malloc (out_bufsz);
   error_check (out_buf == NULL) {
      free (in_buf);
      return -2;
   }
   while (true) {
      ssize_t rd, wr;
      size_t destsz = out_bufsz;
      rd = r_read (in, in_buf, in_bufsz);
      error_check (rd < 0) {
         free (out_buf);
         free (in_buf);
         return -3;
      }
      if (rd == 0) {
         free (out_buf);
         free (in_buf);
         return 0;
      }
      TODO (this belongs in the client code)
      in_buf[(size_t) rd] = '\0';

      error_check (cb (out_buf, in_buf, (size_t) rd, &destsz) != 0) {
         free (out_buf);
         free (in_buf);
         return -4;
      }

      wr = r_write (out, out_buf, destsz);
      error_check (wr < 0) {
         free (out_buf);
         free (in_buf);
         return -5;
      }
      error_check ((size_t) wr != destsz) {
         free (out_buf);
         free (in_buf);
         return -6;
      }
   }
   __builtin_unreachable ();
   /* free(in_buf); free (out_buf); */
   /* return 0; */
}
