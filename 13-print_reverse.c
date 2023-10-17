#include "main.h"

/**
 * print_reverse - a function that handles the specifier r.
 * @args: is a pointer to the argument to be formatted.
 * @b: is a pointer to a structure for a buffer.
 * @val: is a structure holding info about the specifiers given by the user.
 *
 * Description: it reverses a string.
 * Return: the number of characters of the processed formated string.
 */
int print_reverse(va_list *args, Buffer *b, formatSpecifier val)
{
	int i, count = 0;
	char *s = va_arg(*args, char *);

	(void) val;

	if (!s)
		s = ")llun(";

	for (i = 0; s[i] != '\0'; ++i)
		;

	count = i;

	for (--i; i >= 0; --i)
	{
		print_buffer(b);

		b->buf[b->index++] = s[i];
	}

	return (count);
}
