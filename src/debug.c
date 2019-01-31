/*
 * Copyright © 2016 Seiji Hiraki
 * This file is a template for creating a new command.
 */
//#if defined(__WIN32) || defined(__WIN64)
#ifndef __linux
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "debug.h"

void
check_debug_option(void)
{
	/* nothing to do! */
	return;
}

/*
 * This function is print log to stderr or stdoutput.
 */
void
__printf_win(char* message,...)
{
	va_list ap;
	va_start(ap, message);
	vfprintf(stderr, message, ap);
	va_end(ap);
}

#endif
