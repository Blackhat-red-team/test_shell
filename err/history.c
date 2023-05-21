#include "shell.h"

/**
 * get_histret_fi - gets the history file
 * @info: parameter struct
 *
 * Return: allocated string containg history file
 */

char *get_histret_fi(info_t *info)
{
char *buf, *der;

der = _geevv(info, "HOME=");
if (!der)
return (NULL);
buf = malloc(sizeof(char) * (_stles(der) + _stles(HIST_FILE) + 2));
if (!buf)
return (NULL);
buf[0] = 0;
_stcop(buf, der);
_stcet(buf, "/");
_stcet(buf, HIST_FILE);
return (buf);
}

/**
 * writecre_apphistory - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int writecre_apphistory(info_t *info)
{
ssize_t fd;
char *filename = get_histret_fi(info);
list_t *node = NULL;

if (!filename)
return (-1);

fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filename);
if (fd == -1)
return (-1);
for (node = info->history; node; node = node->next)
{
_puqsd(node->str, fd);
_puiuf('\n', fd);
}
_puiuf(BUF_FLUSH, fd);
close(fd);
return (1);
}

/**
 * red_hist - reads history from file
 * @info: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int red_hist(info_t *info)
{
int i, last = 0, linecount = 0;
ssize_t fd, rdlen, fsize = 0;
struct stat st;
char *buf = NULL, *filename = get_histret_fi(info);

if (!filename)
return (0);

fd = open(filename, O_RDONLY);
free(filename);
if (fd == -1)
return (0);
if (!fstat(fd, &st))
fsize = st.st_size;
if (fsize < 2)
return (0);
buf = malloc(sizeof(char) * (fsize + 1));
if (!buf)
return (0);
rdlen = read(fd, buf, fsize);
buf[fsize] = 0;
if (rdlen <= 0)
return (free(buf), 0);
close(fd);
for (i = 0; i < fsize; i++)
if (buf[i] == '\n')
{
buf[i] = 0;
bud_addhs_ls(info, buf + last, linecount++);
last = i + 1;
}
if (last != i)
bud_addhs_ls(info, buf + last, linecount++);
free(buf);
info->histcount = linecount;
while (info->histcount-- >= HIST_MAX)
rm_nod_a_ind(&(info->history), 0);
rem_his(info);
return (info->histcount);
}

/**
 * bud_addhs_ls - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: bufes
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int bud_addhs_ls(info_t *info, char *buf, int linecount)
{
list_t *node = NULL;

if (info->history)
node = info->history;
adn_no_ed(&node, buf, linecount);

if (!info->history)
info->history = node;
return (0);
}

/**
 * rem_his - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int rem_his(info_t *info)
{
list_t *node = info->history;
int i = 0;

while (node)
{
node->num = i++;
node = node->next;
}
return (info->histcount = i);
}
