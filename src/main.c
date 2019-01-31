/*
 * Copyright © 2016 Seiji Hiraki
 * This file is a template for creating a new command.
 */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#include "debug.h"

/*
 * This function is entry point of this program.
 */
int main(int argc, char*argv[])
{
	char *param = NULL;
	int opt;

	check_debug_option();

	while ((opt = getopt(argc, argv, "ab:c::")) != -1) {
		switch (opt) {
		case 'a':
			break;
		case 'b':
			param = optarg;
			break;
		case 'c':
			param = optarg;
			break;
		default:
			printf("unknow option \'%c\' \'%c\'\n", opt, optopt);
			return 1;
		}
	}

	return 0;
}
