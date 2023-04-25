#include "main.h"

/**
 * get_flags - checks for the flags contained in format.
 * @format: a character string.
 * @i: takes a parameter.
 *
 * Return: the number that corresponds to the flag.
 */
int get_flags(const char *format, int *i)
{
	/*  -  +  0  #  ' ' */
	/*  ^  ^  ^  ^   ^  */
	/*  1  2  4  8  16  */

	int n, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {MINUS, PLUS, ZERO, HASH, SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (n = 0; FLAGS_CH[n] != '\0'; n++)
			if (format[curr_i] == FLAGS_CH[n])
			{
				flags |= FLAGS_ARR[n];
				break;
			}

		if (FLAGS_CH[n] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}
