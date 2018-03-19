#include "holberton.h"
/**
 *line_handler - reads a line of text typed in after a prompt
 *
 *Description: function will read a line, break it into tokens, and execute
 *the call, then return to main when end of file is reached
 *Return: 0 when EOF is reached (ie user presses Ctrl + D)
 */
int line_handler(void)
{
	char *line, *newline;
	size_t len;
	ssize_t characters = 0;
	char **tokenarray;
	int i;

	while (characters != -1)
	{
		line = NULL;
		len = 0;

		write(1, "$ ", 2);
		characters = getline(&line, &len, stdin);
		if (characters == EOF)
		{
			write(1, "\n", 1);
			return (0);
		}
		i = 0;
		while (*(line + i) != '\n')
			i++;
		*(line + i) = '\0';
		newline = _reallocchar(line);
		tokenarray = tokensplit(newline);
		executeprog(tokenarray);
		/*while (tokenarray[i] != NULL)
		{
			free(tokenarray[i]);
			i++;
			}
			free(tokenarray[i]);*/
		free(line);
		free(newline);
		free(tokenarray);
	}
	return (0);
}
/**
 *tokensplit - splits a line into tokens and stores into a char array
 *@line: the line string to split
 *
 *Return: the array of strings
 */
char **tokensplit(char *line)
{
	int i = 0;
	int tokencount = 1;
	char **tokenarray;
	char *token;

	while (*(line + i) != '\0')
	{
		if (*(line + i) == ' ')
			tokencount++;
		i++;
	}

	i = 0;
	tokenarray = malloc(sizeof(char *) * tokencount + 1);
	if (tokenarray == NULL)
		return (NULL);
	token = strtok(line, " ");
	while (token != NULL)
	{
		*(tokenarray + i) = token;
		token = strtok(NULL, " ");
		i++;
	}
	*(tokenarray + i) = NULL;
	return (tokenarray);
}

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

int main(void)
{
	line_handler();
	return (0);
}
