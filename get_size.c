#include "main.h"

/**
* get_size - it calculates the size to cast to the argument
* @format: a character string
* @i: list of arguments to be printed.
*
* Return: Precision.
*/
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = LONGS;
	else if (format[curr_i] == 'h')
		size = SHORTS;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
