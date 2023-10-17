#include "main.h"

/**
 * handle_width_uint - a function that handles the alignment of unsigned ints.
 * @old: double pointer to the unsigned int stored in a character array.
 * @len: the length of old.
 * @new: pointer to the new array where old will be copied to.
 * @w: the width of the unsigned int.
 * @flag: the flag for the alignment.
 * @c: the character to use when width is more than the digits of the uint.
 *
 * Return: Always the width.
 */
int handle_width_uint(char **old, int len, char *new, int w, int flag, int c)
{
	if (flag & MINUS)
	{
		*old = _strncpy(new, w - len, *old, len);
		charcpy(*old, c, 0, w - len);
	}
	else
	{
		*old = _strncpy(new, 0, *old, len);
		charcpy(*old, c, len, w);
	}

	return (w);
}
