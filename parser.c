#include "main.h"

/**
 * parser - a function that parses the arguments passed as format specifier.
 * @args: is a pointer to the argument to be formatted.
 * @b: is a pointer to a structure for a buffer.
 * @format: is a double pointer to string character given by the user.
 *.
 * Return: it calls the right function to the format specifier passed by user
 * which in turn returns the number of proccessed character; else 0
 */
int parser(va_list *args, Buffer *b, const char **format)
{
	formatSpecifier val = {0, 0, -1, 0};
	formatHandler fmt[] = {
	{'c', print_char}, {'s', print_str},
	{'%', print_perc}, {'d', print_int},
	{'i', print_int}, {'b', print_binary},
	{'u', print_uint}, {'o', print_octal},
	{'x', print_hex}, {'X', print_HEX},
	{'S', print_Str}, {'p', print_addr},
	{'r', print_reverse}, {'R', print_rot13}
	};
	int i, ret = 0;

	/* gets the flags used if any */
	for (i = 0; isflag(*(*format)); ++(*format))
		val.flag |= isflag(*(*format));

	/* gets the width given if any */
	if (_isdigit(*(*format)))
		val.width = get_width(args, format);

	/* get the precision given if any */
	if (*(*format) == '.')
		++(*format), val.precision = get_precision(args, format);

	/* gets the length modifier given if any */
	(val.len_mod = get_length(*(*format))) ? ++(*format) : *format;

	/* gets the data type to format */
	for (i = 0; i < 14; ++i)
		if (*(*format) == fmt[i].spec)
			return (++(*format), fmt[i].func(args, b, val));

	/* handles printing for unknown specifiers */
	if (*(*format) != '\0')
		ret += print_literal(b, val);
	else
		ret = -1;

	return (ret);
}
