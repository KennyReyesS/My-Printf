#include "holberton.h"

int (*get_type_func(const char k))(va_list)
{
	int j;

	data_t array[] = {
		{"c", print_char},
		{"s", print_str},
		{"d", print_dec},
		{"i", print_dec},
		{"r", print_rev},
		{NULL, NULL}
	};

	for (j = 0; array[j].type != NULL; j++)
	{
		if (*array[j].type == k)
		{
			return (array[j].f);
		}
	}
	return (0);
}

/**
 * _printf - output according to a format.
 * @format: is a character string.
 * Return: On success 1.
 * On error, -1 is returned.
 */

int _printf(const char *format, ...)
{
	unsigned int i = 0;
	unsigned int count = 0;
	va_list list;

	if (!format)
	{
		return (-1);
	}

	va_start(list, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				return(-1);
			}
			else if (format[i + 1] == '%')
			{
				_putchar('%');
				count++;
				i++;
			}
			else if (get_type_func(format[i + 1]) != NULL)
			{
				count += (get_type_func(format[i + 1]))(list);
				i++;
			}
			else
			{
				_putchar(format[i]);
				count++;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		
	}
	va_end(list);
	return (count);

}
