#include "shell.h"

/**
 *_eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int m = 0;

	if (!str)
		return;
	while (str[m] != '\0')
	{
		_eputchar(str[m]);
		m++;
	}
}

/**
 * _eputchar - writes the character g to stderr
 * @g: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char g)
{
	static int m;
	static char buf[WRITE_BUF_SIZE];

	if (g == BUF_FLUSH || m >= WRITE_BUF_SIZE)
	{
		write(2, buf, m);
		m = 0;
	}
	if (g != BUF_FLUSH)
		buf[m++] = g;
	return (1);
}

/**
 * _putfd - writes the character g to given fd
 * @g: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char g, int fd)
{
	static int m;
	static char buf[WRITE_BUF_SIZE];

	if (g == BUF_FLUSH || m >= WRITE_BUF_SIZE)
	{
		write(fd, buf, m);
		m = 0;
	}
	if (g != BUF_FLUSH)
		buf[m++] = g;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int m = 0;

	if (!str)
		return (0);
	while (*str)
	{
		m += _putfd(*str++, fd);
	}
	return (m);
}
