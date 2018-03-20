#include "holberton.h"
/**
  *path_linkedlist - turns PATH directories into a linked list
  *@str: PATH variable
  *
  *Return: void
  */
void path_linkedlist(char *str)
{
        int i = 0, j = 0, len = 0, counter = 0, isfirstnode = 1, fillstart = 0;
	path_t *node, *head, *it;
	char *dir;

        while (str[i] != '\0')
        {
                if (str[i] == ':' || str[i] == '\0')
		{
			node = malloc(sizeof(path_t));
			dir = malloc(sizeof(char) * len + 1);
			while (str[fillstart] != ':' && str[fillstart] != '\0')
			{
				dir[j] = str[fillstart];
				fillstart++;
				j++;
			}
			dir[j] = '\0';
			len = 0;
			node.directory = dir;
			if (isfirstnode == 1)
			{
				head = node;
				it = head;
				isfirstnode = 0;
			}
			else
			{
				it->next = node;
				it = it->next;
			}
		}
                else
			len++;
                i++;
		fillstart = i;
        }
}
