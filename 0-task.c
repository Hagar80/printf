#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - A function that produces output according to a format
 * @format: A character string
 * Return: the number of characters printed
 * excluding the null byte used to end output to strings
 */
int _printf(const char *format, ...)
{
int char_print = 0;
va_list format_args;
if (format == NULL)
return (-1);
va_start(format_args, format);
while (*format) /*a loop that iterates through the chara format string*/
{
if (*format != '%') /*if format is not the % sign*/
{
write(1, format, 1); /*write the char to the standard output*/
char_print++;
}
else /*if format is the % sign*/
{
format++; /*skip '%' - check the next character*/
if (*format == '\0')
break;
if (*format == '%') /*this solves %%*/
{
write(1, format, 1);
char_print++;
}
else if (format == 'c')
{
char c = va_arg(format_args, int); /*use var_arg(list, char) for char*/
write(1, &c, 1);
char_print++;
}
else if (*format == 's')
{
char *str = va_arg(format_args, char*);
}
}
format++;
va_end(format_args);
} return (char_print);
}
