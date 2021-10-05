#include "../main.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	int len1, len2, len3;

	len1 = _printf("%d + %i = %d\n", "str", 5, (55 + 5));
	len2 = _printf("%d + %i = %d\n", -605, 434, (-605 + 434));
	len3 = _printf("98(2): %b, 98(8): %o\n", 98, 98);
	_printf("len1: %i, len2: %d, len3: %d\n", len1, len2, len3);
	printf("Len: %u %u %x\n", len_int(60), 54, 15);
	_printf("%x, %X\n", 2777, 2777);
	return (0);
}
