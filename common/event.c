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
#include "xml.h"

#include <syslog.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <libxml/parser.h>

static int fill_event(struct event *ev, xmlNodePtr data);

struct event *read_event_list(const char *filename, int *num) {
	xmlDocPtr doc;
	xmlNodePtr root;
	xmlNodePtr cur_event;
	int event_count = 0;
	struct event *event_list;
	struct event *under_construction;
	int tmp;

	/* Parse the document */
	doc = xmlParseFile(filename);

	if (doc == NULL) {
		syslog(LOG_ERR, "Error parsing or locating file: %s", filename);
		return NULL;
	}

	/* Check for the right root node */
	if(xml_isNode(root, ROOT_ELEMENT_NAME)) {
		syslog(LOG_ERR, "The event file (%s) had an invalid root"
			       "element: %s", filename, root->name);
		xmlFreeDoc(doc);
		return NULL;
	}

	/* Count the nodes */
	cur_event = root->children;

	while (cur_event != NULL) {
		if (xml_isNode(cur_event, EVENT_ELEMENT_NAME))
			event_count++;
		cur_event = cur_event->next;
	}
	
	if (event_count == 0) {
		syslog(LOG_WARNING, "No entries in list of events; file: %s", filename);
		if (num != NULL)
			*num = 0;
		return NULL;
	}

	/* Allocate the array */
	event_list = (struct event *) malloc(sizeof(struct event) * event_count + 1);

	if (event_list == NULL) {
		syslog(LOG_ERR, "Unable to allocate memory for event list.");
		return NULL;
	}

	/* Build the array */
	cur_event = root->children;
	under_construction = event_list;

	while (cur_event != NULL) {
		if (xml_isNode(cur_event, EVENT_ELEMENT_NAME)) {
			tmp = fill_event(under_construction, cur_event);
			if (tmp == 0)
				under_construction++;
		}
		cur_event = cur_event->next;
	}

	/* Return the result */
	under_construction = malloc(sizeof(struct event));
	if (under_construction == NULL)
		return NULL;
	(*under_construction) = (struct event) {.title = NULL, .datetime =
		NULL, .loc = NULL, .description = NULL, .sponsors = NULL};
	if (num != NULL)
		*num = event_count + 1;

	return event_list;
}

/**
 * Fill an event with data from the given xml event node.
 * @param ev the event to fill
 * @param data the node pointer to fillit from
 * @return 0 on success, 1 for a loose nut behind the wheel, 2 for a malformed
 * xml structure, >2 for any other error.
 */
static int fill_event(struct event *ev, xmlNodePtr data) {
	xmlNodePtr n;
	char *iso_date = NULL;

	/* Check for bad programmers */
	if ((ev == NULL) || (data == NULL)) {
		return 1;
	}

	/* Get the title */
	ev->title = xml_nodeProp(data, NAME_ATTRIBUTE_NAME);

	/* Get the contents */
	n = data->children;

	while (xml_nextNode(n)) {
		xmlr_strd(n, LOCATION_ELEMENT_NAME, ev->loc)
		xmlr_strd(n, DESC_ELEMENT_NAME, ev->description)
		xmlr_strd(n, SPONSOR_ELEMENT_NAME, ev->sponsors)
		xmlr_strd(n, DATE_ELEMENT_NAME, iso_date)
	}

	if (iso_date == NULL) {
		ev->datetime = NULL;
	} else {
		ev->datetime = (struct tm *) malloc(sizeof(struct tm));
		if (ev->datetime == NULL)
			return 3;
		strptime(iso_date, "%Y-%m-%dT%H:%M:%S", ev->datetime);
	}

	return 0;
}
