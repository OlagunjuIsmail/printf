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
					n_char += print_char(c);
					break;
				case 's':
					n_char += print_str(va_arg(ap, char *));
					break;
				case 'd': case 'i': case 'u':
					n_char += print_int(va_arg(ap, int));
					break;
				case 'b':
					n_char += print_base(va_arg(ap, unsigned int), 2, '0', 0);
					break;
				case 'o':
					n_char += print_base(va_arg(ap, unsigned int), 8, '0', 0);
					break;
				case 'x':
					n_char += print_base(va_arg(ap, unsigned int), 16, 'x', 0);
					break;
				case 'X':
					n_char += print_base(va_arg(ap, unsigned int), 16, 'X', 0);
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
