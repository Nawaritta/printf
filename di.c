#include "main.h"

/**
 * convert_di - Converts an arg to a signed int and stores it in a struct buff.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t structhousing a character array.
 * Return: The number of bytes stored in the buffer.
 */
unsigned int convert_di(va_list args, buffer_t *output,
			unsigned char flags, int wid, int prec, unsigned char len)
{
	int d, tmp;
	unsigned int count = 0;
	char str[20]; /* maximum digits in a signed long int + sign */
	char *p = str;

	d = (len == LONG) ? va_arg(args, long int) : va_arg(args, int);
	(len == SHORT) ? d = (short)d : d;
	d < 0 ? (*p++ = '-', d = -d)
		: PLUS_FLAG == 1 ? (*p++ = '+')
		: SPACE_FLAG == 1 ? (*p++ = ' ')
		: 0;
	if (d == 0)
	{
		*p++ = '0';
		count++;
	} else
	{
		tmp = d;
		while (tmp)
		{
			*p++ = '0' + (tmp % 10);
			tmp /= 10;
			count++;
		}
	}
	while (p - str < wid && !(ZERO_FLAG == 1 && prec <= 0))
	{
		*p++ = ' ';
		count++;
	}
	while (p - str < prec)
	{
		*p++ = '0';
		count++;
	}
	while (p-- > str)
	{
		count += _memcpy(output, p, 1);
	}
	return (count);
}
