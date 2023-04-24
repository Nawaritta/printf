#include "main.h"
/**
 *_printf - produces output according to a format
 * @format: dfines the type of the arg
 *Return: number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, buf_index = 0;
	char c, *s, buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			print_buffer(buffer, &buf_index);
			i++;
			switch (format[i])
			{
			case 'c':
				c = va_arg(args, int);
				buffer[buf_index++] = c;
				count++;
				break;
			case 's':
				s = va_arg(args, char *);
				while (*s != '\0')
				{
					buffer[buf_index++] = *s;
					count++;
					s++;
					if (buf_index == BUFFER_SIZE)
						print_buffer(buffer, &buf_index);
				}
				break;
			case '%':
				buffer[buf_index++] = '%';
				count++;
				break;
			default:
				va_end(args);
				return (-1);
			}
		} else
		{
			buffer[buf_index++] = format[i];
			count++;
			if (buf_index == BUFFER_SIZE)
				print_buffer(buffer, &buf_index);
		}
		i++;
	}
	print_buffer(buffer, &buf_index);
	va_end(args);
	return (count);
}

