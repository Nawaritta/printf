#include "main.h"
/**
 *_printf - produces output according to a format
 * @format: dfines the type of the arg
 *Return: number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int buf_index = 0;
	int  count = 0;
	char c, buffer[BUFFER_SIZE];
	char *s;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{	format++;
			if (*format == 'c')
			{	c = va_arg(args, int);
				buffer[buf_index++] = c;
				count++; }
			if (*format == 's')
			{	s = va_arg(args, char *);
				while (*s != '\0')
				{	buffer[buf_index++] = *s++;
					count++; }
			}
			if (*format == '%')
			{	buffer[buf_index++] = '%';
				count++; }
		} else
		{	buffer[buf_index++] = *format;
			count++; }
		format++;
		if (buf_index == BUFFER_SIZE)
		{
			print_buffer(buffer, &buf_index);
			buf_index = 0;
		}
	}
	if (buf_index > 0)
		print_buffer(buffer, &buf_index);
	va_end(args);
	return (count);
}
