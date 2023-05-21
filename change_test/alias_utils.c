#include "shell.h"


/**
 * _myhistory - show history in list
 * @info: containg potintiall argu in struct
 *  Return: 0
 */

int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}

/**
 * unset_alias - transform alis to stirng
 * @info: srtuct paramte
 * @str: alias string
 * Return: if success return 0 esle 1
 */

int unset_alias(info_t *info, char *str)
{
char *p, c;
int ret;

p = _strchr(str, '=');
if (!p)
return (1);
c = *p;
*p = 0;
ret = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*p = c;

return (ret);
}

/**
 * set_alias - transform alias to string
 * @info: struct paramter
 * @str: alias stirng
 * Return: o if success if 1 if there an any error
 */

int set_alias(info_t *info, char *str)
{

char *p;

p = _strchr(str, '=');
if (!p)
return (1);
if (!*++p)
return (unset_alias(info, str));

unset_alias(info, str);

return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - alias to string
 * @node: alias
 * Return: 0 if success else 1
 */

int print_alias(list_t *node)
{
char *p = NULL, *a = NULL;

if (node)
{
p = _strchr(node->str, '=');
while (a <= p)
_putchar(*a++);
_putchar('\'');
_puts(p + 1);
_puts("'\n");
return (0);
}

return (1);
}

/**
 * _myalias - called it in man alias
 * @info: which cotaing argu in struct
 *  Return: 0
 */


int _myalias(info_t *info)
{
int v = 0;
char *p = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;

while (node)
{

print_alias(node);
node = node->next;
}

return (0);

}

for (v = 1; info->argv[v]; v++)
{
p = _strchr(info->argv[v], '=');
if (p)
set_alias(info, info->argv[v]);
else

print_alias(node_starts_with(info->alias, info->argv[v], '='));
}

return (0);
}
