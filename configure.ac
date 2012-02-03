AC_PREREQ([2.64])
AC_INIT([glossy],
        [0.0.0],
        [http://code.google.com/p/glossy/issues/list],
        [glossy],
        [http://code.google.com/p/glossy/])

AC_CONFIG_SRCDIR([glossy.pc.in])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([1.11.1 gnu dist-bzip2 no-dist-gzip -Wall])
AM_SILENT_RULES([yes])

# Check for programs
AM_PROG_CC_C_O
AC_PROG_CXX

dnl ===========================================================================

AC_CONFIG_FILES([
glossy.pc
Makefile
src/Makefile
])

AC_OUTPUT
