/*
 * event.h - managing conference events
 *
 * Copyright (c) 2012 by Ian Dewan
 *
 * This file, and the project of which it is a part, are made
 * available under the terms of the GNU GPL v.3. A copy of that
 * license should have come with the project, and it is
 * available at http://gnu.org/licenses
 */

#ifndef EVENT_H_
#define EVENT_H_

#include <time.h>

struct event {
	char *title;
	struct tm *datetime;
	char *loc;
	char *description;
	char **sponsers;
};

/*
 * Read an event list from the given file. The event list is returned
 * as the result. If num is not NULL, it will be set to the nmber of
 * elements in the resultin array.
 * Returns NULL in case of error.
 * The result array is dynamically allocated, but its your job to free
 * it if nessicary. (Rationale: the API is meant for small, short term
 * use apps, that won't need to do that.)
 */
struct event **read_event_list(char *filename, int *num);

#endif /* EVENT_H_ */
