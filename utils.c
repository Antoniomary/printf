#include "main.h"

/**
* is_printable - checks if a chararcter is printable.
* @c: the character to be checked.
*
* Return: 1 if c is printable, 0 otherwise
*/
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * is_digit - checks for digit.
 * @c: character to be checked
 *
 * Return: 1 if c is a digit, 0 otherwise.
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * conv_size_number - casts a number to the specified size.
 * @num: the number to be casted.
 * @size: number indicating the type to be casted into
 *
 * Return: casted value of num
 */
long int conv_size_number(long int num, int size)
{
	if (size == LONGS)
		return (num);
	else if (size == SHORTS)
		return ((short)num);

	return ((int)num);
}

/**
 * conv_size_unsgnd - casts a number to the specified size
 * @num: the number to be casted to unsigned.
 * @size: number indicating the type to be casted into
 *
 * Return: casted value of num
 */
long int conv_size_unsigned(unsigned long int num, int size)
{
	if (size == LONGS)
		return (num);
	else if (size == SHORTS)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @ascii_code: the ascii code in decimal.
 * @buffer: an array to hold the characters to append.
 * @i: the index at which to start appending.
 *
 * Return: Always 3 (success).
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char hexas[] = "0123456789ABCDEF";

	/**
	 * convert negative sign in the ascii code since
	 * acsii codes are supposedly positive i.e unsigned
	 */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = hexas[ascii_code / 16];
	buffer[i] = hexas[ascii_code % 16];

	return (3);
}
