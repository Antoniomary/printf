#include "main.h"

/**
 * null_handler - a function that writes "(null)" to buffer when a pointer
 * is NULL.
 * @b: the buffer to write to.
 *
 * Return: Always 6 (the length of the string "(null)").
 */
int null_handler(Buffer *b)
{
	char *null = "(null)";

	for ( ; *null; ++null)
	{
		print_buffer(b);

		b->buf[b->index++] = *null;
	}

	return (6);
}

/**
 * strcpy_to_buffer - a function that copies a string to buffer.
 * @s: pointer to the string to copy.
 * @b: a structure to the buffer.
 */
void strcpy_to_buffer(char *s, Buffer *b)
{
	for ( ; *s; ++s)
	{
		print_buffer(b);
		b->buf[b->index++] = *s;
	}
}

/**
 * rev_strcpy_to_buffer - a function that copies a string to buffer.
 * @s: pointer to the string to copy.
 * @s_len: length of the string to copy.
 * @b: a structure to the buffer.
 */
void rev_strcpy_to_buffer(char *s, int s_len, Buffer *b)
{
	for (s_len--; s_len >= 0; --s_len)
	{
		print_buffer(b);
		b->buf[b->index++] = s[s_len];
	}
}
