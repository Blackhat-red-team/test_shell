#include "shell.h"

/**
 * _myhist - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhist(info_t *info)
{
prii_liss(info->history);
return (0);
}

/**
 * unseters_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unseters_alias(info_t *info, char *str)
{
char *p, c;
int ret;

p = _fidchr(str, '=');
if (!p)
return (1);
c = *p;
*p = 0;
ret = rm_nod_a_ind(&(info->alias),
gett_nodd_in(info->alias, nodd_st_wi(info->alias, str, -1)));
*p = c;
return (ret);
}

/**
 * set_alis - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alis(info_t *info, char *str)
{
char *p;

p = _fidchr(str, '=');
if (!p)
return (1);
if (!*++p)
return (unseters_alias(info, str));

unseters_alias(info, str);
return (adn_no_ed(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias_string - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias_string(list_t *node)
{
char *p = NULL, *a = NULL;

if (node)
{
p = _fidchr(node->str, '=');
while (a <= p)
_puuchi(*a++);
_puuchi('\'');
_puuss(p + 1);
_puuss("'\n");
return (0);
}
return (1);
}

/**
 * _myhelpalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelpalias(info_t *info)
{
int v = 0;
char *p = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias_string(node);
node = node->next;
}
return (0);
}
for (v = 1; info->argv[v]; v++)
{
p = _fidchr(info->argv[v], '=');
if (p)
set_alis(info, info->argv[v]);
else
print_alias_string(nodd_st_wi(info->alias, info->argv[v], '='));
}

return (0);
}
