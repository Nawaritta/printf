#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#define BUFFER_SIZE 1024
int _printf(const char *format, ...);
void print_buffer(char *buffer, int *buf_index);
int _putchar(char c);
#endif
