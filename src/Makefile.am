AM_CPPFLAGS = -D__STDC_INT64__

SUBDIRS = ../glitter
AM_CPPFLAGS += ../glitter/src

SUBDIRS += ../restart
AM_CPPFLAGS += -I ../restart/src

LIBEZIO_LIBADD = ../restart/src/.libs/librestart.la $(LIBRESTART_LIBADD)

lib_LTLIBRARIES = libezio.la
include_HEADERS = ezio.h
libezio_la_LIBADD = $(LIBEZIO_LIBADD)

bin_PROGRAMS = ezio-test
ezio_test_LDADD = libezio.la $(LIBEZIO_LIBADD)
#ezio_CFLAGS =
