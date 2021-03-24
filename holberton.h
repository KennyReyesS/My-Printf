#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdio.h>
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
int print_char(va_list c);
int print_str(va_list s);
int print_dec(va_list n);
int print_rev(va_list r);

#endif
