#include "main.h"
/**
 * _printf - recreates the printf function
 * @format: string with format specifier
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
int i, j;
int counter = 0;
va_list args;
va_start(args, format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'c':
{
char c = va_arg(args, int);
write(1, &c, 1);
counter++;
break;
}
case 's':
{
char *s = va_arg(args, char*);
for (j = 0; s[j] != '\0'; j++)
{
write(1, &s[j], 1);
counter++;
}
break;
}
case '%':
{
write(1, "%", 1);
counter++;
break;
}
default:
break;
}
}
else
{
write(1, &format[i], 1);
counter++;
}
}
va_end(args);
return (counter);
}
