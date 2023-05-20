#include "shell.h"

/**
 * active - returns true if shell is active mode
 * @info: struct address
 *
 * Return: 1 if active mode, 0 otherwise
*/
int active(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * ist_de - checks if character is a delimeter
 * @c: the char to check
 * @deli: the delimeter string
 * Return: 1 if true, 0 if false
 */
int ist_de(char c, char *deli)
{
while (*deli)
if (*deli++ == c)
return (1);
return (0);
}

/**
 *_isph - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isph(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
 *_atii - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atii(char *s)
{
int v = 0, sign = 1, flag = 0, out;
unsigned int res = 0;

while (s[v] != '\0' && flag != 2)
{
if (s[v] == '-')
sign *= -1;

if (s[v] >= '0' && s[v] <= '9')
{
flag = 1;
res *= 10;
res += (s[v] - '0');
}
else if (flag == 1)
flag = 2;

v++;
}

if (sign == -1)
out = -res;
else
out = res;

return (out);
}
