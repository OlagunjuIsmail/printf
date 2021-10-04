#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int print_char(int n_char, char c);
int print_str(int n_char, char *s);
int len(char *s);
/**
  * _printf - prints any number of args based on a format string
  * @format: the format string
  * Return: the number of characters printed
  */
int _printf(const char *format, ...)
{
	int n_char;
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
					n_char += print_char(n_char, va_arg(ap, int));
					break;
				case 's':
					n_char += print_str(n_char, va_arg(ap, char *));
					break;
			}
		}
		format++;
	}

	return (n_char);
}

int print_char(int n_char, char c)
{
	n_char += write(1, &c, 1);
	return (n_char);
}

int print_str(int n_char, char *s)
{
	n_char += write(1, s, len(s));

	return (n_char);
}

int len(char *s)
{
	if (s == NULL || *s == 0)
		return (0);
	return (len(s + 1) + 1);
}
