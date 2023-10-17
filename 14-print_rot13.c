#include "main.h"

/**
 * print_rot13 - a function that handles the specifier R.
 * @args: is a pointer to the argument to be formatted.
 * @b: is a pointer to a structure for a buffer.
 * @val: is a structure holding info about the specifiers given by the user.
 *
 * Description: it encrypts a string using rot13.
 * Return: the number of characters of the processed formated string.
 */
int print_rot13(va_list *args, Buffer *b, formatSpecifier val)
{
	int count = 0;
	char *s = va_arg(*args, char *);

	(void) val;

	if (!s)
		s = "(ahyy)";

	for ( ; *s; ++count, ++s)
	{
		print_buffer(b);

		if (*s >= 'a' && *s <= 'z')
			b->buf[b->index++] = 'a' + (*s - 'a' + 13) % 26;
		else if (*s >= 'A' && *s <= 'Z')
			b->buf[b->index++] = 'A' + (*s - 'A' + 13) % 26;
		else
			b->buf[b->index++] = *s;
	}

	return (count);
}
