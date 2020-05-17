AM_CPPFLAGS = -D__STDC_INT64__

lib_LTLIBRARIES =
bin_PROGRAMS    =

lib_LTLIBRARIES += libezio.la
include_HEADERS = ezio.h
libezio_la_CPPFLAGS = $(RESTART_CFLAGS)
libezio_la_LIBADD   = $(RESTART_LIBS)

bin_PROGRAMS += ezio-test
ezio_test_CPPFLAGS = $(RESTART_CFLAGS)
ezio_test_LDADD    = -lezio $(RESTART_LIBS)
EXTRA_ezio_test_DEPENDENCIES = libezio.la

