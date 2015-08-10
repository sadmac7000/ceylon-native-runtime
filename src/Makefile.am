xxd = $(xxd_$(V))$(XXD)
xxd_ = $(xxd_$(AM_DEFAULT_VERBOSITY))
xxd_0 = @echo "  XXD     " $@;

AM_CFLAGS = --std=gnu99 -Wall -Wextra -D_GNU_SOURCE -fvisibility=hidden $(lcov_CFLAGS)
lib_LTLIBRARIES = libceylon.la
libceylon_la_SOURCES = print.c util.h
libceylon_la_LDFLAGS = -Wl,--defsym,cMS4xLjE.ceylon.language.print=__ceylon_language_print

MOSTLYCLEANFILES = *.gcda *.gcno *.gcov *.gcov_report launcher_help.c

if BUILD_LAUNCHER
bin_PROGRAMS = ceylon-run-native
ceylon_run_native_SOURCES = launcher.c launcher_help.c
ceylon_run_native_LDFLAGS = -ldl
endif

launcher_help.c: launcher_help.txt
	$(xxd) -i $< $@
