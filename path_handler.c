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

	if (str == NULL)
		return (NULL);
	if (env == NULL || *env == NULL)
		return (NULL);
	path = _getenv("PATH", env);
	if (path == NULL)
	{
		write(STDOUT_FILENO, "PATH not found", 14);
		_exit(0);
	}
	list = create_ll(path);
	if (list == NULL)
	{
		write(STDOUT_FILENO, "Issues with PATH", 16);
		_exit(0);
	}
	list = fill_list(path, list);
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
