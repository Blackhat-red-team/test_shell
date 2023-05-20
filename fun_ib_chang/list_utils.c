#include "shell.h"

/**
 * list_len - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
size_t v = 0;

for (; h; h = h->next)
v++;

return (v);
}


/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
list_t *node = head;
size_t v = list_len(head), j;
char **strs;
char *str;

if (!head || !v)
return (NULL);

strs = malloc(sizeof(char *) * (v + 1));
if (!strs)
return (NULL);

v = 0;
while (node)
{
str = malloc(_strlen(node->str) + 1);
if (!str)
{
for (j = 0; j < v; j++)
free(strs[j]);
free(strs);
return (NULL);
}

str = _strcpy(str, node->str);
strs[v] = str;
node = node->next;
v++;
}

strs[v] = NULL;
return (strs);
}



/**
 * print_list - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
size_t v = 0;

for (; h; h = h->next, v++)
{
_puts(convert_snum(h->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(h->str ? h->str : "(nil)");
_puts("\n");
}

return (v);
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
char *p = NULL;

for (; node; node = node->next)
{
p = starts_with(node->str, prefix);
if (p && ((c == -1) || (*p == c)))
return (node);
}

return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
size_t v = 0;

for (; head; head = head->next, v++)
{
if (head == node)
return (v);
}

return (-1);
}
