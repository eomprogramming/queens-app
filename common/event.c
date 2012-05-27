/*
 * event.c - implements the event data code
 *
 * Copyright (c) 2012 by Ian Dewan
 *
 * This file, and the project of which it is a part, are made
 * available under the terms of the GNU GPL v.3. A copy of that
 * license should have come with the project, and it is
 * available at http://gnu.org/licenses
 */

#define _XOPEN_SOURCE 500

#include "conf-event.h"
#include "format.h"

#include <syslog.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

static int fill_event(struct event *ev, xmlNodePtr data);

struct event *read_event_list(const char *filename, int *num) {
	event_data_source *source;
	int event_count;
	struct event *event_list;
	struct event *under_construction;
	event_data current;
	char *iso_date = NULL;
	int tmp;

	source = new_event_source(filename);
	if (source == NULL)
		return NULL;

	event_count = count_events(source);
	if (event_count < 0)
		return NULL;
	if (event_count == 0) {
		syslog(LOG_WARN, "No events in data file %s.", filename);
		if (num != NULL)
			(*num) = 0;
		under_construction = (struct event *)
			malloc(sizeof(struct event));
		(*under_construction) = (struct event) {.title = NULL,
			.datetime = NULL, .loc = NULL, .description = NULL,
			.sponsors = NULL};
		return under_construction;
	}

	/* Allocate the array */
	event_list = (struct event *)
		malloc(sizeof(struct event) * (event_count + 1));

	if (event_list == NULL) {
		syslog(LOG_ERR, "Unable to allocate memory for event list.");
		return NULL;
	}

	/* Build the array */
	under_construction = event_list;

	while ((current = next_event(source)) != NULL) {
		under_construction->title = (char *) extract_data(current,
				NAME_DATA_TYPE);
		/* Title can never be NULL: if it is, warn and skip. */
		if (under_construction->title == NULL) {
			syslog(LOG_WARN, "Unable to get name of an event in"
					"file %s.", filename);
			continue;
		}
		under_construction->loc = (char *) extract_data(current,
				LOCATION_DATA_TYPE);
		under_construction->description = (char *) extract_data(current,
				DESCRIPTION_DATA_TYPE);
		under_construction->sponsors = (char **) extract_data(current,
				SPONSORS_DATA_TYPE);
		under_construction->image = (char *) extract_data(current,
				IMAGE_DATA_TYPE);
		iso_date = (char *) extract_data(current, DATETIME_DATA_TYPE);
		if (iso_date == NULL) {
			under_construction->datetime = NULL;
		} else {
			under_construction->datetime = (struct tm *)
				malloc(sizeof(struct tm));
			if (under_construction->datetime == NULL) {
				under_construction->datetime = NULL;
				under_construction++;
				continue;
			}
			strptime(iso_date, "%Y-%m-%dT%H:%M:%S",
				under_construction->datetime);
		}
		under_construction++;
	}

	/* Return the result */
	under_construction = (struct event *) malloc(sizeof(struct event));
	if (under_construction == NULL)
		return NULL;
	(*under_construction) = (struct event) {.title = NULL, .datetime =
		NULL, .loc = NULL, .description = NULL, .sponsors = NULL};
	if (num != NULL)
		*num = event_count;

	return event_list;
}
