#include "main.h"
/**
 * _printf - function that produces output according to a format
 * @format: pointer to a string
 * Return: an int
 */
int _printf(const char *format, ...)
{
	int i, j, count = 0;
	va_list args;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				char c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			}
			else if (format[i] == 's')
			{
				char *s = va_arg(args, char*);
				for (j = 0; s[j] != '\0'; j++)
				{
					write(1, &s[j], 1);
					count++;
				}
			}
			else if (format[i] == '%')
			{
				write(1, '%', 1);
				count++;
			}
		else
		{
		}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		}
		va_end(args);
		return (count);
}

