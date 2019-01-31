
#ifdef __linux
extern void __printf_ln(char* message,...);
extern void check_debug_option(void);
extern void check_debug_option(void);
#define __printf __printf_linux
#else
//#else if defined(__WIN32) || defined(__WIN64)

extern void __printf_win(char* message,...);
extern void check_debug_option(void);
#define __printf __printf_win
#endif

