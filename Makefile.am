lcov = $(lcov_$(V))$(LCOV)
lcov_ = $(lcov_$(AM_DEFAULT_VERBOSITY))
lcov_0 = @echo "  LCOV    " $@;

genhtml = $(genhtml_$(V))$(GENHTML)
genhtml_ = $(genhtml_$(AM_DEFAULT_VERBOSITY))
genhtml_0 = @echo "  GENHTML " $@;

GENHTML_FLAGS=--branch-coverage $(LCOV_FLAGS)
LCOV_FLAGS=--rc lcov_branch_coverage=1 $(LCOV_FLAGS_$(V))
LCOV_FLAGS_= $(LCOV_FLAGS_$(AM_DEFAULT_VERBOSITY))
LCOV_FLAGS_0= -q

ACLOCAL_AMFLAGS = -I m4
SUBDIRS = src include tests
EXTRA_DIST=README.md NEWS.md

.PHONY: lcov
lcov: coverage

tests/test-suite.log:
	-$(MAKE) check

coverage.info.raw: tests/test-suite.log
	$(lcov) --capture --directory . $(LCOV_FLAGS) --output-file $@

coverage.info.all_code: coverage.info.raw
	$(lcov) --directory . --extract $< $(abs_top_builddir)/src/\* $(LCOV_FLAGS) --output-file $@
coverage.info: coverage.info.all_code
	$(lcov) --directory . --remove $< $(abs_top_builddir)/src/parse.c $(LCOV_FLAGS) --output-file $@

coverage: coverage.info
	$(genhtml) $^ $(GENHTML_FLAGS) --output-dir $@

MOSTLYCLEANFILES = coverage.info coverage.info.raw coverage.info.all_code

clean-local:
	-rm -rf coverage
