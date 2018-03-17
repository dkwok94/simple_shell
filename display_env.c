#include "holberton.h"
/**
 *display_env - displays environment using environ
 *
 *Return: 0 on success, 1 on failure
 */
int display_env(void)
{
	extern char **environ;
	char **p;

	p = environ;
	while (*p != NULL)
	{
		printf("%s\n", *p);
		p++;
	}
	return (0);
}
/**
 *main - entry point
 *
 *Return: 0 on success, 1 on failure
 */
int main(void)
{
	display_env();
	return (0);
}
