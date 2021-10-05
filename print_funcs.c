#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

/**
  * print_char - writes a char to stdout
  * @c: the char
  * Return: number of char printed = 1
  */
int print_char(char c)
{
	return (write(1, &c, 1));
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
  * print_int - writes an integer to stdout
  * @num: the integer
  * Return: number of digits written
  */
int print_int(int num)
{
	char *s;
	unsigned int len_s;
	int n_char;

	if (num < 0)
		len_s = len_int(num * -1) + 1;
	else
		len_s = len_int(num);

	s = malloc(sizeof(char) * len_s);
	if (s != NULL)
		save_int(s, num, len_s);

	n_char = write(1, s, len_s);
	free(s);
	return (n_char);
}

/**
  * print_base - prints the binary equivalent of a decimal
  * @num: the integer passed
  * @base: the base to be converted to
  * @n_char: number of chars printed
  * Return: number of digits printed
  */
int print_base(unsigned int num, unsigned int base, int n_char)
{
	char d;

	if (num / base == 0)
	{
		d = num + '0';
		return (write(1, &d, 1));
	}
	n_char += print_base(num / base, base, 0);
	d = (num % base) + '0';
	write(1, &d, 1);
	return (n_char + 1);
}
