#include "shell.h"

/**
 * is_chain - test if chain palamter
 * @info: parmater struct
 * @buf: char of buffer
 * @p: addresss of buffer char
 * Return: chain paramter return 1 else 0
 */

int is_chain(info_t *info, char *buf, size_t *p)
{


size_t j = *p;

if (buf[j] == '|' && buf[j + 1] == '|')
{
buf[j] = 0;
j++;
info->cmd_buf_type = CMD_OR;
}

else if (buf[j] == '&' && buf[j + 1] == '&')
{
buf[j] = 0;
j++;
info->cmd_buf_type = CMD_AND;
}

else if (buf[j] == ';')
{
buf[j] = 0;
info->cmd_buf_type = CMD_CHAIN;
}

else
return (0);
*p = j;
return (1);
}

/**
 * check_chain - checks we should continue chaining go last status
 * @info: the parameter struct
 * @buf: the char buff
 * @p: address of current position in buffer
 * @v: starting position buffer
 * @len: length of buffer
 * Return: Void
 */

void check_chain(info_t *info, char *buf, size_t *p, size_t v, size_t len)
{
size_t j = *p;

if (info->cmd_buf_type == CMD_AND)
{
if (info->status)
{
buf[v] = 0;
j = len;
}
}
if (info->cmd_buf_type == CMD_OR)
{
if (!info->status)
{
buf[v] = 0;
j = len;
}
}

*p = j;
}

/**
 * replace_alias - replaces an aliases in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */

int replace_alias(info_t *info)
{
int i;
list_t *node;
char *p;

for (i = 0; i < 10; i++)
{
node = node_starts_with(info->alias, info->argv[0], '=');
if (!node)
return (0);
free(info->argv[0]);
p = _strchr(node->str, '=');
if (!p)
return (0);
p = _strdup(p + 1);
if (!p)
return (0);
info->argv[0] = p;
}
return (1);
}


/**
 * replace_vars - replaces vars in the tokenized string
 * @info: the parameter struct
 * Return: 1 if replaced, 0 otherwise
 */

int replace_vars(info_t *info)
{
int v = 0;
list_t *node;

while (info->argv[v])

{
if (info->argv[v][0] != '$' || !info->argv[v][1])
{
v++;
continue;
}

if (!_strcmp(info->argv[v], "$?"))
{
replace_string(&(info->argv[v]),
_strdup(convert_number(info->status, 10, 0)));
v++;
continue;
}
if (!_strcmp(info->argv[v], "$$"))
{
replace_string(&(info->argv[v]), _strdup(convert_number(getpid(), 10, 0)));
v++;
continue;
}

node = node_starts_with(info->env, &info->argv[v][1], '=');
if (node)
{
replace_string(&(info->argv[v]), _strdup(_strchr(node->str, '=') + 1));
}
else
{
replace_string(&info->argv[v], _strdup(""));
}

v++;
}

return (0);
}

/**
 * replace_string - replaces string
 * @old: address of old string
 * @new: new string
 * Return: if 1 replace, esle 0
 */


int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}
