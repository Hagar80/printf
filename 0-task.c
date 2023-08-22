#include "main.h"
#include <stdio.h>
#include <stdarg.h>
int _printf(const char *format, ...)
{
int char_print = 0;
va_list format_args;
if(format == NULL)
return (-1);
va_start(format_args, format);
while (format)
{
if (format != '%')
{
write(1, format, 1);
char_print++;
}
else
{
format++;
if (*format == '\0')
break;
if (*format == '%')
{
write(1, format, 1);
char_print++;
}
else if (format == 'c')
{
char c = va_arg(format_args, int);
write(1, &c, 1);
char_print++;
}
else if(format == 's')
{
char str = va_arg(format_args, char);
int str_len = 0;
whie (; str[str_len] != '\0')
str_len++;
write(1, str, strlen);
char_print += strlen(str);
}
}
format++;
}
va_end(format_args);
return (char_print);
}
