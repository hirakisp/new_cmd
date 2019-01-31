
#ifdef __linux
#define __printf __printf_linux
extern void check_debug_option(void);
#else
//#else if defined(__WIN32) || defined(__WIN64)
#define __printf __printf_win
extern void check_debug_option(void);
#endif

