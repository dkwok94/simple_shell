#include "holberton.h"

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

int main(void)
{
	path_t *head;
	int nodes = 0;

	head = create_ll("/bin/usr:/bin/lol:/bin:/hello:/hi");

	while (head != NULL)
	{
		nodes++;
		head = head->next;
	}
	printf("NUMBER OF NODES: %d\n", nodes);
	return (0);
}
