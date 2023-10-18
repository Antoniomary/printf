#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024

#define  ZERO  1
#define  HASH  2
#define  PLUS  4
#define MINUS  8
#define SPACE 16

/**
 * struct buffer - a struct for a buffer.
 * @index: the number of characters stored in buffer (zero-based index).
 * @buf: a character array.
 */
typedef struct buffer
{
	int index;
	char buf[BUF_SIZE];
} Buffer;

/**
 * struct specifier - a struct for format specifiers.
 * @flag: for +, -, 0.
 * @width: for the width value.
 * @precision: for the precision value (.<number>).
 * @len_mod: for the length modifier h or l.
 */
typedef struct specifier
{
	int flag;
	int width;
	int precision;
	int len_mod;
} formatSpecifier;

typedef int (*format_parser)(va_list *args, Buffer *b, formatSpecifier val);

/**
 * struct handler - a struct for a parser.
 * @spec: to hold the specifier e.g d in '%d'.
 * @func: a pointer to a function (of user defined data type).
 */
typedef struct handler
{
	char spec;
	format_parser func;
} formatHandler;

/* custom prinf prototype */
int _printf(const char *format, ...);

int parser(va_list *args, Buffer *b, const char **format);

int print_char(va_list *args, Buffer *b, formatSpecifier val);
int print_str(va_list *args, Buffer *b, formatSpecifier val);
int print_perc(va_list *args, Buffer *b, formatSpecifier val);
int print_int(va_list *args, Buffer *b, formatSpecifier val);
int print_binary(va_list *args, Buffer *b, formatSpecifier val);
int print_uint(va_list *args, Buffer *b, formatSpecifier val);
int print_octal(va_list *args, Buffer *b, formatSpecifier val);
int print_hex(va_list *args, Buffer *b, formatSpecifier val);
int print_HEX(va_list *args, Buffer *b, formatSpecifier val);
void print_buffer(Buffer *b);
void flush_buffer(Buffer *b);
int print_Str(va_list *args, Buffer *b, formatSpecifier val);
int print_addr(va_list *args, Buffer *b, formatSpecifier val);
int print_reverse(va_list *args, Buffer *b, formatSpecifier val);
int print_rot13(va_list *args, Buffer *b, formatSpecifier val);
int print_literal(Buffer *b, formatSpecifier val);

/* general helper functions */
int _abs(int x);
int hex_map(int n);
int Hex_map(int n);
int _isdigit(int c);
int isflag(int c);

/* helper functions that deal with strings*/
int _free(char *ptr);
char *alloc(int size);
int _strlen(const char *s);
char *charcpy(char *s, char c, int start, int end);
char *_strncpy(char *to, int start, char *from, int n);


/* helper functions that deal with numbers*/
int itoa_reverse(char *rev, long num, unsigned long u_num, int opt, int base);
int itoa_reverse_base_16(char *rev, unsigned long u_num, int opt);
int handle_precision(char **old, int old_len, char *new, int precision);
int handle_width(char **old, int len, char *new, int w, int flag, int c);
int handle_width_uint(char **old, int len, char *new, int w, int flag, int c);

void strcpy_to_buffer(char *s, Buffer *b);
void rev_strcpy_to_buffer(char *s, int s_len, Buffer *b);

/* functions that get arguments for formatting */
int get_length(char c);
int get_width(va_list *args, const char **c);
int get_precision(va_list *args, const char **c);

#endif /* MAIN_H */
