#include "main.h"
/**
 *_printf - produces output according to a format
 * @format: dfines the type of the arg
 *Return: number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int buf_index = 0, count = 0;
	char c, buffer[BUFFER_SIZE], *s;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{	format++;
			if (*format == 'c')
			{	c = va_arg(args, int);
				buffer[buf_index++] = c; }
			if (*format == 's')
			{
				if (va_arg(args, char *) == NULL)
					return (-1);
				s = va_arg(args, char *);
				while (*s != '\0')
					buffer[buf_index++] = *s++;
			}
			if (*format == '%')
				buffer[buf_index++] = '%';
		} else
			buffer[buf_index++] = *format;
		format++;
		if (buf_index == BUFFER_SIZE)
		{
			count += buf_index;
			if (format[buf_index] == '%')
				buf_index--;
			print_buffer(buffer, &buf_index);
		}
	}
	if (buf_index > 0)
	{
		count += buf_index;
		if (format[buf_index] == '%')
			buf_index--;
		print_buffer(buffer, &buf_index); }
	va_end(args);
	return (count);
}
