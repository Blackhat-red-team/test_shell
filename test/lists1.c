#include "shell.h"

/**
 * list_len - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
	size_t m;

	for (m = 0; h; m++, h = h->next)
		;

	return m;
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
	size_t m = list_len(head), j;
	char **strs;
	char *str;

	size_t len = list_len(head);
	if (!head || !len)
		return NULL;

	strs = malloc(sizeof(char *) * (len + 1));
	if (!strs)
		return NULL;

	m = 0;
	while (node)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			j = 0;
			while (j < m)
			{
				free(strs[j]);
				j++;
			}
			free(strs);
			return NULL;
		}

		str = _strcpy(str, node->str);
		strs[m] = str;

		node = node->next;
		m++;
	}

	strs[m] = NULL;
	return strs;
}




/**
 * print_list - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t m = 0;

	for (; h; h = h->next, m++)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
	}

	return m;
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
			return node;
	}

	return NULL;
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
	size_t m = 0;

	for (; head; head = head->next, m++)
	{
		if (head == node)
			return m;
	}

	return -1;
}
