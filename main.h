#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n);
void free_buffer(buffer_t *output);
buffer_t *init_buffer(void);

void cleanup(va_list args, buffer_t *output);
int run_printf(const char *format, va_list args, buffer_t *output);
int _printf(const char *format, ...);

unsigned char handle_flags(const char *flag, char *index);
unsigned char handle_length(const char *modifier, char *index);
int handle_width(va_list args, const char *modifier, char *index);
int handle_precision(va_list args, const char *modifier, char *index);

unsigned int print_width(buffer_t *output, unsigned int printed,
			 unsigned char flags, int wid);
unsigned int print_string_width(buffer_t *output,
				unsigned char flags, int wid, int prec, int size);
unsigned int print_neg_width(buffer_t *output, unsigned int printed,
			     unsigned char flags, int wid);

/**
 * struct print - defines the differents data types to print
 * @t: type to print
 * @f: function to print
 */
typedef struct print
{
	char *t;
	int (*f)(va_list);
} print_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list c);
int print_s(va_list s);
int print_i(va_list i);
int print_d(va_list d);
int print_u(va_list u);
int print_b(va_list b);
int print_o(va_list o);
int print_x(va_list x);
int print_X(va_list X);
int print_p(va_list p);
int print_S(va_list S);
int print_r(va_list r);
int print_R(va_list R);

#endif
