#include "main.h"

/**
 * itoa_reverse - a function that converts integers to ascii in reverse order.
 * @rev: pointer to array to store result.
 * @num: the integer to convert.
 * @u_num: the integer to convert.
 * @opt: it is used to select the signness of the integer, num or u_num.
 * @base: the base to convert the integer to.
 *
 * Description: only works for bases below 11 i.e 2 - 10.
 * Return: the number of digits contained in the integer converted.
 */
int itoa_reverse(char *rev, long num, unsigned long u_num, int opt, int base)
{
	int len = 0;

	if (opt == 's')
	{
		(void) u_num;

		if (num == 0)
			rev[len++] = '0';

		for ( ; num != 0; num /= base)
			rev[len++] = _abs(num % base) + '0';
	}
	else /* opt == 'u' */
	{
		(void) num;

		if (u_num == 0)
			rev[len++] = '0';

		for ( ; u_num != 0; u_num /= base)
			rev[len++] = _abs(u_num % base) + '0';
	}

	return (len);
}

/**
 * itoa_reverse_base_16 - a function that converts integers to base 16.
 * @rev: pointer to array to store result.
 * @num: the integer to convert.
 * @opt: it is used to select the case for the mapping.
 *
 * Return: the number of digits contained in the integer converted.
 */
int itoa_reverse_base_16(char *rev, unsigned long num, int opt)
{
	int len = 0;

	if (num == 0)
		rev[len++] = '0';
	else
	{
		if (opt == 'x')
			for ( ; num != 0; num /= 16u)
				rev[len++] = hex_map(num % 16u);
		else /* opt == 'X' */
			for ( ; num != 0; num /= 16u)
				rev[len++] = Hex_map(num % 16u);
	}

	return (len);
}

/**
 * handle_precision - a function that handles the precision.
 * @old: double pointer to the unsigned int stored in a character array.
 * @len: the length of old.
 * @new: pointer to the new array where old will be copied to.
 * @precision: the number of characters to take from old.
 *
 * Return: Always the precision.
 */
int handle_precision(char **old, int len, char *new, int precision)
{
	*old = _strncpy(new, 0, *old, len);
	charcpy(*old, '0', len, precision);

	return (precision);
}

/**
 * handle_width - a function that handles the space a string should take.
 * @old: double pointer to a character array.
 * @len: the length of old.
 * @new: pointer to the new array where old will be copied to.
 * @w: the width that old should have now.
 * @flag: the flag to use.
 * @c: the character to use supplement when width is greater than len.
 *
 * Return: Always width.
 */
int handle_width(char **old, int len, char *new, int w, int flag, int c)
{
	if (flag & MINUS)
	{
		*old = _strncpy(new, w - len, *old, len);
		charcpy(*old, c, 0, w - len);
	}
	else
	{
		*old = _strncpy(new, 0, *old, len);
		charcpy(*old, c, len, w);
	}

	return (w);
}
