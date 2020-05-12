AM_CPPFLAGS = -D__STDC_INT64__

#if USE_SUBMODULES
#SUBDIRS = ../glitter
#AM_CPPFLAGS += $(top_srcdir)/glitter/src
#
#SUBDIRS += ../restart
#AM_CPPFLAGS += -I $(top_srcdir)/restart/src
#endif

#include Makefile-LIBADD.inc
dist_bin_SCRIPTS = libezio_config ezio_test_config

lib_LTLIBRARIES = libezio.la
include_HEADERS = ezio.h
#libezio_la_LIBADD = $(LIBEZIO_LIBADD)
libezio_la_LIBADD = @LIBEZIO_LIBADD@

bin_PROGRAMS = ezio-test
#ezio_test_LDADD = libezio.la $(LIBEZIO_LIBADD)
#ezio_test_LDADD = $(EZIO_TEST_LIBADD)
ezio_test_LDADD = @EZIO_TEST_LIBADD@
#ezio_CFLAGS =
EXTRA_ezio_test_DEPENDENCIES = libezio.la
