#include "holberton.h"

/**
 *print_char - prints char.
 *@c: argument to print
 *Return: 0 if the function is correct.
 */

int print_char(va_list c)
{
	char ch = (char)va_arg(c, int); /* va_arg devuelve el argumento actual */

	_putchar(ch);
	return (0);
}

int print_str(va_list s)
{
	char *str = va_arg(s, char *);
	int i;

	if (str == NULL)
	{
		str = "(null)";
	}

	for(i = 0; str[i]; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}

int print_dec(va_list n)
{
	long int num;
	int dig;
	int base;
	int count = 0;

	num = va_arg(n, int); /*Guarda el argumento actual en num*/

	if (num < 0)
	{
		num *= -1;
		_putchar('-');
		count++;
	}
	if (num <= 9 && num >= 0)
	{
		_putchar(num + 48);
		count++;
	}

	if (num > 9)
	{
		base = 10;

		while (num / base > 9)
		{
			base *= 10;
		}
		while (base > 0)
		{
			dig = num / base;
			num = num % base;
			_putchar(dig + 48);
			base = base / 10;
			count++;
		}
	}
	return (count);
}

/**
 *print_reverse - prints reversed argument.
 *@params: argument to print
 *Return: number of characters printed.
 */

int print_rev(va_list r)
{
	int i = 0;
	int count = 0;

	char *s_rev = va_arg(r, char *);

	if (s_rev == NULL)
	{
		s_rev = "(null)";
	}
	while (s_rev[i] != '\0')
	{
		i++;
		count++;
	}
	i--; /* la cadena recorre en reversa */

	while (i >= 0)
	{
		_putchar(s_rev[i]);
		i--;
	}
	return (count);
}
