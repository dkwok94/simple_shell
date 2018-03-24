#include "holberton.h"
/**
 *check_builtins - implement exit, buit-in, that exits the shell
 *@array: the array of strings to execute
 *
 *Return: 0 when successfully running a builtin, 1 when builtin not found
 */
int check_builtins(char **array, char **env)
{
	int i = 0, j = 0, num;
	int length = 0;
	char cwd[1024];
	char *newdir;

	if (_strcmp((array[0]), "exit") == 0)
	{
		if (array[1] == NULL)
		{
			free(array);
			exit(0);
		}

		else
		{
			num = _atoi(array[1]);
			if (num == -1)
			{
				write(STDOUT_FILENO, "./hsh: 1: exit: Illegal number: ", 32);
				while (array[1][j] != '\0')
					j++;
				write(STDOUT_FILENO, array[1], j);
				write(STDOUT_FILENO, "\n", 1);
				return (0);
			}
			free(array);
			exit(num);
		}
	}
	else if (_strcmp((array[0]), "cd") == 0)
	{
		if (array[1] == NULL)
		{
			if(chdir(_getenv("HOME")) == -1)
			{
				perror("./hsh");
				perror("cd");
				write(STDOUT_FILENO, "can't cd to home\n", 17);
			}
		}
		else
		{
			getcwd(cwd, 1024);
			while (cwd[i] != '\0')
				i++;
			cwd[i++] = '/';
			cwd[i] = '\0';
			newdir = str_concat(cwd, array[1]);
			if (chdir(newdir) == -1)
			{
				perror("./hsh");
				write(STDOUT_FILENO, "can't cd into directory\n", 24);
			}
			free(newdir);
		}
		return (0);
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
		return (0);
	}
	else
		return (1);
}
/**
 *executeprog - executes a line of code in the shell
 *@array: the array of strings to execute
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
			concat = path_handler(array[0]);
			if (concat == NULL)
				no_file_error(argv);
			execve(concat, array, NULL);
		}
	}
	else
		wait(&signal);

	return (0);
}
