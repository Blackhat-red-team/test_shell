#include "shell.h"

/**
 **_memfill - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memfill(char *s, char b, unsigned int n)
{
unsigned int v;

for (v = 0; v < n; v++)
s[v] = b;
return (s);
}

/**
 * ffrre - frees a string of strings
 * @pp: string of strings
 */
void ffrre(char **pp)
{
char **a = pp;

if (!pp)
return;
while (*pp)
free(*pp++);
free(a);
}

/**
 * _reeloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @od_si: byte size of previous block
 * @nw_si: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_reeloc(void *ptr, unsigned int od_si, unsigned int nw_si)
{
char *p;

if (!ptr)
return (malloc(nw_si));
if (!nw_si)
return (free(ptr), NULL);
if (nw_si == od_si)
return (ptr);

p = malloc(nw_si);
if (!p)
return (NULL);

od_si = od_si < nw_si ? od_si : nw_si;
while (od_si--)
p[od_si] = ((char *)ptr)[od_si];
free(ptr);
return (p);
}
