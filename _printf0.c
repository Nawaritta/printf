#include "main.h"
/**
 *_printf - produces output according to a format
 * @format: dfines the type of the arg
 *Return: number of printed characters
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;
	char *s;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				c = va_arg(args, int);
				putchar(c);
				count++;
			}

			if (*format == 's')
			{
				s = va_arg(args, char *);

				while (*s)
				{
					putchar(*s++);
					count++;
				}
			}

		} else
		{
			putchar(*format);
			count++;
		}

		format++;
	}

	va_end(args);
	return (count);
}
