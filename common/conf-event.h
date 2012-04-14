/*
 * conf-event.h - managing conference events
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

/**
 * Represents an event at a conference. This is an opaque type; it should only
 * be accessed through the given functions and macros.
 */
struct event {
	char *title;
	struct tm *datetime;
	char *loc;
	char *description;
	char **sponsers;
};

/**
 * Read an event list from the given file. The event list is returned
 * as the result. If num is not NULL, it will be set to the nmber of
 *
 * @param[in] filename The file to read data from.
 * @param[out] num If it is not NULL, it will be set to the number of elements
 *  in the result array (unless an error occurs).
 * 
 * @return The list of events in the file, NULL terminated, or NULL if an error
 *  occured.<br/>
 *  The result array is dynamically allocated, but it's your job to free
 *  it if nessicary. (Rationale: the API is meant for small, short term
 *  use apps, that won't need to do that.)
 */
struct event **read_event_list(char *filename, int *num);

#endif /* EVENT_H_ */
