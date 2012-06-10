/**
 * Simple compatability layer for syslog and strptime.
 */
#include "config.h"
#ifdef HAVE_SYSLOG_H
#include <syslog.h>
#else
#define syslog(lvl, fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#endif
#if !HAVE_DECL_STRPTIME
#include <time.h>
char * strptime(const char *buf, const char *fmt, struct tm *tm);
#endif
