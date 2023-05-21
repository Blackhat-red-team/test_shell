#include "shell.h"

/**
 * get_environ - returns the string array copy of our environ
 * @info: Structure containing potential arguments
 * Return: 0
 */


char **get_environ(info_t *info)
{
if (!info->environ || info->env_changed)
{
info->environ = list_to_strings(info->env);
info->env_changed = 0;
}


return (info->environ);
}


/**
 * _unsetenv - Remove an environment variable
 * @info: structure containing potential arguments
 *  Return: 1 if deleter else 0
 * @var: the string env var property
 */

int _unsetenv(info_t *info, char *var)
{
list_t *node = info->env;
size_t v = 0;
char *p;

if (!node || !var)
return (0);

for (; node; node = node->next, v++)
{
p = starts_with(node->str, var);
if (p && *p == '=')
{
info->env_changed = delete_node_at_index(&(info->env), v);
v = 0;
node = info->env;
continue;
}
}
return (info->env_changed);
}


/**
 * _setenv - initialize a new environment variable
 * @info: Structure containing potential arguments
 * @var: the string env var property
 * @value: the string env var value
 *  Return: 0
 */


int _setenv(info_t *info, char *var, char *value)
{
char *buf = NULL;
list_t *node;
char *p;

if (!var || !value)
return (0);

buf = malloc(_strlen(var) + _strlen(value) + 2);
if (!buf)
return (1);
_strcpy(buf, var);
_strcat(buf, "=");
_strcat(buf, value);
node = info->env;
for (; node; node = node->next)
{
p = starts_with(node->str, var);
if (p && *p == '=')
{

free(node->str);
node->str = buf;
info->env_changed = 1;
return (0);
}
}

add_node_end(&(info->env), buf, 0);
free(buf);
info->env_changed = 1;
return (0);
}
