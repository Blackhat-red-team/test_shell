#include "shell.h"

/**
 **_cpsrting - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_cpsrting(char *dest, char *src, int n)
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
 **_copncatsr - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_copncatsr(char *dest, char *src, int n)
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
 **_fidchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_fidchr(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
return (s);
s++;
}

return (NULL);
}
