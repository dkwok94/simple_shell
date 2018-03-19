#include "holberton.h"
/**
 *executeprog - executes a line of code in the shell
 *@array: the array of strings to execute
 *
 *Return: 0 on success, -1 on failure
 */
int executeprog(char **array)
{
	pid_t my_pid;
	int signal;
	struct stat status;

	if (stat(array[0], &status) == -1)
	{
		write(1, "./shell: No such file or directory\n", 35);
		return (-1);
	}
	my_pid = fork();
	if (my_pid == -1)
	{
		write(1, "Error", 5);
		return (-1);
	}

	if (my_pid == 0)
		execve(array[0], array, NULL);
	else
		wait(&signal);

	return (0);
}
