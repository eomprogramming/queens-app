noinst_LIBRARIES = libqbet.a

libqbet_a_SOURCES = event.c xml.c

noinst_HEADERS = conf-event.h

TESTS = tests/countxml.sh
check_PROGRAMS = tests/read-test
tests_read_test_SOURCES = tests/read-test.c
tests_read_test_LDADD = libqbet.a
