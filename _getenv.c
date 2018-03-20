#include "holberton.h"
/**
 *_getenv - looks at environment variable and returns a pointer to string
 *@name: the name of the environmental variable
 *
 *Return: pointer to the environmental variable
 */
char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0;
	int j = 0;

	while (environ[i] != NULL)
	{
		while (environ[i][j] == name[j])
			j++;
		if (environ[i][j] == '=')
		{
			j++;
			return (&(environ[i][j]));
		}
		i++;
		j = 0;
	}
	write(STDOUT_FILENO, "Environment variable not found", 30);
	return (NULL);
}

/**
 *main - entry point
 *
 *Description: Tests the code
 *Return: 0 when successful, 1 if failed
 *
int main(void)
{
	char *envvar;

	envvar = _getenv("PWD");
	if (envvar == NULL)
	{
		printf("Could not find environmental variable\n");
		return (1);
	}
	printf("Environmental variable: %s\n", envvar);

	envvar = _getenv("LS_COLORS");
	if (envvar == NULL)
	{
		printf("Could not find environmental variable\n");
		return (1);
	}
	printf("Environmental variable: %s\n", envvar);

	envvar = _getenv("PATH");
	if (envvar == NULL)
	{
		printf("Could not find environmental variable\n");
		return (1);
	}
	printf("Environmental variable: %s\n", envvar);

	print_path(envvar);
	return (0);
}
*/
