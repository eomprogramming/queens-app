/**
 * Simple compatability layer for syslog.
 */
#include "config.h"
#ifdef HAVE_SYSLOG_H
#include <syslog.h>
#else
#define syslog(lvl, fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#endif
