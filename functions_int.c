#include "main.h"
/**
 * print_int - A function to print an integer
 * @types: The list of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: The precision specification
 * @size: The size specifier
 * Return: The number of chars printed
 */
int print_int(va_list types, char buffer, int flags)
int print_int(int width, int precision, int size)
{
int l = BUFF_SIZE - 2;
int is_negative = 0;
long int n = va_arg(types, long int);
unsigned long int num;
n = convert_size_number(n, size);
if (n == 0)
buffer[l--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)n;
if (n < 0)
{
num = (unsigned long int) ((-1 * n);
is_negative = 1;
}
while (num > 0)
{
buffer[l--] = (num % 10) + '0';
num = 10;
}
l++
return (write_number(is_negative, l, buffer, flags, width, precision, size));
}
