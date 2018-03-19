#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

/**
 * _setenv - changes or adds an environment variable
 *
 * @name: name of the variable to add
 * @value: value of the variable name
 * @overwrite: if overwite is non zero - change value of name, if it is zero -
 * value of name is not changed.
 *
 * Return: 0 if success, -1 on error
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *es;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL ||
	value == NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	if (getenv(name) != NULL && overwrite == 0)
		return (0);
	unsetenv(name);
	es = malloc(strlen(name) + strlen(value) + 2);
	if (es == NULL)
		return (-1);
	strcpy(es, name);
	strcat(es, "=");
	strcat(es, value);
	if (putenv(es) != 0)
		return (-1);
	else
		return (0);
}
