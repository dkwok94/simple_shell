#include "holberton.h"
/**
  *main - entry point for shell program
  *@ac: the number of arguments passed
  *@av: an array of strings of the arguments passed
  *@env: the current environment
  *
  *Description: function will read a line, break it into tokens, and execute
  *the call, then return to main when end of file is reached
  *Return: 0 when EOF is reached (ie user presses Ctrl + D)
  */
int main(int ac, char **av, char **env)
{
	(void)ac, (void)av;
	char *line, *newline;
	size_t len;
	ssize_t characters = 0;
	char **tokenarray;

	while (1)
	{
		line = NULL;
		len = 0;
		if (isatty(0) == 1)
		{
			write(STDOUT_FILENO, "$ ", 2);
			signal(SIGINT, ctrlc);
		}
		characters = getline(&line, &len, stdin);
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		if (characters == EOF)
			return (ctrld(line));
		newline = _reallocchar(line);
		tokenarray = tokensplit(newline);
		executeprog(tokenarray, env, av);
		free_all(line, newline, tokenarray);
	}
	free(line);
	return (0);
}
