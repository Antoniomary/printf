#include "main.h"

/**
 * print_unsigned - a function that prints an unsigned number.
 * @types: contains a list of arguments.
 * @buffer: an array contain what would be printed.
 * @flags:  detects an active flags to format.
 * @width: hold the width to format if any.
 * @precision: specifies the precision required.
 * @size: specifies the size.
 *
 * Return: the number of characters printed to stdout..
 */
int print_unsigned(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	int i = BUF - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = conv_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUF - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsigned(0, i, buffer, flags, width,
		precision, size));
}

/**
 * print_octal - prints an unsigned number in octal notation
 * @types: contains a list of arguments.
 * @buffer: an array contain what would be printed.
 * @flags:  detects an active flags to format.
 * @width: hold the width to format if any.
 * @precision: specifies the precision required.
 * @size: specifies the size.
 *
 * Return: the number of characters printed to stdout..
 */
int print_octal(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{

	int i = BUF - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = conv_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUF - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsigned(0, i, buffer, flags, width, 
		precision, size));
}

/**
 * print_hex - prints an unsigned number in lower hexadecimal
 * notation
 * @types: contains a list of arguments.
 * @buffer: an array contain what would be printed.
 * @flags:  detects an active flags to format.
 * @width: hold the width to format if any.
 * @precision: specifies the precision required.
 * @size: specifies the size.
 *
 * Return: the number of characters printed to stdout..
 */
int print_hex(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, 
		flags, 'x', width, precision, size));
}

/**
 * print_heX - prints an unsigned number in upper hexadecimal notation
 * @types: contains a list of arguments.
 * @buffer: an array contain what would be printed.
 * @flags:  detects an active flags to format.
 * @width: hold the width to format if any.
 * @precision: specifies the precision required.
 * @size: specifies the size.
 *
 * Return: the number of characters printed to stdout..
 */ 
int print_heX(va_list types, char buffer[], int flags, int width,
	int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * notation
 * @types: contains a list of arguments.
 * @hexas: an array that holds the values to map the number to
 * @buffer: an array contain what would be printed.
 * @flags:  detects an active flag to format.
 * @flag_ch: detects an active flag to fomat.
 * @width: hold the width to format if any.
 * @precision: specifies the precision required.
 * @size: specifies the size.
 *
 * Return: the number of characters printed to stdout..
 */ 
int print_hexa(va_list types, char hexas[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUF - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = conv_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUF - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = hexas[num % 16];
		num /= 16;
	}

	if (flags & HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsigned(0, i, buffer, flags, width,
		precision, size));
}
