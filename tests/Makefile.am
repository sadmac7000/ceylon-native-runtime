AM_CFLAGS = --std=gnu99 -Wall -Wextra -D_GNU_SOURCE -fvisibility=hidden $(lcov_CFLAGS)

valgrind = $(valgrind_$(V))$(LIBTOOL) --mode=execute $(VALGRIND)
valgrind_ = $(valgrind_$(AM_DEFAULT_VERBOSITY))
valgrind_0 = @echo "  VALGRND " $@;

TESTS = #dummy_test
noinst_PROGRAMS = $(TESTS)

MOSTLYCLEANFILES=*.gcda *.gcno *.gcov *.valgrind

%.valgrind: %
	$(valgrind) --leak-check=full --log-file=$@ ./$^ --raw

.PHONY: valgrind-local
valgrind-local: $(patsubst %,%.valgrind,$(TESTS))

#dummy_test_SOURCES = dummy_test.c harness.c harness.h
#dummy_test_LDADD = ../src/libason.la
#dummy_test_CFLAGS = -Wno-uninitialized
