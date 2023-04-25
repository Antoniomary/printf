#include "main.h"

/**
 * print_reverse - Prints reverse string.
 * @types: list of arguments to format.
 * @buffer: is an array to handle print.
 * @flags: keeps track of active flags.
 * @width: the width output for a fetched argument.
 * @precision: the precision to apply.
 * @size: specifies the size.
 *
 * Return: the number of printed characters.
 */
int rev_str(va_list types, char buffer[], int flags, int width,
	int precision, int size)
{
	int i = 0, counter = 0;
	char *str, b;

	UNUSED(flags);
	UNUSED(buffer);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
		str = ")Null(";

	while (str[i])
		i++;

	for (i -= 1; i >= 0; i--)
	{
		b = str[i];
		write(1, &b, 1);
		counter++;
	}

	return (counter);
}
