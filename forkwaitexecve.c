#include "holberton.h"

/**
 *childcommand - runs a line of code 5 times
 *@av: the argv array of strings
 *
 *Return: 0 on success
 */
int childcommand(char *av[])
{
	int i = 0;
	pid_t my_pid;

	while (i < 5)
	{
		my_pid = fork();
		if (my_pid == -1)
			return (-1);
		if (my_pid == 0)
		{
			printf("\nITERATION: %d\n", i + 1);
			execve(av[0], av, NULL);
		}
		else
			wait(NULL);
		i++;
	}
	return (0);
}

/**
 *main - entry point
 *
 *Description: fills an array with strings of a command and runs them
 *5 times in children processes
 *Return: 0 on success
 */
int main(void)
{
	char *argv[4];

	argv[0] = "/bin/ls";
	argv[1] = "-1";
	argv[2] = ".";
	argv[3] = NULL;
	childcommand(argv);
	return (0);
}
