#include "holberton.h"
/**
 *create_ll - creates an empty linked list the size of the path variable
 *@str: the PATH variable
 *
 *Return: a pointer to the empty array
 */
path_t *create_ll(char *str)
{
	int i = 0;
	int nodes = 1;
	path_t *node, *head, *tmp, *end;

	tmp = malloc(sizeof(path_t));
	head = tmp;

	end = malloc(sizeof(path_t));
	end->next = NULL;

	while (str[i] != '\0')
	{
		if (str[i] == ':')
			nodes++;
		i++;
	}

	while ((nodes - 2) > 0)
	{
		node = malloc(sizeof(path_t));
		tmp->next = node;
		tmp = tmp->next;
		nodes--;
	}
	tmp->next = end;
	return (head);
}

/**
 *main - entry point
 *
 *Description: test the linked list code
 *Return: 0 on success
 */
int main(void)
{
	path_t *head, *filledlist, *tmp;
	int nodes = 0;
	char *copy, *str;

	str = "/bin/usr:/bin/lol:/bin:/hello:/hi";
	copy = _strdup(str);
	head = create_ll(copy);
	tmp = head;

	while (tmp != NULL)
	{
		nodes++;
		tmp = tmp->next;
	}
	printf("NUMBER OF NODES: %d\n", nodes);
	filledlist = fill_list(copy, head);
	while (filledlist != NULL)
	{
		printf("%s\n", filledlist->directory);
		filledlist = filledlist->next;
	}
	return (0);
}
