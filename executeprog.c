#include "holberton.h"

/**
 *check_builtins - implement exit, buit-in, that exits the shell
 *@array: the array of strings to execute
 *
 */
void check_builtins(char **array, char **env)
{
	int i = 0;
	int length = 0;

	if (_strcmp((array[0]), "exit") == 0)
	{
		free(array);
		exit(0);
	}
	else if (_strcmp((array[0]), "cd") == 0)
	{
		;
	}
	else if (_strcmp((array[0]), "env") == 0)
	{
		while (env[i] != NULL)
		{
			length = _strlen(env[i]);
			write(STDOUT_FILENO, env[i], length);
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
	}
}
/**
 *executeprog - executes a line of code in the shell
 *@array: the array of strings to execute
 *
 *Return: 0 on success, -1 on failure
 */
int executeprog(char **array, char **env)
{
	pid_t my_pid;
	char *concat;
	int signal;
	struct stat status;

	check_builtins(array, env);
	my_pid = fork();
	if (my_pid == -1)
	{
		write(STDOUT_FILENO, "Error", 5);
		return (-1);
	}

	if (my_pid == 0)
	{
		if (array[0][0] == '/')
		{
			if (stat(array[0], &status) == -1)
			{
				write(STDOUT_FILENO, "./shell: No such file or directory\n", 35);
				return (-1);
			}

			execve(array[0], array, NULL);
		}
		else
		{
			concat = path_handler(array[0]);
			if (concat == NULL)
			{
				write(STDOUT_FILENO, "./shell: No such file or directory\n", 35);
				return (-1);
			}
			execve(concat, array, NULL);
		}
	}
	else
		wait(&signal);

	return (0);
}
