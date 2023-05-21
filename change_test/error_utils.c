#include "shell.h"


/**
 * _erratoi - convert string to int
 * @s: string which conveted
 * Return: 0 if no num in string, converted num -1 if there and error
 */


int _erratoi(char *s)
{
int v = 0;
unsigned long int result = 0;

if (*s == '+')
s++;

for (v = 0;  s[v] != '\0'; v++)
{
if (s[v] >= '0' && s[v] <= '9')
{
result *= 10;
result += (s[v] - '0');
if (result > INT_MAX)
return (-1);
}
else

return (-1);
}
return (result);
}


/**
 * print_error - show error
 * @info: parameter & return struct
 * @estr: string contain specific error type
 * Return: 0 if no num in string convert num to -1 on error
 */

void print_error(info_t *info, char *estr)
{
_eputs(info->fname);
_eputs(": ");
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estr);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: input
 * @fd: filedescriptor to write to
 * Return: num of char which will printed
 */

int print_d(int input, int fd)
{
int (*__putchar)(char) = _putchar;
int v, count = 0;
unsigned int _abs_, current;

if (fd == STDERR_FILENO)
__putchar = _eputchar;
if (input < 0)
{
_abs_ = -input;
__putchar('-');
count++;
}
else
_abs_ = input;
current = _abs_;
for (v = 1000000000; v > 1; v /= 10)
{
if (_abs_ / v)
{
__putchar('0' + current / v);
count++;
}
current %= v;
}
__putchar('0' + current);
count++;

return (count);
}

/**
 * convert_number - convert function clone
 * @num: numb
 * @base: base
 * @flags: argu flag
 * Return: string
 */

char *convert_number(long int num, int base, int flags)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';

while (n != 0)
{
*--ptr = array[n % base];
n /= base;
}

if (sign)
*--ptr = sign;
return (ptr);
}

/**
 * remove_comments - function replaces first '#' with '\0'
 * @buf: address of string
 * Return: 0
 */


void remove_comments(char *buf)
{
int v;

for (v = 0; buf[v] != '\0'; v++)
if (buf[v] == '#' && (!v || buf[v - 1] == ' '))
{

buf[v] = '\0';
break;
}
}
