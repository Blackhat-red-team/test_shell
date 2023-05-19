#include "shell.h"



/**
 * bfree - pointer is free an nnnnulll
 * @ptr: addre of free pointer
 * Return: 1 if freed if not return 0
 */

int bfree(void **ptr)
{

if (ptr && *ptr)
{
free(*ptr);

*ptr = NULL;

return (1);

}
return (0);
}
