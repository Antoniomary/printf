#include "main.h"

/**
 * _abs - a function that returns the absolute value of a number.
 * @x: the number to return its absolute value.
 *
 * Return: the absolute value of x.
 */
int _abs(int x)
{
	return (x < 0 ? -x : x);
}

/**
 * hex_map - a function that maps numbers 0 - 15 to their hexadecimal symbols.
 * @n: the number to map.
 *
 * Description: this function maps only to lower case.
 * Return: the mapped value of n.
 */
int hex_map(int n)
{
	return (n >= 0 && n <= 9 ? n + '0' : n - 10 + 'a');
}

/**
 * Hex_map - a function that maps numbers 0 - 15 to their hexadecimal symbols.
 * @n: the number to map.
 *
 * Description: this function maps only to upper case.
 * Return: the mapped value of n.
 */
int Hex_map(int n)
{
	return (n >= 0 && n <= 9 ? n + '0' : n - 10 + 'A');
}

/**
 * _isdigit - a function that checks if a character is a digit.
 * @c: the character to check.
 *
 * Return: a number greater than or equal to 0 if is a digit, else -1.
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9' ? c - '0' : -1);
}

/**
 * isflag - a function that checks if a character is a printf flag.
 * @c: the character to check.
 *
 * Return: a number greater than 0 if c is a flag, else 0.
 */
int isflag(int c)
{
	if (c == '+')
		return (PLUS);
	if (c == ' ')
		return (SPACE);
	if (c == '#')
		return (HASH);
	if (c == '-')
		return (MINUS);
	if (c == '0')
		return (ZERO);

	return (0);
}
