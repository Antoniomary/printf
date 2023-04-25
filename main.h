#ifndef MAIN_H
#define MAIN_H


/* STANDARD LIBRARY FUNCTIONS ALLOWED */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


/* CONSTANT DEFINITIONS USED */

#define BUF 1024

#define HASH 8
#define MINUS 1
#define PLUS 2
#define SPACE 16
#define ZERO 4


/* USER-DEFINED MACROS */

#define UNUSED(x) (void)(x)


/* SIZES */
#define LONGS 2
#define SHORTS 1


/**
 * struct functions - a structure that holds a set for our function declarations.
 *
 * @format: The format.
 * @func: a function pointer to a function.
 */
typedef struct functions
{
	char format;
	int (*func)(va_list, char[], int, int, int, int);
} fmt_t;


/* ALL FUNCTION DECLARATIONS */

int _printf(const char *format, ...);

int print_std(const char *format, int *i, va_list list, 
	char buffer[], int constants, int width, int precision,
	int size);


/* Funtions that print characters and strings */

int print_char(va_list types, char buffer[], int constants,
	int width, int precision, int size);
int print_str(va_list types, char buffer[], int constants,
	int width, int precision, int size);
int print_percent(va_list types, char buffer[], int constants,
	int width, int precision, int size);


/* Functions to print numbers */

int print_int(va_list types, char buffer[], int constants,
	int width, int precision, int size);
int print_bit(va_list types, char buffer[], int constants,
	int width, int precision, int size);
int print_unsigned(va_list types, char buffer[], int constants, 
	int width, int precision, int size);
int print_octal(va_list types, char buffer[], int constants,
	int width, int precision, int size);
int print_hex(va_list types, char buffer[],int constants,
	int width, int precision, int size);
int print_heX(va_list types, char buffer[], int constants,
	int width, int precision, int size);
int print_hexa(va_list types, char hexas[], char buffer[],
	int constants, char flag_ch, int width, int precision,
	int size);


/* Function to print buffer */

void print_buffer(char buffer[], int *buff_ind);


/* Function to print unusual characters */

int print_unusual(va_list types, char buffer[], int constants,
	int width, int precision, int size);


/* Funcion to print memory address*/

int print_pointer(va_list types, char buffer[], int constants,
	int width, int precision, int size);


/* Function to handle other specifiers: width, precision */

int get_constants(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int get_flags(const char *format, int *i);


/* Function to print string in reverse*/

int rev_str(va_list types, char buffer[], int constants,
	int width, int precision, int size);


/* Function to print a string in rot13*/

int print_rot13d(va_list types, char buffer[],int constants,
	int width, int precision, int size);


/* Width handler */

int handle_write_char(char c, char buffer[], int constants,
	int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int constants, int width, int precision, int size);
int write_num(int ind, char bff[], int constants, int width,
	int precision,int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length, int width,
	int constants, char padd, char extra_c, int padd_start);
int write_unsigned(int is_negative, int ind, char buffer[],
	int constants, int width, int precision, int size);


/* helper functions */

int is_printable(char);
int is_digit(char);
long int conv_size_number(long int num, int size);
long int conv_size_unsigned(unsigned long int num, int size);
int append_hexa_code(char, char[], int);

#endif /* MAIN_H */
