#include "main.h"

/**
 * convert_di - Converts an argument to a signed int and
 * stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t structhousing a character array.
 *
 * Return: The number of bytes stored in the buffer.
 */

unsigned int convert_di(va_list args, buffer_t *output,
			unsigned char flags, int wid, int prec, unsigned char len)
{
	int d;
	unsigned int count = 0;
	char str[20]; /* maximum digits in a signed long int + sign */
	char *p = str;

	if (len == LONG)
		d = va_arg(args, long int);
	else
		d = va_arg(args, int);
	if (len == SHORT)
		d = (short)d;
	if (d < 0)
	{
		*p++ = '-';
		d = -d;
	}
	else if (PLUS_FLAG == 1)
	{
		*p++ = '+';
	}
	else if (SPACE_FLAG == 1)
	{
		*p++ = ' ';
	}
	if (d == 0)
	{
		*p++ = '0';
		count++;
	}
	else
	{
		int tmp = d;
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
