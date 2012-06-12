#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.60])
AC_INIT([QBet Library], [1.0], [eomprogramming@gmail.com],,
	[http://github.com/eomprogramming/queens-app])
AC_CONFIG_SRCDIR([conf-event.h])
AM_INIT_AUTOMAKE([-Wall foreign])

# Substitution files
AC_CONFIG_FILES([Makefile Doxyfile])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_RANLIB

# Checks for libraries.
AC_CHECK_LIB([xml2], [xmlParseFile],,
	     [AC_MSG_ERROR([libqbet requires libxml2])])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h libxml/parser.h],,
		 [AC_MSG_ERROR([Missing required header file.])])
AC_CHECK_HEADERS([syslog.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([strdup])

AC_OUTPUT
