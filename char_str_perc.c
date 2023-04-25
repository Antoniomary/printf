#include "main.h"

/**
 * print_char - prints a character
 * @types: list of arguments to format.
 * @buffer: is an array to handle print.
 * @flags: keeps track of active flags.
 * @width: the width output for a fetched argument.
 * @precision: the precision to apply.
 * @size: specifies the size.
 *
 * Return: the number of printed characters.
 */
int print_char(va_list types, char buffer[],int flags, int width,
	int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width,
		precision, size));
}

/**
 * print_string - prints a string
 * @types: list of arguments to format.
 * @buffer: is an array to handle print.
 * @flags: keeps track of active flags.
 * @width: the width output for a fetched argument.
 * @precision: the precision to apply.
 * @size: specifies the size.
 *
 * Return: the number of printed characters.
 */
int print_str(va_list types, char buffer[], int flags, int width,
	int precision, int size)
{
	int len= 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = " ";
	}
	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}

/**
 * print_percent - prints a percentage sign.
 * @types: list of arguments to format.
 * @buffer: is an array to handle print.
 * @flags: keeps track of active flags.
 * @width: the width output for a fetched argument.
 * @precision: the precision to apply.
 * @size: specifies the size.
 *
 * Return: the number of printed characters.
 */
int print_percent(va_list types, char buffer[],int flags,
	int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}
