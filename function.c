#include "main.h"
/**
 * print_buffer - prints the buffer
 * @buffer: buf to print
 * @buf_index: index of the element in the buff
 */
void print_buffer(char buffer[], int *buf_index)
{
	if (*buf_index > 0)
		write(1, &buffer[0], *buf_index);

	*buf_index = 0;
}
