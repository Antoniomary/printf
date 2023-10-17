#include "main.h"

/**
 * get_length - a function that checks for length modifier in format.
 * @c: the character to check.
 *
 * Return: the length modifier itself else 0 if it is not
 */
int get_length(char c)
{
	return ((c == 'l' || c == 'h') ? c : 0);
}

/**
 * get_width - a function that gets the width argument passed in format.
 * @args: is a pointer to the argument to be formatted.
 * @c: double pointer to supposed supplied width (an int).
 *
 * Return: the width.
 */
int get_width(va_list *args, const char **c)
{
	int width = 0;
	int d;

	if (*(*c) == '*')
	{
		++(*c);
		return (va_arg(*args, int));
	}

	for ( ; _isdigit(*(*c)) != -1; ++(*c))
	{
		d = _isdigit(*(*c));
		width = width * 10 + d;
	}

	return (width);
}

/**
 * get_precision - a function that gets the precision value passed in format.
 * @args: is a pointer to the argument to be formatted.
 * @c: double pointer to supposed supplied precision (an int).
 *
 * Return: the precision.
 */
int get_precision(va_list *args, const char **c)
{
	int d, precision = 0;

	if (*(*c) == '*')
	{
		++(*c);
		return (va_arg(*args, int));
	}

	for ( ; _isdigit(*(*c)) != -1; ++(*c))
	{
		d = _isdigit(*(*c));
		precision = precision * 10 + d;
	}

	return (precision);
}
