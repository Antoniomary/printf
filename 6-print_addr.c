#include "main.h"

/**
 * print_addr - a function that handles specifier p.
 * @args: is a pointer to the argument to be formatted.
 * @b: is a pointer to a structure for a buffer.
 * @val: is a structure holding info about the specifiers given by the user.
 *
 * Description: it handles the formatting of memory address of a variable
 * in hexadecimal (lower case)..
 * Return: the number of characters of the processed formated string.
 */
int print_addr(va_list *args, Buffer *b, formatSpecifier val)
{
	char t_buf[30], *ptr = NULL;
	int i = 0, count = 5;
	unsigned long int addr;

	(void) val;
	ptr = va_arg(*args, void *);
	if (!ptr)
		for (ptr = "(nil)"; i < count; ++i)
		{
			print_buffer(b);
			b->buf[b->index++] = ptr[i];
		}
	else
	{
		addr = (unsigned long int) ptr;
		do {
			t_buf[i++] = hex_map(addr % 16u);
			addr /= 16u;
		} while (addr != 0);

		t_buf[i++] = 'x', t_buf[i++] = '0';

		count = i;
		for (--i; i >= 0; --i)
		{
			print_buffer(b);
			b->buf[b->index++] = t_buf[i];
		}
	}

	return (count);
}
