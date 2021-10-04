#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
  * _printf - prints any number of args based on a format string
  * @format: the format string
  * Return: the number of characters printed
  */
int _printf(const char *format, ...)
{
	int n_char;
	char c;
	va_list ap;

	n_char = 0;
	va_start(ap, format);
	if (format == NULL)
		return (n_char);

	while (*format != 0)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(ap, int);
					n_char += print_char(&c);
					break;
				case 's':
					n_char += print_str(va_arg(ap, char *));
					break;
				case '%':
					c = '%';
					n_char += write(1, &c, 1);
					break;
			}

		}
		else
			n_char += write(1, format, 1);
		format++;
	}

	return (n_char);
}

/**
  * print_char - writes a char to stdout
  * @c: the char
  * Return: number of char printed = 1
  */
int print_char(char *c)
{
	if (c == NULL)
		return (0);
	return (write(1, c, 1));
}

/**
  * print_str - writes a string to stdout
  * @s: the string
  * Return: the number of chars written
  */
int print_str(char *s)
{
	if (s == NULL || *s == 0)
		return (0);
	return (write(1, s, len(s)));
}

/**
  * len - finds the length of a string
  * @s: the string
  * Return: length of s
  */
int len(char *s)
{
	if (s == NULL || *s == 0)
		return (0);
	return (len(s + 1) + 1);
}
