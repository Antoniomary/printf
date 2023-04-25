#include "main.h"
#include <stdarg.h>

/**
 * _printf - a function that gives  output according to a format.
 * @format: is a character string. It may be composed of zero or
 * more directives.
 * @...: optional arguments to be formatted to stdout.
 *
 * Return: the number of characters printed (excluding the null
 * byte used to end output to string.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flag, width, precision, size, buff_ind = 0;
	char buffer[BUF];
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		/* prints single character one at a time */
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUF)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		/**
		 * handles any form of formating to be done by
		 * other functions.
		 */
		else
		{
			print_buffer(buffer, &buff_ind);
			flag = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = print_std(format, &i, list,
			buffer, flag, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}
