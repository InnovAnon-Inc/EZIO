AC_INIT([libezio], [0.0], [laurence.a.maddox@gmail.com])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AM_PROG_AR
LT_INIT([])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
 Makefile
 src/Makefile
])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SUBDIRS([glitter restart])

AC_CHECK_HEADERS([stdlib.h])
AC_CHECK_HEADERS([strings.h])
AC_CHECK_HEADERS([glitter.h restart.h])

AC_CHECK_LIB([stdlib],[malloc,free])
AC_CHECK_LIB([restart],[r_read,r_write])
AC_CHECK_LIB([stdlib],[memcpy])

INNOVANON_WARNINGS([])

AC_OUTPUT
