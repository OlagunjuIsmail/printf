#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int len(char *s);
/**
  * _printf - prints any number of args based on a format string
  * @format: the format string
  * Return: the number of characters printed
  */
int _printf(const char *format, ...)
{
	int n_char;
	char *str, c;
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
					n_char += write(1, &c, 1);
					break;
				case 's':
					str = va_arg(ap, char *);
					n_char += write(1, str, len(str));
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
