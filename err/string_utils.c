#include "shell.h"

/**
 * _stcop - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_stcop(char *dest, char *src)
{
int v = 0;

if (dest == src || src == 0)
return (dest);
while (src[v])
{
dest[v] = src[v];
v++;
}
dest[v] = 0;
return (dest);
}

/**
 * _strtpp - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strtpp(const char *str)
{
int length = 0;
char *ret;

if (str == NULL)
return (NULL);
while (*str++)
length++;
ret = malloc(sizeof(char) * (length + 1));
if (!ret)
return (NULL);
for (length++; length--;)
ret[length] = *--str;
return (ret);
}

/**
 *_puuss - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puuss(char *str)
{
int v = 0;

if (!str)
return;
while (str[v] != '\0')
{
_puuchi(str[v]);
v++;
}
}

/**
 * _puuchi - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _puuchi(char c)
{
static int v;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || v >= WRITE_BUF_SIZE)
{
write(1, buf, v);
v = 0;
}
if (c != BUF_FLUSH)
buf[v++] = c;
return (1);
}
