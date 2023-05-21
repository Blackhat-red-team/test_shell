#include "shell.h"

/**
 **_strncpy - copy an string
 *@dest: destination string to be copied to
 *@src: source string
 *@n: amount of char which copied
 *Return: concatenat string
 */

char *_strncpy(char *dest, char *src, int n)
{
char *s = dest;
int v = 0;

while (src[v] != '\0' && v < n - 1)
{
dest[v] = src[v];
v++;
}


if (v < n)
{
int j = v;
while (j < n)
{
dest[j] = '\0';
j++;
}
}

return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: first string
 *@src: second string
 *@n: amount of bytes
 *Return: concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
char *s = dest;
int v = 0;
int j = 0;

while (dest[v] != '\0')
{

v++;

}

while (src[j] != '\0' && j < n)
{
dest[v + j] = src[j];
j++;
}

if (j < n)
{
dest[v + j] = '\0';
}

return (s);
}

/**
 **_strchr - locates a char in a string
 *@s: string to be parsed
 *@c: character to look for
 *Return: s  pointer to the memory area
 */

char *_strchr(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
return (s);
s++;
}

return (NULL);
}
