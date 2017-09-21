lib_LTLIBRARIES = libezio.la
libezio_la_SOURCES = ezio.c
include_HEADERS = ezio.h
libezio_la_LDFLAGS = -lrestart

bin_PROGRAMS = ezio
ezio_SOURCES = main.c
ezio_LDFLAGS = -lrestart
ezio_LDADD = libezio.la
#ezio_CFLAGS =

#AM_CPPFLAGS = -D__STDC_INT64__
