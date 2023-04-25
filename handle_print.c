#include "main.h"
/**
 * handle_print - parses what is an argument based on its type
 * @format: a character string.
 * @list: List of arguments to be printed.
 * @ind: index.
 * @buffer: an array to handle print.
 * @flags: calculates thr number of active flags
 * @width: get width.
 * @precision: specifies the precision.
 * @size: specifies the size.
 *
 * Return: the number of characters printed.
 */
int print_std(const char *format, int *ind, va_list list,
	char buffer[], int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, printed_chars = -1;
	fmt_t functions[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_bit},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hex},
		{'X', print_heX}, {'p', print_pointer}, {'S', print_unusual},
		{'r', rev_str}, {'R', print_rot13d}, {'\0', NULL}
	};
	for (i = 0; functions[i].format != '\0'; i++)
		if (format[*ind] == functions[i].format)
			return (functions[i].func(list, buffer, flags, width, precision, size));

	if (functions[i].format == '\0')
	{
		if (format[*ind] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (format[*ind - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (format[*ind] != ' ' && format[*ind] != '%')
				--(*ind);
			if (format[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_len += write(1, &format[*ind], 1);
		return (unknown_len);
	}
	return (printed_chars);
}
