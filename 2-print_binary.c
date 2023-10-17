#include "main.h"

/**
 * print_binary - a function that handles specifier b.
 * @args: is a pointer to the argument to be formatted.
 * @b: is a pointer to a structure for a buffer.
 * @val: is a structure holding info about the specifiers given by the user.
 *
 * Description: this function turns integers to binary numbers.
 * Return: the number of characters of the processed formated string.
 */
int print_binary(va_list *args, Buffer *b, formatSpecifier val)
{
	char t_buf[40];
	int i = 0, count;
	unsigned int n = va_arg(*args, unsigned int);

	if (n == 0)
		t_buf[i++] = '0';
	for ( ; n != 0; n >>= 1)
		t_buf[i++] = (n & 1) + '0';

	if (val.flag & HASH)
	{
		t_buf[i++] = 'b';
		t_buf[i++] = '0';
	}

	count = i;
	for (--i; i >= 0; --i)
	{
		print_buffer(b);
		b->buf[b->index++] = t_buf[i];
	}

	return (count);
}
