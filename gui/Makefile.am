.res.rc:
	windres $< -O coff -o $@

bin_PROGRAMS = qbet-builder
dist_pkgdata_DATA = gui.glade

qbet_builder_SOURCES = main.c
qbet_builder_LDADD = ../common/libqbet.a

if WINRES
qbet_builder_LDADD += dat.res
endif

# TESTS = tests/countxml.sh
# check_PROGRAMS = tests/read-test
# tests_read_test_SOURCES = tests/read-test.c
# tests_read_test_LDADD = libqbet.a
