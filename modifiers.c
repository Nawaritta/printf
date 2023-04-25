#include "main.h"

/**
 * print_width -  width modifier.
 * @output: points to the buff structure
 * @printed: printed characters.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int print_width(buffer_t *output, unsigned int printed,
			 unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		for (wid -= printed; wid > 0;)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}

/**
 * print_string_width - contains the leading spaces to a buff for a width mod
 * @output: pointer to the buff.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @size: String's size.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int print_string_width(buffer_t *output,
				unsigned char flags, int wid, int prec, int size)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		wid -= (prec == -1) ? size : prec;
		for (; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}

/**
 * print_neg_width - Stores trailing space.
 * @output: pointer to the buff.
 * @printed: printed char.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * Return: The number of bytes stored to the buffer.
 */
unsigned int print_neg_width(buffer_t *output, unsigned int printed,
			     unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 1)
	{
		for (wid -= printed; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}
