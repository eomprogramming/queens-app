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

#include <event.h>

#include <syslog.h>
#include <libxml/parser.h>


struct event **read_event_list(const char *filename, int *num) {
	xmlDocPointer doc;
	xmlNodePointer root;

	doc = xmlParseFile(filename);

	if (doc == NULL) {
		syslog(LOG_ERR, "Error parsing or locating file: %s", filename);
		return NULL;
	}

	if(xmlStrcmp(root->name, (const xmlChar *) "conference")) {
		syslog(LOG_ERR, "The event file (%s) had an invalid root"
			       "element: %s", filename, root->name);
		xmlDocFree(doc);
		return NULL;
	}
}
