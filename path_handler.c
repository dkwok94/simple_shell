#include "holberton.h"
/**
 *path_handler - iterates through PATH variable and concatenates
 *command into it
 *@str: string to concatenate
 *@env: the environment variable
 *
 *Return: pointer to concatenated string
 */
char *path_handler(char *str, char **env)
{
	char *path, *concat;
	path_t *list, *tmp;
	struct stat st;

	path = _getenv("PATH", env);
	list = create_ll(path);
	if (list == NULL)
		return (NULL);
	list = fill_list(path, list);
	if (list == NULL)
		return (NULL);
	tmp = list;

	while (tmp != NULL)
	{
		concat = str_concat(tmp->directory, str);
		if (stat(concat, &st) == 0)
			return (concat);
		tmp = tmp->next;
	}
	free(list);
	free(concat);
	return (NULL);
}
