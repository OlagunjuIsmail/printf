#include "main.h"
#include <stddef.h>
#include <stdlib.h>

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

/**
  * save_int - saves an integer to a given buffer
  * @buf: the buffer
  * @num: number to be saved
  * @len_buf: size of buf in bytes
  * Return: nothing
  */
void save_int(char *buf, int num, unsigned int len_buf)
{
	unsigned int i;

	if (num < 0)
	{
		*buf = '-';
		num *= -1;
		buf++;
		len_buf--;
	}

	for (i = 0; i < len_buf; i++)
	{
		*(buf + len_buf - i - 1) = (num % 10) + '0';
		num = num / 10;
	}
}

/**
  * len_int - finds the number of digits in an integer
  * @num: the integer
  * Return: length of num
  */
unsigned int len_int(int num)
{
	if (num / 10 == 0)
		return (1);

	return (len_int(num / 10) + 1);
}
