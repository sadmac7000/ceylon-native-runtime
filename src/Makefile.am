lmvb64 = MS4zLjA

symbol_map = \
    c$(lmvb64).ceylon.language.print=__ceylon_language_print \
    c$(lmvb64).ceylon.language.\$$Basic\$$vtable=__ceylon_language_Basic_vtable \
    c$(lmvb64).ceylon.language.\$$Basic\$$size=__ceylon_language_Basic_size \
    c$(lmvb64).ceylon.language.\$$Basic\$$vtSize=__ceylon_language_Basic_vtsize \
    c$(lmvb64).ceylon.language.\$$Basic\$$setup=__ceylon_language_Basic_setup

comma := ,
empty :=
space := $(empty) $(empty)
symbol_args = $(foreach arg,$(symbol_map),--defsym$(comma)$(arg))

AM_CFLAGS = --std=gnu99 -Wall -Wextra -D_GNU_SOURCE -fvisibility=hidden $(lcov_CFLAGS)

lib_LTLIBRARIES = libceylon.la
libceylon_la_LDFLAGS = -Wl,$(subst $(space),$(comma),$(symbol_args))
libceylon_la_SOURCES = \
    Basic.c \
    print.c \
    util.h

libexec_PROGRAMS = ceylon-launcher
ceylon_launcher_SOURCES = launcher.c
ceylon_launcher_LDFLAGS = -ldl
ceylon_launcher_LDADD = libceylon.la

MOSTLYCLEANFILES = *.gcda *.gcno *.gcov *.gcov_report
