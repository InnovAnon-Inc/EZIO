lib_LTLIBRARIES = libezio.la
libezio_la_SOURCES = ezio.c
include_HEADERS = ezio.h
libezio_la_LIBADD = -lrestart

bin_PROGRAMS = ezio
ezio_SOURCES = main.c
ezio_LDADD = libezio.la -lrestart
#ezio_CFLAGS =

AM_CPPFLAGS = -D__STDC_INT64__
AM_CPPFLAGS += -I $(srcdir)/../glitter/src
AM_CPPFLAGS += -I $(srcdir)/../restart/src
