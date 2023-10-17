#include "main.h"

/**
 * print_literal - a function that handles action for unknown format
 * specifiers.
 * @b: is a pointer to a structure for a buffer.
 * @val: is a structure holding info about the specifiers given by the user.
 *
 * Return: the number of characters of the processed formated string.
 */
int print_literal(Buffer *b, formatSpecifier val)
{
	int ret = print_perc(NULL, b, val);

	if (val.flag)
	{
		if (val.flag & PLUS)
		{
			print_buffer(b);
			++ret, b->buf[b->index++] = '+';
		}
		if (val.flag & MINUS)
		{
			print_buffer(b);
			++ret, b->buf[b->index++] = '-';
		}
		if (val.flag & SPACE && !(val.flag & PLUS || val.flag & MINUS))
		{
			print_buffer(b);
			++ret, b->buf[b->index++] = ' ';
		}
		if (val.flag & ZERO && !(val.flag & MINUS))
		{
			print_buffer(b);
			++ret, b->buf[b->index++] = '0';
		}
	}

	return (ret);
}
