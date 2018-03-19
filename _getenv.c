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
			return (environ[i]);
		i++;
		j = 0;
	}
	return (NULL);
}
/**
 *_strlen - calculates the length of a string
 *@buf: buffer to count length of strings
 *
 *Return: the length of the string
 */
int _strlen(char *buf)
{
	int i = 0;

	while (buf[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 *printpath - prints each entry of path
 *@path: pointer to the path variable
 *
 *Return: 0 upon success
 */
int printpath(char *path)
{
	char buf[1024];
	int i = 0, j = 0, length;
	while (path[i] != '\0')
	{
		if (i == 0)
		{
			while (path[i] != '=')
				i++;
			i++;
		}
		while (path[i] != ':' && path[i] != '\0')
		{
			buf[j] = path[i];
			i++;
			j++;
		}
		if (path[i] == ':')
			i++;
		buf[j++] = '\n';
		buf[j] = '\0';
		length = _strlen(buf);
		write(1, buf, length);
		j = 0;
	}
	return (0);
}
/**
 *main - entry point
 *
 *Description: Tests the code
 *Return: 0 when successful, 1 if failed
 */
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

	printpath(envvar);
	return (0);
}
