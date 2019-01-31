/*
 * Copyright © 2016 Seiji Hiraki
 * This file is a template for creating a new command.
 */
#ifdef __linux

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#include <pthread.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include "debug.h"

static int debug_option = 0;

static pid_t
gettid(void)
{
	return syscall(SYS_gettid);
}

/*
 * This function is check debug-mode from environment
 */
void
check_debug_option(void)
{
	const char *debug;
	debug = getenv("MY_XXX_DEBUG");
	if (debug && (strstr(debug, "xxx") || strstr(debug, "1")))
		debug_option = 1;
}

/*
 * This function is print log to stderr or stdoutput.
 */
void
__printf(char* message,...)
{
	struct timespec tp;
	unsigned int time;
	va_list ap;

	if (!debug_option)
		return;

	clock_gettime(CLOCK_REALTIME, &tp);
	time = (tp.tv_sec * 1000000L) + (tp.tv_nsec / 1000);

	va_start(ap, message);
	fprintf(stderr, "[%10.3f] ", time / 1000.0);
	vfprintf(stderr, message, ap);
	va_end(ap);

	va_start(ap, message);
	vfprintf(stderr, message, ap);
	va_end(ap);

	return;
}
#endif
