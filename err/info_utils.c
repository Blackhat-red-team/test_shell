#include "shell.h"

/**
 * cledel_inf - initializes info_t struct
 * @info: struct address
 */
void cledel_inf(info_t *info)
{
info->arg = NULL;
info->argv = NULL;
info->path = NULL;
info->argc = 0;
}

/**
 * sett_inf - initializes info_t struct
 * @info: struct address
 * @av: argument vector
 */
void sett_inf(info_t *info, char **av)
{
int v = 0;

info->fname = av[0];
if (info->arg)
{
info->argv = sttiww(info->arg, " \t");
if (!info->argv)
{

info->argv = malloc(sizeof(char *) * 2);
if (info->argv)
{
info->argv[0] = _strtpp(info->arg);
info->argv[1] = NULL;
}
}
for (v = 0; info->argv && info->argv[v]; v++)
;
info->argc = v;

replace_alias(info);
replace_vars(info);
}
}

/**
 * fr_inf - frees info_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void fr_inf(info_t *info, int all)
{
ffrre(info->argv);
info->argv = NULL;
info->path = NULL;
if (all)
{
if (!info->cmd_buf)
free(info->arg);
if (info->env)
frre_lis(&(info->env));
if (info->history)
frre_lis(&(info->history));
if (info->alias)
frre_lis(&(info->alias));
ffrre(info->environ);
info->environ = NULL;
frnpr((void **)info->cmd_buf);
if (info->readfd > 2)
close(info->readfd);
_puuchi(BUF_FLUSH);
}
}
