#include $(top_srcdir)/restart/src/Makefile-LIBADD.inc
include ../../restart/src/Makefile-LIBADD.inc

#if USE_SUBMODULES
#LIBEZIO_LIBADD = ../restart/src/.libs/librestart.la $(LIBRESTART_LIBADD)
#else
LIBEZIO_LIBADD = -lrestart $(LIBRESTART_LIBADD)
#endif
