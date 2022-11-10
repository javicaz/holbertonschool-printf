#include "main.h"
/**
 * _printf - print string
 * @format: variable that points to a list of arguments
 * @...: rest of arguments
 *
 * Return: the length of the printed string
 */

int _printf(const char *format, ...)
{
	va_list ptr;
	int pos = 0;
	int len = 0;
	int tmp = 0;
	int count = 0;
	const char *savec;

	if (restriction_percentage(format) == -1 || !format)
		return (-1);

	va_start(ptr, format);
	while (*(format + pos) != '\0')
	{
		savec = (format + pos);
		if (*savec == '%' && *(save + 1) != '%')
		{
			len = match_case(savec + 1)(ptr);
			if (len == -1)
				return (-1);

			tmp += len;

			pos = pos + 2;
			savec = (format + pos);
		}
		if (*(savec) == '%' && *(savec + 1) == '%')
			pos++, savec = (format + pos);
		if (*(savec - 1) != '%' && *(savec) == '%' && *(savec + 1) != '%')
			continue;
		_putchar(*(savec));
		count++;
		pos++;
	}
	va_end(ptr);
	return (count + tmp);
}
/**
 * restriction_percentage - checks the percentages
 * @str: A variable that points to a list of arguments
 *
 * Return: the length of the printed string
 */
int restriction_percentage(const char *str)
{
	int pos = 0, count = 0;

	while (*(str + pos))
	{
		if (*(str + pos) == '%')
		{
			count = 0;
			while (*(str + pos) == '%')
			{
				count++;
				pos++;
			}
			if (count % 2 != 0 && match_case(str + pos) == NULL)
			{
				return (-1);
			}
		}
		pos++;
	}
	return (0);
}


