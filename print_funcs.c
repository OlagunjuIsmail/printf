#include "main.h"
#include <unistd.h>

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
