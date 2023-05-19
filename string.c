#include "shell.h"

/**
 * _strlen - returns a string's length
 * @s: checking the length of the string
 *
 * Return: integer string length
 */
int _strlen(char *s)
{
int z = 0;

if (!s)
return (0);

while (*s++)
z++;
return (z);
}

/**
 * _strcmp - compares the lexical patterns of two different languages.
 * @s1: the opening strang
 * @s2: second strangulation
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
for (; *s1 && *s2; s1++, s2++)
{
if (*s1 != *s2)
return (*s1 - *s2);
}

if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - determines if the needle begins with haystack
 * @haystack: searching a string
 * @needle: the necessary substring
 *
 * Return: address of the following haystack char, or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
for (; *needle; needle++, haystack++)
{
if (*needle != *haystack)
return (NULL);
}
return ((char *)haystack);

}

/**
 * _strcat - concatenates two strings
 * @dest: the final buffer
 * @src: the origin buffer
 *
 * Return: pointer to the desired buffer
 */
char *_strcat(char *dest, char *src)
{
char *ret = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
