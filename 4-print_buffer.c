#include "main.h"

/**
 * print_buffer - a function that writes the content of a buffer to stdout.
 * @b: is a pointer to a structure for a buffer.
 *
 * Description: it uses a local buffer of 1024 chars in order to call write as
 * little as possible. Once full, it writes the content to stdout.
 */
void print_buffer(Buffer *b)
{
	if (b->index >= BUF_SIZE - 1)
	{
		write(1, b->buf, b->index);
		b->index = 0;
	}
}

/**
 * flush_buffer - a function that writes the content of a buffer to stdout.
 * @b: is a pointer to a structure for a buffer.
 *
 * Description: it writes to stdout as long as buffer has at least one char.
 */
void flush_buffer(Buffer *b)
{
	if (b->index > 0)
	{
		write(1, b->buf, b->index);
		b->index = 0;
	}
}
