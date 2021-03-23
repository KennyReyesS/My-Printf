#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);

typedef struct data
{
	char *type;
	int (*f)(va_list);
} data_t;

int _putchar(char c);
int (*get_type_func(const char k))(va_list);
int print_char(va_list l);
int print_str(va_list s);
int print_dec(va_list n);
int print_rev(va_list r);

#endif
