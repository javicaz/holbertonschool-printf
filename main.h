#ifndef HEADER_H
#define HEADER_H

#include <stdgarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);

/**
 * struc case_match - stores a flag and function
 * @c: pointer to the flag
 * @f: pointer to function
 *
 *Description: Longer description
 */
typedef struct case_match
{
	char *c;
	int (*f)(va_list);
} c_mtc;
/* ------------------------------------*/
int _putchar(char c);
void _puts(char *str);
int _strlen(char *);
char *_strcpy(char *, char *);
char *_strcat(char *, char *);
/* --------------------------- */
int char_case(va_list);
int string_case(va_list);
int digit_base_10(va_list);
/*------------------------------------*/
int restriction_percentage(const char *str);
int (*match_case(const char *))(va_list);
int convert_base(int base, int number, int band);
int print_number(int n);

#endif
