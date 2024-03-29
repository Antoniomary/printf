#include "main.h"

/**
 * print_char - a function that handles specifier c.
 * @args: is a pointer to the argument to be formatted.
 * @b: is a pointer to a structure for a buffer.
 * @val: is a structure holding info about the specifiers given by the user.
 *
 * Description: it handles the formatting of a single character.
 * Return: the number of characters of the processed formated string.
 */
int print_char(va_list *args, Buffer *b, formatSpecifier val)
{
	int i;
	char *pad = NULL;
	char c = (char) va_arg(*args, int);

	if (val.width > 1)
	{
		pad = alloc(val.width);
		if (pad)
		{
			charcpy(pad, ' ', 0, val.width);
			if (val.flag & MINUS)
				pad[0] = c;
			else
				pad[val.width - 1] = c;
		}
		else
			return (0);
	}
	else
	{
		val.width = 1;
		pad = alloc(val.width);
		pad[0] = c;
	}

	for (i = 0; i < val.width; ++i)
	{
		print_buffer(b);
		b->buf[b->index++] = pad[i];
	}

	free(pad);

	return (val.width);
}

/**
 * print_str - a function that handles specifier s.
 * @args: is a pointer to the argument to be formatted.
 * @b: is a pointer to a structure for a buffer.
 * @val: is a structure holding info about the specifiers given by the user.
 *
 * Description: it handles the formatting of a string of characters.
 * Return: the number of characters of the processed formated string.
 */
int print_str(va_list *args, Buffer *b, formatSpecifier val)
{
	int count = 0, null = 0;
	char *pad = NULL, *ptr = NULL, *s = va_arg(*args, char *);

	if (!s)
		s = "(null)", null = 1;

	count = _strlen(s);
	ptr = alloc(count + 1);
	if (!ptr)
		exit(-1);
	s = _strncpy(ptr, 0, s, count);
	s[count] = '\0';

	if (val.precision >= 0 && val.precision < count)
		s[null ? (val.precision = 0) : val.precision] = '\0', count = val.precision;

	if (val.width > count)
	{
		pad = alloc(val.width + 1);
		if (!pad)
			return (free(ptr), 0);

		if (val.flag & MINUS)
		{
			s = _strncpy(pad, 0, s, count);
			charcpy(s, ' ', count, val.width);
		}
		else
		{
			charcpy(pad, ' ', 0, val.width - count);
			s = _strncpy(pad, val.width - count, s, count);
		}
		s[val.width] = '\0';
		count = val.width;
	}

	strcpy_to_buffer(s, b);
	_free(pad), _free(ptr);

	return (count);
}

/**
 * print_perc - a function that writes a literal percent to buffer.
 * @args: is a pointer to the argument to be formatted.
 * @b: is a pointer to a structure for a buffer.
 * @val: is a structure holding info about the specifiers given by the user.
 *
 * Description: it handles the printing of '%'.
 * Return: Always 1.
 */
int print_perc(va_list *args, Buffer *b, formatSpecifier val)
{
	(void) args;
	(void) val;

	print_buffer(b);

	b->buf[b->index++] = '%';

	return (1);
}
