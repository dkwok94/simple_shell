#include "holberton.h"
/**
 *env_environ - prints the address of env and environ for comparison
 *@env: array that holds environment variable strings
 *
 *Return: 0 when successful, 1 if failed
 */
int env_environ(char **env)
{
	extern char **environ;

	printf("Address of env: %p\n", *env);
	printf("Address of environ: %p\n", *environ);
	if (*env == *environ)
		printf("They are the SAME!\n");
	else
		printf("They are different!\n");
	return (0);
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	env_environ(env);
	return (0);
}
