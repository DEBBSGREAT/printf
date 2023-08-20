#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - Format and print data to stdout
 * @format: A string containing zero or more format specifiers
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
char c;
va_start(args, format);
while ((c = *format++) != '\0')
{
if (c == '%')
{
switch (*format++)
{
case 'c':
putchar(va_arg(args, int));
count++;
break;
case 's':
count += printf("%s", va_arg(args, char *));
break;
case '%':
putchar('%');
count++;
break;
default:
break;
}
}
else
{
putchar(c);
count++;
}
}
va_end(args);
return (count);
}
