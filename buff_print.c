#include "main.h"

/**
 * print_buffer - prints the contents of buffer if it exist.
 * @buffer: an array of characters
 * @buff_ind: the index to add next char.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
