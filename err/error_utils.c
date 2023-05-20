#include "shell.h"

/**
 * _strtoint - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _strtoint(char *s)
{
int v = 0;
unsigned long int res = 0;

if (*s == '+')
s++;  /* TODO: why does this make main return 255? */
for (v = 0;  s[v] != '\0'; v++)
{
if (s[v] >= '0' && s[v] <= '9')
{
res *= 10;
res += (s[v] - '0');
if (res > INT_MAX)
return (-1);
}
else
return (-1);
}
return (res);
}

/**
 * print_errorms - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_errorms(info_t *info, char *estr)
{
_eppu(info->fname);
_eppu(": ");
print_dec(info->line_count, STDERR_FILENO);
_eppu(": ");
_eppu(info->argv[0]);
_eppu(": ");
_eppu(estr);
}

/**
 * print_dec - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_dec(int input, int fd)
{
int (*__putchar)(char) = _puuchi;
int v, count = 0;
unsigned int _abs_, current;

if (fd == STDERR_FILENO)
__putchar = _epitch;
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
 * convert_snum - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_snum(long int num, int base, int flags)
{
static char *array;
static char bufes[50];
char sign = 0;
char *ptr;
unsigned long n = num;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &bufes[49];
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
 * replace_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void replace_comments(char *buf)
{
int v;

for (v = 0; buf[v] != '\0'; v++)
if (buf[v] == '#' && (!v || buf[v - 1] == ' '))
{
buf[v] = '\0';
break;
}
}
