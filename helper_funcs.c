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

/**
  * hex - returns the appropriate letter for hexadecimal conversion
  * @num: number to convert to letter (10 to 15)
  * @flag: specify whether to return upper or lowercase letters
  * Return: a char equivalent of num
  */
char hex(unsigned int num, char flag)
{
	int i;
	char c;
	char cs[12] = {'A', 'B', 'C', 'D', 'E', 'F', 'a', 'b', 'c', 'd', 'e', 'f'};
	unsigned int nums[6] = {10, 11, 12, 13, 14, 15};

	for (i = 0; i < 6; i++)
	{
		if (num == nums[i])
		{
			if (flag == 'X')
				c = cs[i];
			else
				c = cs[i + 6];
		}
	}
	return (c);
}
