AM_CFLAGS = --std=gnu99 -Wall -Wextra -D_GNU_SOURCE -fvisibility=hidden $(lcov_CFLAGS)
lib_LTLIBRARIES = libceylon.la
libceylon_la_SOURCES = print.c util.h

MOSTLYCLEANFILES = *.gcda *.gcno *.gcov *.gcov_report

if BUILD_LAUNCHER
bin_PROGRAMS = ceylon-launcher
ceylon_launcher_SOURCES = launcher.c
ceylon_launcher_LDFLAGS = -ldl
endif
