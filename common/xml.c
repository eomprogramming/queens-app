/*
 * xml.c - implements xml parsing
 *
 * Copyright (c) 2012 by Ian Dewan
 *
 * This file, and the project of which it is a part, are made
 * available under the terms of the GNU GPL v.3. A copy of that
 * license should have come with the project, and it is
 * available at http://gnu.org/licenses
 */

#include "xml-format.h"
#include "xml.h"
#include "compat.h"

#include <stdlib.h>

#define ROOT_ELEMENT_NAME "event-list"
#define EVENT_ELEMENT_NAME "event"

#define IS_EVENT_ATTRIBUTE 0x01
#define LIST_OF_SUBELEMENT 0x02

static int count_subnodes(const xmlNodePtr n, const char * name);

static const struct {
	char *name;
	int flags;
	char *arg;
} format[NUM_DATA_TYPES] = {
	[NAME_DATA_TYPE] = {.name = "name", .flags = IS_EVENT_ATTRIBUTE},
	[LOCATION_DATA_TYPE] = {.name = "location", .flags = 0},
	[DESCRIPTION_DATA_TYPE] = {.name = "description", .flags = 0},
	[SPONSORS_DATA_TYPE] = {.name = "sponsors", .flags = LIST_OF_SUBELEMENT,
		.arg = "sponsor"},
	[DATETIME_DATA_TYPE] = {.name = "datetime", .flags = 0},
	[IMAGE_DATA_TYPE] = {.name = "image", .flags = 0},
	[SPEAKER_DATA_TYPE] = {.name = "speaker", .flags = 0},
};

event_data_source *new_event_source(const char *filename) {
	event_data_source *ret;

	ret = (event_data_source *) malloc(sizeof(event_data_source));
	if (ret == NULL) {
		syslog(LOG_ERR, "Error allocating memory at %i in %s.",
				__LINE__, __FILE__);
		return NULL;
	}

	ret->d = xmlParseFile(filename);
	if (ret->d == NULL) {
		syslog(LOG_ERR, "Error parsing or locating data file: %s",
				filename);
		return NULL;
	}

	ret->n = ret->d->children;
	if (!xml_isNode(ret->n, ROOT_ELEMENT_NAME)) {
		syslog(LOG_ERR, "Invalid root element name \"%s\" in file %s.",
				(char *)((ret->n->name == NULL)?"ERROR":ret->n->name), filename);
		return NULL;
	}

	ret->c = NULL;

	return ret;
}

void free_event_source(event_data_source *e) {
	xmlFreeDoc(e->d);
	free(e);
}

int count_events(const event_data_source *e) {
	return count_subnodes(e->n, EVENT_ELEMENT_NAME);
}

event_data next_event(event_data_source *e) {
	if (e->c == NULL) {
		e->c = e->n->children;
		if (xml_isNode(e->c, EVENT_ELEMENT_NAME))
			return e->c;
	}

	while(xml_nextNode(e->c)) {
		if (xml_isNode(e->c, EVENT_ELEMENT_NAME))
			return e->c;
	}

	return NULL;
}

void reset_event_source(event_data_source *e) {
	e->c = NULL;
}

void *extract_data(const event_data e, unsigned int data_type) {
	xmlNodePtr cur;
	xmlNodePtr cur2;
	char **array_result = NULL;
	char *result = NULL;
	int i;

	if (data_type >= NUM_DATA_TYPES) {
		syslog(LOG_WARNING, "Bad data type passed to extract_data: %i",
				data_type);
		return NULL;
	}

	if (format[data_type].flags & LIST_OF_SUBELEMENT) {
		cur = e->children;
		do {
			if (!xml_isNode(cur, format[data_type].name))
				continue;
			cur2 = cur->children;
			array_result = (char **) malloc(sizeof(char *) *
				(count_subnodes(cur, format[data_type].arg)
				+ 1));
			if (array_result == NULL) {
				syslog(LOG_ERR, "Error in allocating space to"
					"hold %s data from file %s.",
					format[data_type].name, e->doc->name);
				return NULL;
			}
			for (i = 0; xml_nextNode(cur2); i++) {
				if(!xml_isNode(cur2, format[data_type].arg)) {
					i--; // reset counter
					continue;
				}
				array_result[i] = xml_getStrd(cur2);
			}
			array_result[i] = NULL;
			return (void *)array_result;
		} while (xml_nextNode(cur));	
	} else if (format[data_type].flags & IS_EVENT_ATTRIBUTE) {
		return (void *) xml_nodeProp(e, format[data_type].name);
	} else {
		cur = e->children;
		do {
			xmlr_str(cur, format[data_type].name, result);
		} while (xml_nextNode(cur));
		return result;
	}
}

static int count_subnodes(const xmlNodePtr n, const char * name) {
	xmlNodePtr cur;
	int count = 0;

	cur = n->children;

	do {
		if(xml_isNode(cur, name))
			count++;
	} while (xml_nextNode(cur));

	return count;
}
