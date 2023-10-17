#include "main.h"

/**
 * print_uint - a function that handles specifier u.
 * @args: is a pointer to the argument to be formatted.
 * @b: is a pointer to a structure for a buffer.
 * @val: is a structure holding info about the specifiers given by the user.
 *
 * Description: it handles the formatting of unsigned integers(base10).
 * Return: the number of characters of the processed formated string.
 */
int print_uint(va_list *args, Buffer *b, formatSpecifier val)
{
	char temp[30], *num = NULL, *(pad)[] = {NULL, NULL};
	unsigned long n = va_arg(*args, unsigned long);
	int c = ' ', len = 0;

	len = itoa_reverse(temp, 0, n, 'u', 10);
	num = temp;

	if (val.precision > len)
	{
		pad[0] = alloc(val.precision);
		if (!pad[0])
			return (0);

		len = handle_precision(&num, len, pad[0], val.precision);
	}

	if (val.width > len)
	{
		pad[1] = alloc(val.width);
		if (!pad[1])
			return (_free(pad[0]));

		if ((val.precision == -1) && (val.flag & ZERO))
			c = '0';

		len = handle_width(&num, len, pad[1], val.width, val.flag, c);
	}

	rev_strcpy_to_buffer(num, len, b);

	_free(pad[0]);
	_free(pad[1]);

	return (len);
}

/**
 * print_octal - a function that handles specifier o.
 * @args: is a pointer to the argument to be formatted.
 * @b: is a pointer to a structure for a buffer.
 * @val: is a structure holding info about the specifiers given by the user.
 *
 * Description: it handles the formatting of a base10 int to base8.
 * Return: the number of characters of the processed formated string.
 */
int print_octal(va_list *args, Buffer *b, formatSpecifier val)
{
	char temp[30], *num = NULL, *(pad)[] = {NULL, NULL};
	unsigned long n = va_arg(*args, unsigned long);
	int c = ' ', len = 0;

	len = itoa_reverse(temp, 0, n, 'u', 8);
	num = temp;

	if (val.flag & HASH)
		num[len++] = '0';

	if (val.precision > len)
	{
		pad[0] = alloc(val.precision);
		if (!pad[0])
			return (0);

		len = handle_precision(&num, len, pad[0], val.precision);
	}

	if (val.width > len)
	{
		pad[1] = alloc(val.width);
		if (!pad[1])
			return (_free(pad[0]));

		if ((val.precision == -1) && (val.flag & ZERO))
			c = '0';

		len = handle_width(&num, len, pad[1], val.width, val.flag, c);
	}

	rev_strcpy_to_buffer(num, len, b);

	_free(pad[0]);
	_free(pad[1]);

	return (len);
}

/**
 * print_hex - a function that handles specifier x.
 * @args: is a pointer to the argument to be formatted.
 * @b: is a pointer to a structure for a buffer.
 * @val: is a structure holding info about the specifiers given by the user.
 *
 * Description: handles the foarmatting of a base10 int to base16 (lower case).
 * Return: the number of characters of the processed formated string.
 */
int print_hex(va_list *args, Buffer *b, formatSpecifier val)
{
	char temp[30], *num = NULL, *(pad)[] = {NULL, NULL};
	unsigned long n = va_arg(*args, unsigned long);
	int c = ' ', len = 0;

	len = itoa_reverse_base_16(temp, n, 'x');
	num = temp;

	if (val.precision > len)
	{
		pad[0] = alloc(val.precision + 2);
		if (!pad[0])
			return (0);

		len = handle_precision(&num, len, pad[0], val.precision);
	}

	if (val.flag & HASH)
	{
		num[len++] = 'x';
		num[len++] = '0';
	}

	if (val.width > len)
	{
		pad[1] = alloc(val.width);
		if (!pad[1])
			return (_free(pad[0]));

		if ((val.precision == -1) && (val.flag & ZERO))
			c = '0';

		len = handle_width(&num, len, pad[1], val.width, val.flag, c);
	}

	rev_strcpy_to_buffer(num, len, b);
	_free(pad[0]);
	_free(pad[1]);

	return (len);
}

/**
 * print_HEX - a function that handles specifier X.
 * @args: is a pointer to the argument to be formatted.
 * @b: is a pointer to a structure for a buffer.
 * @val: is a structure holding info about the specifiers given by the user.
 *
 * Description: handles the formatting of base10 int to base16 (upper case).
 * Return: the number of characters of the processed formated string.
 */
int print_HEX(va_list *args, Buffer *b, formatSpecifier val)
{
	char temp[30], *num = NULL, *(pad)[] = {NULL, NULL};
	unsigned long n = va_arg(*args, unsigned long);
	int c = ' ', len = 0;

	len = itoa_reverse_base_16(temp, n, 'x');
	num = temp;

	if (val.precision > len)
	{
		pad[0] = alloc(val.precision + 2);
		if (!pad[0])
			return (0);

		len = handle_precision(&num, len, pad[0], val.precision);
	}

	if (val.flag & HASH)
	{
		num[len++] = 'X';
		num[len++] = '0';
	}

	if (val.width > len)
	{
		pad[1] = alloc(val.width);
		if (!pad[1])
			return (_free(pad[0]));

		if ((val.precision == -1) && (val.flag & ZERO))
			c = '0';

		len = handle_width(&num, len, pad[1], val.width, val.flag, c);
	}

	rev_strcpy_to_buffer(num, len, b);

	_free(pad[0]);
	_free(pad[1]);

	return (len);
}
