#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

/**
 * _strlen - return the string lenght
 *
 * @str: pointer to a first element of the string str
 *
 * Return: lenght of the string str
 */
int _strlen(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _unsetenv - deletes the variable name from the environment
 *
 * @name: name of the variable to delete
 *
 * Return: 0 if success, -1 on error
 */
int _unsetenv(const char *name)
{
	extern char **environ;
	char **ep, **sp;
	size_t len;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	len = _strlen(name);
	for (ep = environ; *ep != NULL; )
		if (strncmp(*ep, name, len) == 0 && (*ep)[len] == '=')
		{
			for (sp = ep; *sp != NULL; sp++)
				*sp = *(sp + 1);
		}
		else
			ep++;
	return (0);
}
