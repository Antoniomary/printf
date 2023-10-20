#include "main.h"

/**
 * print_int - a function that handles specifier d and i.
 * @args: is a pointer to the argument to be formatted.
 * @b: is a pointer to a structure for a buffer.
 * @val: is a structure holding info about the specifiers given by the user.
 *
 * Description: it handles the formatting of base10 ints.
 * Return: the number of characters of the processed formated string.
 */
int print_int(va_list *args, Buffer *b, formatSpecifier val)
{
	char temp[30], *num = NULL, *(pad)[] = {NULL, NULL};
	long int n;
	int c, len = 0, sign, tmp;

	n = (val.len_mod == 'l') ? va_arg(*args, long int) : va_arg(*args, int);
	sign = (n < 0) ? 1 : 0;
	len = itoa_reverse(temp, n, 0, 's', 10);
	num = temp;

	if (val.precision > len)
	{
		pad[0] = alloc(val.precision + 1);
		if (!pad[0])
			return (0);
		len = handle_precision(&num, len, pad[0], val.precision);
	}
	else if (val.precision == 0 && n == 0)
		return (0);

	tmp = len;
	if (sign)
		num[len++] = '-';
	else if ((val.flag & PLUS) && !sign)
		num[len++] = '+';
	else if (val.flag & SPACE && !sign)
		num[len++] = ' ';

	if (val.width > len)
	{
		pad[1] = alloc(val.width);
		if (!pad[1])
			return (_free(pad[0]));
		c = (val.flag & ZERO) == ZERO ? '0' : ' ';
		len = handle_width(&num, len, pad[1], val.width, val.flag, c);
		if (c == '0' && (val.flag & PLUS || val.flag & SPACE || sign))
			c = num[tmp], num[tmp] = num[len - 1], num[len - 1] = c;
	}

	rev_strcpy_to_buffer(num, len, b);
	_free(pad[0]), _free(pad[1]);

	return (len);
}
