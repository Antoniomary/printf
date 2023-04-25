#include "main.h"

/**
 * print_rot13string - Print a string in rot13.
 * @types: list of arguments to format.
 * @buffer: is an array to handle print.
 * @flags: keeps track of active flags.
 * @width: the width output for a fetched argument.
 * @precision: the precision to apply.
 * @size: specifies the size.
 *
 * Return: the number of printed characters.
 */
int print_rot13d(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	char b, *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				b = out[j];
				write(1, &b, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			b = str[i];
			write(1, &b, 1);
			count++;
		}
	}

	return (count);
}
