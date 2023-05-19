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
 * is_del - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_del(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_range - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _range(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int m, sign = 1, flag = 0, output;
	unsigned int result = 0;

m = 0;
while (s[m] != '\0' && flag != 2) {
    if (s[m] == '-')
        sign *= -1;

    if (s[m] >= '0' && s[m] <= '9') {
        flag = 1;
        result *= 10;
        result += (s[m] - '0');
    }
    else if (flag == 1)
        flag = 2;

    m++;
}


	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
