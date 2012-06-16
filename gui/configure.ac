#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([QBet Builder], [1.0], [eomprogramming@gmail.com],,
	[http://github.com/eomprogramming/queens-app])
AC_CONFIG_SRCDIR([main.c])
AM_INIT_AUTOMAKE([-Wall foreign])

# Substitution files
AC_CONFIG_FILES([Makefile])

# Optional features
AC_ARG_ENABLE([win-res], [AC_HELP_STRING([--enable-win-res],
	      [add a Windows .res file to the executable (default: no)])],
	      [winres=${enableval}], [winres=no])
AM_CONDITIONAL([WINRES], [test x$winres = xyes])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
dnl AC_CHECK_LIB([xml2], [xmlParseFile],,
	     dnl [AC_MSG_ERROR([libqbet requires libxml2])])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_OUTPUT
