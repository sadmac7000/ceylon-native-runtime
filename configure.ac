AC_INIT([libceylon], [1.2.0], [casey.dahlin@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror -Wno-portability foreign
                  parallel-tests subdir-objects])
AM_EXTRA_RECURSIVE_TARGETS([valgrind])
AM_SILENT_RULES([yes])
AC_PROG_CC
m4_pattern_allow([AM_PROG_AR])
AM_PROG_AR
AC_PROG_LN_S

AC_ARG_ENABLE([lcov], [AS_HELP_STRING(
	       [--enable-lcov],
	       [Compile in lcov support])
], [], [enable_lcov=no])

lcov_CFLAGS=

AC_PATH_PROG([LCOV], [lcov], [no])
AC_PATH_PROG([GENHTML], [genhtml], [no])
AS_IF([test "x$enable_lcov" = xyes], [
       lcov_CFLAGS="-O0 -fprofile-arcs -ftest-coverage"
       ], [])
AC_ARG_VAR([lcov_CFLAGS], [C compiler flags for lcov])

test "x$LCOV" = "xno" -a "x$enable_lcov" = xyes && \
	AC_MSG_ERROR([lcov command not found])
test "x$GENHTML" = "xno" -a "x$enable_lcov" = xyes && \
	AC_MSG_ERROR([genhtml command (part of lcov) not found])

AC_PATH_PROG([VALGRIND], [valgrind], [no])

LT_INIT
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([include/config.h])
AC_CONFIG_FILES([
	Makefile
	src/Makefile
	include/Makefile
	tests/Makefile
])
AC_OUTPUT
