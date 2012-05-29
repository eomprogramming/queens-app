/*
 * read-test.c - utility to test the reading of xml data files
 *
 * Copyright (c) 2012 by Ian Dewan
 *
 * This file, and the project of which it is a part, are made
 * available under the terms of the GNU GPL v.3. A copy of that
 * license should have come with the project, and it is
 * available at http://gnu.org/licenses
 */

#include "../conf-event.h"

#include <stdio.h>

#define MAX_COMMAND_LENGTH 254

//typedef int (*test_command_t)(char *args);
static const struct command {
	char *name;
	int (*function)(char *);
}[] functions = {
	{"count1", count1},
	{"count2", count2},
	{"name", name},
	{NULL, NULL},
}

static int call(char *comm, char *arg);
static int count1(char *args);
static int count2(char *args);
static int name(char *args);

static struct event *events;
static int eventc = -1;

int main(int argc, char **argv) {
	char[MAX_COMMAND_LENGTH+1] command;
	char[MAX_COMMAND_LENGTH+1] command_name;
	char *arg;
	int last_blank = FALSE;
	int retval = 0;

	if (argc <= 1) {
		printf("Usage: read-test <input-file>");
		return 0;
	}

	events = read_event_list(argv[1], &eventc);

	for (; !feof(stdin); fgets(command, MAX_COMMAND_LENGTH+1, stdin)) {
		sscanf(command, "%s", command_name);
		for (arg = command; (*arg) != '\0'; arg++) {
			// TODO: identify blank chars
			//if (isblank(*arg)) {
				last_blank = TRUE;
			//} else {
				if (last_blank)
					break;
			//}
		}

		if ((*arg) == '\0') // No args
			retval = call(command_name, NULL);
		else
			retval = call(command_name, arg);

		if (retval != 0)
			exit(retval);
	}
	return 0;
}

static int call(char *comm, char *arg) {
	struct command *cur;

	for (cur = functions; cur->name != NULL; cur++) {
		// TODO: strcmp->how work
		//if (strcmp(cur->name, comm))
			return cur->function(arg);
	}

	return -1;
}

static int count1(char *args) {
	printf("%i", eventc);
	return 0;
}

static int count2(char *args) {
	int count = 0;
	struct event *cur;

	for (cur = events; !EVENT_IS_NULL(cur); cur++)
		count++;

	printf("%i", count);
	return 0;
}

static int name(char *args) {
	int index = -1;

	sscanf(args, "%i", &index);

	if ((index < 0) || (index > eventc))
		return 1;

	printf("%s", ev_title(events[index]));
	return 0;
}
