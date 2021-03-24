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
	va_list list; /* se declara para acceder a los argumentos sin nombre */

	if (!format) /*si no es ninguno de los formatos retorna -1 (error)*/
	{
		return (-1);
	}

	va_start(list, format); /*utilizamos la macro va_start para inicializar la variable list*/
	for (i = 0; format[i] != '\0'; i++) /*recorremos los datos de la estructura*/
	{
		if (format[i] == '%') /* si formato tiene el porcentaje ejecuta lo siguiente: */
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
				count += (get_type_func(format[i + 1]))(list); /* si encuentra el caracter dentro de list llama a la funcion*/
				i++;
			}
			else
			{
				_putchar(format[i]); /* imprime el caracter dado y sigue buscando*/
				count++;
			}
		}
		else /* de lo contrario solo impriminos el caracter introducido */
		{
			_putchar(format[i]);
			count++;
		}
		
	}
	va_end(list);
	return (count);

}
