#include "../main.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int main(void)
{
	int len1, len2, len3;

	len1 = _printf("%d + %i = %d\n", 5, 5, (55 + 5));
	len2 = _printf("%d + %i = %d\n", -605, 434, (-605 + 434));
	len3 = _printf("98(2): %b, 98(8): %o\n", 98, 98);
	_printf("len1: %i, len2: %d, len3: %u\n", len1, len2, -10);
	printf("Len: %u %i 250(8): %x or %d\n", -10, 54, 250, len3);
	/*int len;
	len = _printf("%d and\n", 25485);
	printf("%d\n", len);*/

	return (0);
}
