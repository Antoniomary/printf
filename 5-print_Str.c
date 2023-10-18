#include "main.h"

/**
 * print_Str - a function that handles specifier S.
 * @args: is a pointer to the argument to be formatted.
 * @b: is a pointer to a structure for a buffer.
 * @val: is a structure holding info about the specifiers given by the user.
 *
 * Description: Non printable characters (0 < ASCII value < 32 or >= 127) are
 * printed this way: \x, followed by the ASCII code value in hexadecimal (upper
 * case - always 2 characters).
 * Return: the number of characters of the processed formated string.
 */
int print_Str(va_list *args, Buffer *b, formatSpecifier val)
{
	char *s = va_arg(*args, char *);
	int count = 0;

	(void) val;

	if (!s)
		s = "(null)";

	for ( ; *s; ++s)
	{
		if (*s >= 32 && *s <= 126)
		{
			print_buffer(b);
			b->buf[b->index++] = *s;
			++count;
			continue;
		}

		if (b->index >= BUF_SIZE - 4)
			flush_buffer(b);

		b->buf[b->index++] = '\\';
		b->buf[b->index++] = 'x';
		b->buf[b->index++] = Hex_map(*s / 16u);
		b->buf[b->index++] = Hex_map(*s % 16u);
		count += 4;
	}

	return (count);
}
