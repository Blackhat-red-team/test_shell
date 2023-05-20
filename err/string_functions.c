#include "shell.h"

/**
 * _stles - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _stles(char *s)
{
int v = 0;

if (!s)
return (0);

for (; *s != '\0'; s++)
v++;
return (v);
}


/**
 * _stcmm - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _stcmm(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}

/**
 * stres_wi - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *stres_wi(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
 * _stcet - concatenates two strings
 * @dest: the destination bufes
 * @src: the source bufes
 *
 * Return: pointer to destination bufes
 */
char *_stcet(char *dest, char *src)
{
char *ret = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
