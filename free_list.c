#include "holberton.h"
/**
 *free_list - frees a list_t list
 *@head: head of the linked list
 *
 *Return: void
 */
void free_list(path_t *head)
{
	path_t *nextnode;

	while (head != NULL)
	{
		nextnode = head->next;
		free(head->directory);
		free(head);
		head = nextnode;
	}
}
