/*
 * Copyright © 2016 Seiji Hiraki
 * This file is a template for creating a new command.
 */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

static int debug_option = 0;

/*
 * This function is check debug-mode from environment
 */
static void 
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
static void
__printf(char* message,...)
{
	struct timespec tp;
	unsigned int time;

  va_list ap;
 
  if (debug_option) {
	  clock_gettime(CLOCK_REALTIME, &tp);
	  time = (tp.tv_sec * 1000000L) + (tp.tv_nsec / 1000);

    va_start(ap, message);
	  fprintf(stderr, "[%10.3f] ", time / 1000.0);
    vfprintf(stderr, message, ap)
	  fprintf(stderr, ")\n");
    va_end(ap);
  }
}

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
