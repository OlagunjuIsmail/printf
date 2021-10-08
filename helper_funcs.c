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
  * @buff: the buffer
  * @num: number to be saved
  * @len_buff: size of buf in bytes
  * Return: nothing
  */
char *save_int(char *buff, int num, unsigned int len_buff)
{
	unsigned int i;

	if (num < 0)
	{
		*buff = '-';
		num *= -1;
		buff++;
		len_buff--;
	}

	for (i = 0; i < len_buff; i++)
	{
		*(buff + len_buff - i - 1) = (num % 10) + '0';
		num = num / 10;
	}

	return (buff + len_buff - 1);
}

/**
  * save_uint - saves an unsigned integer to a given buffer
  * @buff: the buffer
  * @num: number to be saved
  * @len_buff: size of buf in bytes
  * Return: nothing
  */
char *save_uint(char *buff, unsigned int num, unsigned int len_buff)
{
	unsigned int i;

	for (i = 0; i < len_buff; i++)
	{
		*(buff + len_buff - i - 1) = (num % 10) + '0';
		num = num / 10;
	}

	return (buff + len_buff - 1);
}

/**
  * len_int - finds the number of digits in an integer
  * @num: the integer
  * Return: length of num
  */
unsigned int len_int(unsigned int num)
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
