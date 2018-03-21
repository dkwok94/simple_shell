#include "holberton.h"
/**
 *fill_list - fills an empty linked list with PATH variable contents
 *@str: the PATH variable
 *@list: pointer to the empty linked list
 *
 *Return: pointer to the filled linked list
 */
path_t *fill_list(char *str, path_t *list)
{
	path_t *ptr, *head;
	char *dir;
	int i = 0, j = 0, stcnt = 0, dirlen = 0;

	if (str ==  NULL)
		return (NULL);
	if (list == NULL)
		return (NULL);
	head = list;
	ptr = head;
	while (ptr != NULL)
	{
		if (str[i] == ':' || str[i] == '\0')
		{
			if (str[i] != '\0')
				i++;
			dir = malloc(sizeof(char) * dirlen + 2);
			if (dir == NULL)
				return (NULL);
			while (str[stcnt] != ':' && str[stcnt] != '\0')
			{
				dir[j] = str[stcnt];
				stcnt++;
				j++;
			}
			dir[j++] = '/';
			dir[j] = '\0';
			stcnt = i;
			j = 0;
			ptr->directory = dir;
			ptr = ptr->next;
		}

		else
		{
			dirlen++;
			i++;
		}
	}
	return (head);
}
