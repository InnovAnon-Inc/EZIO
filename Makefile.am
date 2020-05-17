# Install the pkg-config file.
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = src/libezio.pc src/ezio-test.pc

DISTCLEANFILES = $(pkgconfig_DATA)
EXTRA_DIST = src/libezio.pc.in src/ezio-test.pc.in

#SUBDIRS = glitter restart src
SUBDIRS = src
dist_doc_DATA = README.md
ACLOCAL_AMFLAGS = -I m4

