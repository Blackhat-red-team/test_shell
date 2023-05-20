#include "shell.h"

/**
 *_eppu - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eppu(char *str)
{
int v = 0;

if (!str)
return;
while (str[v] != '\0')
{
_epitch(str[v]);
v++;
}
}

/**
 * _epitch - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _epitch(char c)
{
static int v;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || v >= WRITE_BUF_SIZE)
{
write(2, buf, v);
v = 0;
}
if (c != BUF_FLUSH)
buf[v++] = c;
return (1);
}

/**
 * _puiuf - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _puiuf(char c, int fd)
{
static int v;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || v >= WRITE_BUF_SIZE)
{
write(fd, buf, v);
v = 0;
}
if (c != BUF_FLUSH)
buf[v++] = c;
return (1);
}

/**
 *_puqsd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _puqsd(char *str, int fd)
{
int v = 0;

if (!str)
return (0);
while (*str)
{
v += _puiuf(*str++, fd);
}
return (v);
}
