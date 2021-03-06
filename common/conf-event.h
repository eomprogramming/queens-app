/**
 * @file conf-event.h
 * Managing conference events
 */
/* Copyright (c) 2012 by Ian Dewan
 *
 * This file, and the project of which it is a part, are made
 * available under the terms of the GNU GPL v.3. A copy of that
 * license should have come with the project, and it is
 * available at http://gnu.org/licenses
 */

#ifndef CONF_EVENT_H_
#define CONF_EVENT_H_

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
	char **sponsors;
	char *image;
	char *speaker;
};

/**
 * Check if the parameter points to a null event.
 * @param ev A pointer to a struct event.
 */
#define EVENT_IS_NULL(ev) ((ev)->title == NULL)

/**
 * Read an event list from the given file. The event list is returned
 * as the result. If num is not NULL, it will be set to the nmber of
 *
 * @param[in] filename The file to read data from.
 * @param[out] num If it is not NULL, it will be set to the number of elements
 *  in the result array, not including the terminal null. (unless an error
 *  occurs).
 * 
 * @return The list of events in the file, terminated by the null event
 *  (check for this using EVENT_IS_NULL), or NULL if an error occured.<br/>
 *  The result array is dynamically allocated, but it's your job to free
 *  it if nessicary. (Rationale: the API is meant for small, short term
 *  use apps, that won't need to do that.)
 *
 * @see EVENT_IS_NULL, struct event
 */
struct event *read_event_list(const char *filename, int *num);

/**
 * Read the version number contained in the given file.
 * @param filename the file to read
 * @return The version number, or -1 if it does not exist.
 */
long event_list_version(const char *filename);

/**
 * Get the title of an event.
 * @param e a pointer to the event
 * @return The title (char *)
 */
#define ev_title(e) (e)->title

/**
 * Get the date and time of an event.
 * @param e a pointer to the event
 * @return The date and time, as a struct tm *. Only the year, month, day, hour,
 * minute and second fields will be filled: tm_wday, tm_yday and tm_isdst will
 * be junk.
 * @see time.h
 */
#define ev_date(e) (e)->datetime

/**
 * Get the location of an event.
 * @param e a pointer to the event
 * @return The location (char *)
 */
#define ev_loc(e) (e)->loc

/**
 * Get the description of an event.
 * @param e a pointer to the event
 * @return The description (char *)
 */
#define ev_desc(e) (e)->description

/**
 * Get the sponsors of an event.
 * @param e a pointer to the event
 * @return The sponsor (char **)
 */
#define ev_sponsors(e) (e)->sponsors

/**
 * Get the location of an event's associated image.
 * @param e a pointer to the event.
 * @return The location (char *)
 */
#define ev_image_loc(e) (e)->image

/**
 * Get the speaker at an event.
 * @param e a pointer to the event.
 * @return The speaker (char *)
 */
#define ev_speaker(e) (e)->speaker

#endif /* CONF_EVENT_H_ */
