#include "main.h"
/**
* _printf - Prints the string
* @format: A variable that points to a list of arguments
* @...: The rest of the arguments
* Return: the lenght of the printed string
*/
int _printf(const char *format, ...)
{
	int pos, count = 0;
	va_list ptr;
	char buff[1024];
	char *add = &buff[0];

	va_start(ptr, format);
	
	if ((format == NULL) || (*(format) == '%' && *(format + 1) == '\0'))
		return (-1);
	if (*(format) == '\0')
		return (0);
	
	for (pos = 0;*(format + pos) != '\0'; pos++)
	{
		if (*(format + pos) == '%' && *(format + pos + 1) == '%')
		{
			*add = *(format + pos);
			add++:
			pos++;
			continue;
			
			if (*(format + pos) == '%' && *(format + pos + 1) == '\0')
			{
				return (-1);
			}
			if (*(format + pos) == '%')
			{
				if (match_case(format + pos + 1) != NULL)
				{
					count += match_case(format + pos + 1)(ptr, &add);
					pos++;
					continue;
				}
			}
			*add = *(format + pos);
			add++;
		}
		va_end(ptr);
		return (_putchar(buff, add - (char *)buff));
}
