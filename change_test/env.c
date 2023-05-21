#include "shell.h"

/**
 * _myenv - show current envireoment
 * @info: contain potential arguments
 * Return: 0
*/

int _myenv(info_t *info)
{
list_t *current = info->env;

for (; current != NULL; current = current->next)
{
_puts(current->str);
_putchar('\n');
}

return (0);
}


/**
 * _getenv - get value of enviroment
 * @info: Struct containing potential arguments
 * @name: env var which name
 * Return: the value
 */


char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *p;

for (; node != NULL; node = node->next)
{
p = starts_with(node->str, name);
if (p && *p)
return (p);
}

return (NULL);
}


/**
 * _mysetenv - make a new environment variable
 * @info: Structure containing potential arguments
 *  Return: 0
 */

int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguments\n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}


/**
 * _myunsetenv - Remove environment variable
 * @info: Structure containing potential arguments
 *  Return: 0
 */

int _myunsetenv(info_t *info)
{
int v;

if (info->argc == 1)
{
_eputs("Too few arguments.\n");
return (1);
}

for (v = 1; v < info->argc; v++)
_unsetenv(info, info->argv[v]);

return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments
 * Return: 0
 */

int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t v;

for (v = 0; environ[v]; v++)
add_node_end(&node, environ[v], 0);
info->env = node;

return (0);
}
