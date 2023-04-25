#include "main.h"

/**
 * print_int - a funtion that print an integer
 * @types: list of arguments to format.
 * @buffer: is an array to handle print.
 * @flags: keeps track of active flags.
 * @width: the width output for a fetched argument.
 * @precision: the precision to apply.
 * @size: specifies the size.
 *
 * Return: the number of printed characters.
 */
int print_int(va_list types, char buffer[], int flags, int width,
	int precision, int size)
{
	int i = BUF - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = conv_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUF - 1] = '\0';

	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;

	return (write_number(is_negative, i, buffer, flags,
		width, precision, size));
}

/**
 * print_bit - prints an unsigned number in binary.
 * @types: list of arguments to format.
 * @buffer: is an array to handle print.
 * @flags: keeps track of active flags.
 * @width: the width output for a fetched argument.
 *
 * Return: 
 */
int print_bit(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */

	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char b = '0' + a[i];
			write(1, &b, 1);
			count++;
		}
	}

	return (count);
}
