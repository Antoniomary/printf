#include "main.h"

/**
 * _free - a function that frees a dynamically allocated space.
 * @ptr: the space to free.
 *
 * Return: Always 0 (success).
 */
int _free(char *ptr)
{
	if (ptr != NULL)
		free(ptr);

	return (0);
}

/**
 * alloc - a function used to allocate an array of character.
 * @size: size to allocate.
 *
 * Return: pointer to the allocated space (success), else NULL (failure).
 */
char *alloc(int size)
{
	char *new = (char *) malloc(sizeof(char) * size);

	return (new);
}

/**
 * _strlen - get the length of a string.
 * @s: pointer to the string.
 *
 * Return: length of s.
 */
int _strlen(const char *s)
{
	const char *ptr = s;

	while (*ptr)
		++ptr;

	return (ptr - s);
}

/**
 * charcpy - a function that copies a character to a designated block.
 * @s: the pointer to the address to copy to.
 * @c: the character to copy to a block within s.
 * @start: index to begin copying.
 * @end: index to end copying (not inclusive).
 *
 * Return: Always pointer to the address i.e s.
 */
char *charcpy(char *s, char c, int start, int end)
{
	while (start < end)
		s[start++] = c;

	return (s);
}

/**
 * _strncpy - a function that copies a string to another string.
 * @to: the destination address to copy to.
 * @start: index to begin copying to.
 * @from: the source address to copy from.
 * @n: number of characters to copy from source (not inclusive).
 *
 * Return: Always pointer to the destination address i.e to.
 */
char *_strncpy(char *to, int start, char *from, int n)
{
	int i;

	for (i = 0; i < n && from[i]; ++i)
		to[start + i] = from[i];

	return (to);
}
