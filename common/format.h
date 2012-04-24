/**
 * @file format.h
 * Definitions of the format of the XML data files
 */
/* Copyright (c) 2012 by Ian Dewan
 *
 * This file, and the project of which it is a part, are made
 * available under the terms of the GNU GPL v.3. A copy of that
 * license should have come with the project, and it is
 * available at http://gnu.org/licenses
 */

#ifndef FORMAT_H_
#define FORMAT_H_

/**
 * The name of the root element in a file.
 */
#define ROOT_ELEMENT_NAME "event-list"

/**
 * The name of the element that represents one event's data.
 */
#define EVENT_ELEMENT_NAME "event"

/**
 * The name of the attribute (of an event node) that contains the name of the
 * event.
 */
#define NAME_ATTRIBUTE_NAME "name"

/**
 * The name of the element that represents an event's location.
 */
#define LOCATION_ELEMENT_NAME "location"

/**
 * The name of the element that represents an event's description.
 */
#define DESC_ELEMENT_NAME "description"

/**
 * The name of the element that represents an event's sponsor.
 */
#define SPONSOR_ELEMENT_NAME "sponsor"

/**
 * The name of the element that represents an event's date and time.
 */
#define DATE_ELEMENT_NAME "datetime"

#endif /* FORMAT_H_ */
