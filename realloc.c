#include "shell.h"

/**
 **_memset - fills memory with a const byte
 *@s: memory of areay
 *@b: the byte
 *@n: amount of byte will be fill
 *Return: s to pointer
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int q;

for (q = 0; q < n; q++)

s[q] = b;

return (s);

}

/**
 * ffree - frees strings
 * @pp: string
 */
void ffree(char **pp)
{

char **c = pp;

if (pp == NULL)
return;

while (*pp)

free(*pp++);

free(c);
}


/**
 * _realloc - block of memory
 * @ptr: previous malloc
 * @old_size: size previous block
 * @new_size: size of new bllock
 * Return: pointter to make block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{

char *o;

if (!ptr)

return (malloc(new_size));
if (!new_size)

return (free(ptr), NULL);

if (new_size == old_size)
return (ptr);

o = malloc(new_size);
if (o == NULL)
return (NULL);

old_size = old_size < new_size ? old_size : new_size;
while (old_size--)

o[old_size] = ((char *)ptr)[old_size];

free(ptr);
return (o);
}
