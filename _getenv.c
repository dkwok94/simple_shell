#include "holberton.h"
/**
 *_getenv - looks at environment variable and returns a pointer to string
 *@name: the name of the environmental variable
 *@env: the environment variable
 *
 *Return: pointer to the environmental variable
 */
char *_getenv(const char *name, char **env)
{
	int i = 0;
	int j = 0;

	while (env[i] != NULL)
	{
		while (env[i][j] == name[j])
			j++;
		if (env[i][j] == '=')
		{
			j++;
			return (&(env[i][j]));
		}
		i++;
		j = 0;
	}
	write(STDOUT_FILENO, "Environment variable not found", 30);
	return (NULL);
}
