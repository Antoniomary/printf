#include "main.h"

/**
 * print_unusual - prints the hexadecimal value of a non-printable
 * ascii code character.
 * @types: list of arguments to format.
 * @buffer: is an array to handle print.
 * @flags: keeps track of active flags.
 * @width: the width output for a fetched argument.
 * @precision: the precision to apply.
 * @size: specifies the size.
 *
 * Return: the number of printed characters.
 */
int print_unusual(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i],
			buffer, i + offset);
		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}
