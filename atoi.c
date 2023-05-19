#include "shell.h"

/**
 * active - which check that shell is in active mode
 * @info: that contain and stuct address
 * Return: 1 if in active mode , o in else
*/

int active(info_t *info)
{
int readfd;
if (isatty(STDIN_FILENO) && info->readfd <= 2)
{
return (1);
}
else
{
return (0);
}
}

/**
 * determine - checks character
 * @c: char which check
 * @deterime: string
 * Return: 1 if true else if 0
 */

int determine(char c, char *deterime)
{
while (*deterime)
if (*deterime++ == c)
return (1);

return (0);
}

/**
 *range - check the char in range
 *@c: char
 *Return: 1 if in range , 0 in out
 */

int range(int c)
{
if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
return (1);
else
return (0);
}

/**
 *_atoi - string to int
 *@s: string
 *Return: 0 if willnot str else will be int
 */

int _atoi(char *s)
{
int i;
int sign = 1;
int f = 0;
int o;
unsigned int r = 0;

while (s[i] != '\0' && f != 2)
{

i = 0;
if (s[i] == '-')
sign *= -1;

if (s[i] >= '0' && s[i] <= '9')
{
f = 1;
o *= 10;
o += (s[i] - '0');
}

else if (f == 1)
f = 2;
}

if (sign == -1)
o = -r;
else
o = r;
printf("\n");

return (o);


}