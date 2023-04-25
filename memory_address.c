#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 * @types: list of arguments to format.
 * @buffer: is an array to handle print.
 * @flags: keeps track of active flags.
 * @width: the width output for a fetched argument.
 * @precision: the precision to apply.
 * @size: specifies the size.
 *
 * Return: the number of printed characters.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUF - 2, length = 2, padd_start = 1;

	unsigned long num_addrs;
	char hexa[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUF - 1] = '\0';

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = hexa[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & ZERO) && !(flags & MINUS))
		padd = '0';
	if (flags & PLUS)
		extra_c = '+', length++;
	else if (flags & SPACE)
		extra_c = ' ', length++;

	ind++;

	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}
