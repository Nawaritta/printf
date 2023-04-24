#include "main.h"
/**
 * print_buffer - prints the buffer
 * @buffer: buf to print
 * @buf_index: index of the element in the buff
 */
void print_buffer(char buffer[], int *buf_index)
{
	if (*buf_index > 0)
		write(1, buffer, *buf_index);

	*buf_index = 0;
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
