#include "main.h"
/**
 *di_printf - function that handles i and d
 *@format: pointer to a char
 *Return: void
 */
void di_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);

				printf("%d", num);
			}
			else
			{
				putchar('%');
				putchar(*format);
			}
		}
		else
		{
			putchar(*format);
		}
		format++;
	}
	va_end(args);
}

