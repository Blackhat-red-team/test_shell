#include "shell.h"

/**
 * _mievv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
*/
int _mievv(info_t *info)
{
list_t *current = info->env;

for (; current != NULL; current = current->next)
{
_puuss(current->str);
_puuchi('\n');
}

return (0);
}

/**
 * _geevv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_geevv(info_t *info, const char *name)
{
list_t *node = info->env;
char *p;

for (; node != NULL; node = node->next)
{
p = stres_wi(node->str, name);
if (p && *p)
return (p);
}

return (NULL);
}
/**
 * _miserevv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _miserevv(info_t *info)
{
if (info->argc != 3)
{
_eppu("Incorrect number of arguments\n");
return (1);
}
if (_initenva(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}


/**
 * _miunsotevv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _miunsotevv(info_t *info)
{
int v;

if (info->argc == 1)
{
_eppu("Too few arguments.\n");
return (1);
}

for (v = 1; v < info->argc; v++)
_rmunsetenv(info, info->argv[v]);

return (0);
}

/**
 * populate_evv_li - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_evv_li(info_t *info)
{
list_t *node = NULL;
size_t v;

for (v = 0; environ[v]; v++)
adn_no_ed(&node, environ[v], 0);
info->env = node;

return (0);
}
