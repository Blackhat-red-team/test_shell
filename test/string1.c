#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int m;

	if (dest == src || src == NULL)
		return (dest);

	for (m = 0; src[m]; m++)
		dest[m] = src[m];

	dest[m] = '\0';
	return (dest);
}


/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);

	for (; str[length]; length++)
		;

	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);

	for (length = 0; str[length]; length++)
		ret[length] = str[length];

	ret[length] = '\0';
	return (ret);
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	if (!str)
		return;

	for (; *str; str++)
		_putchar(*str);
}


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int m;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || m >= WRITE_BUF_SIZE)
	{
		write(1, buf, m);
		m = 0;
	}
	if (c != BUF_FLUSH)
		buf[m++] = c;
	return (1);
}
