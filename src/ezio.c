#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#include <stdlib.h>

#include <restart.h>

#include <ezio.h>

__attribute__ ((leaf, nonnull (3), nothrow, warn_unused_result))
int ezio (size_t in_bufsz, size_t out_bufsz, ezio_cb_t cb) {
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
      rd = r_read (STDIN_FILENO, in_buf, in_bufsz);
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
      in_buf[(size_t) rd] = '\0';

      error_check (cb (out_buf, in_buf, (size_t) rd, &destsz) != 0) {
         free (out_buf);
         free (in_buf);
         return -4;
      }

      wr = r_write (STDOUT_FILENO, out_buf, destsz);
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
