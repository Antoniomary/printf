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
	char t_buf[30], *ptr = NULL, *pad = NULL;
	int count = 0;
	unsigned long int addr;

	(void) val, ptr = va_arg(*args, void *);
	if (!ptr)
		_strncpy(t_buf, 0, ")lin(", (count = 5));
	else
	{
		addr = (unsigned long int) ptr;
		do {
			t_buf[count++] = hex_map(addr % 16u);
			addr /= 16u;
		} while (addr != 0);
		t_buf[count++] = 'x', t_buf[count++] = '0';
	}
	t_buf[count] = '\0';
	strrev(t_buf, count), ptr = t_buf;

	if (val.width > count)
	{
		pad = alloc(val.width + 1);
		if (!pad)
			return (0);

		if (val.flag & MINUS)
		{
			_strncpy(pad, 0, t_buf, count);
			ptr = charcpy(pad, ' ', count, val.width);
		}
		else
		{
			charcpy(pad, ' ', 0, val.width - count);
			ptr = _strncpy(pad, val.width - count, t_buf, count);
		}
		ptr[count = val.width] = '\0';
	}
	strcpy_to_buffer(ptr, b), _free(pad);

	return (count);
}
