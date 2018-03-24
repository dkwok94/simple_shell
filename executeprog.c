#include "holberton.h"
/**
 *check_builtins - implement exit, buit-in, that exits the shell
 *@array: the array of strings to execute
 *@env: the environment variable
 *
 *Return: 0 when successfully running a builtin, 1 when builtin not found
 */
int check_builtins(char **array, char **env)
{
	if (_strcmp((array[0]), "exit") == 0)
		return (exit_op(array));

	else if (_strcmp((array[0]), "cd") == 0)
		return (cd_op(array, env));

	else if (_strcmp((array[0]), "env") == 0)
		return (env_op(env));

	else
		return (1);
}
/**
 *executeprog - executes a line of code in the shell
 *@array: the array of strings to execute
 *@env: the environment variable
 *@argv: the array of command line argument strings
 *
 *Return: 0 on success, -1 on failure
 */
int executeprog(char **array, char **env, char **argv)
{
	pid_t my_pid;
	char *concat;
	int signal;
	struct stat status;

	if (check_builtins(array, env) == 0)
		return (0);
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
				no_file_error(argv);
			execve(array[0], array, NULL);
		}
		else
		{
			concat = path_handler(array[0], env);
			if (concat == NULL)
				no_file_error(argv);
			execve(concat, array, NULL);
		}
	}
	else
		wait(&signal);

	return (0);
}
