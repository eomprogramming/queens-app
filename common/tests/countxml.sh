#!/bin/bash
# Test the xmlreading features of libqbet

res=$(echo "count1\ncount2" | tests/read-test "tests/test.xml" |\
awk 'BEGIN {first = 1}
(first == 1) {fval = $0; first = 0}
(first != 1) {if (fval != $0) print "bad"; exit}')

if [ "x$res" == "xbad" ]; then
	return 1
else
	return 0
fi
