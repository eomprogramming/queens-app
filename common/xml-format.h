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

#include <libxml/parser.h>

/**
 * The number of *_DATA_TYPE data types that can be extracted from an
 * event_data.
 */
#define NUM_DATA_TYPES 6

/**
 * Data type tag to get the name of an event.
 * extract_data() will return a char *.
 */
#define NAME_DATA_TYPE 0
/**
 * Data type tag to get the location of an event.
 * extract_data() will return a char *.
 */
#define LOCATION_DATA_TYPE 1
/**
 * Data type tag to get the description of an event.
 * extract_data() will return a char *.
 */
#define DESCRIPTION_DATA_TYPE 2
/**
 * Data type tag to get the sponsors of an event.
 * extract_data() will return a char **.
 */
#define SPONSORS_DATA_TYPE 3
/**
 * Data type tag to get the time and date of an event.
 * extract_data() will return a char *.
 */
#define DATETIME_DATA_TYPE 4
/**
 * Data type tag to get the location of the associated image of an event.
 * extract_data() will return a char *.
 */
#define IMAGE_DATE_TYPE 5

/**
 * An internal representation of a place from which to extract data about
 * events. It is an opaque type: no peeking!
 */
typedef struct {
	xmlDocPtr d; // The xml document
	xmlNodePtr n; // The root node of said document
	xmlNodePtr c; // The current event node for next event
} event_data_source;

/**
 * An internal representation of one event in raw form. It is an opaque type.
 */
typedef xmlNodePtr event_data;

/**
 * Create a new event source from a file.
 * @param filename the name of the event data file
 * @return a new data source, or NULL on error
 */
event_data_source *new_event_source(const char *filename);

/**
 * Free resources associated with a data source. The data source should not be
 * used after a call to this function.
 * @param e the data source to free
 */
void free_event_source(event_data_source *e);

/**
 * Count the number of events available  from a given source.
 * @param e the source to count.
 * @return The number of events, or -1 on error
 */
int count_events(const event_data_source *e);

/**
 * Cycle through the individual events available in the given event source.
 * @param e The event source to cycle through.
 * @return The next event_data, or NULL if the last has been reached.
 */
event_data next_event(event_data_source *e);

/**
 * Reset the next_event cycle to the first element.
 * @param e The event_data_source to reset.
 * @see next_event(), #event_data
 */
void reset_event_source(event_data_source *e);

/**
 * Extract the data of the given data type from the given event_data. The return
 * value should be cast to the type indicated in the *_DATA_TYPE define passed
 * as data_type.
 * @param e The event_data to extract from.
 * @param data_type The data to extract (one of the *_DATA_TYPE defines)
 * @return The value of the event_data, or NULL on error.
 * @see #NAME_DATA_TYPE
 * 	#LOCATION_DATA_TYPE
 * 	#DESCRIPTION_DATA_TYPE
 * 	#SPONSORS_DATA_TYPE
 * 	#DATETIME_DATA_TYPE
 */
void *extract_data(const event_data *e, unsigned int data_type);

#endif /* FORMAT_H_ */
