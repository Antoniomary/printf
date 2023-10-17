#include "main.h"

/**
 * _printf - a function that produces output according to a format.
 * @format: is a character string.
 *
 * Return: number of characters printed (excluding the null byte
 * used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	Buffer b = {0};
	int total_count = 0, temp;

	if (!format)
		return (-1);

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			if (*format)
			{
				temp = parser(&args, &b, &format);
				if (temp != -1)
					total_count += temp;
				else
					total_count = temp;
			}
		}
		else
		{
			b.buf[b.index++] = *format;
			++total_count;
			++format;
		}

		print_buffer(&b);
	}
	va_end(args);
	flush_buffer(&b);

	return (total_count);
}
