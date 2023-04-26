#include "main.h"

/**
 * convert_b - Converts an unsigned int argument to binary
 * and stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored in the buffer.
 */

unsigned int convert_b(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned int val;

	val = va_arg(args, unsigned int);

	(void)len;

	return (convert_ubase(output, val, "01", flags, wid, prec));
}

/**
 * convert_o - Converts an unsigned int to octal and
 * stores it to a buffer contained in a struct.
 * @args: A va_list poinitng to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */

unsigned int convert_o(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int val;
	unsigned int ret = 0;
	char zero = '0';

	if (len == LONG)
		val = va_arg(args, unsigned long int);
	else
		val = va_arg(args, unsigned int);
	if (len == SHORT)
		val = (unsigned short)val;

	if (HASH_FLAG == 1 && val != 0)
		ret += _memcpy(output, &zero, 1);

	if (!(val == 0 && prec == 0))
		ret += convert_ubase(output, val, "01234567",
				flags, wid, prec);

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}

/**
 * convert_u - Converts an unsigned int argument to decimal and
 * stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct housing a character array.
 *
 * Return: The number of bytes stored in the buffer.
 */

unsigned int convert_u(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int val;
	unsigned int ret = 0;

	if (len == LONG)
		val = va_arg(args, unsigned long int);
	else
		val = va_arg(args, unsigned int);
	if (len == SHORT)
		val = (unsigned short)val;

	if (!(val == 0 && prec == 0))
		ret += convert_ubase(output, val, "0123456789",
				flags, wid, prec);

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}
