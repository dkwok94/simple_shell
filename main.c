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
	int cmdnum = 0;

	while (1)
	{
		line = NULL;
		len = 0;
		cmdnum++;
		if (isatty(0) == 1)
			printprompt();
		characters = getline(&line, &len, stdin);
		if (characters == EOF || characters == -1)
			return (ctrld(line));
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		newline = _reallocchar(line);
		if (newline == NULL)
		{
			free(line);
			return (0);
		}
		tokenarray = tokensplit(newline);
		if (tokenarray == NULL)
		{
			free(line);
			return (0);
		}
		exec(tokenarray, env, av, line, newline, cmdnum);
		free_all(line, newline, tokenarray);
	}
	free(line);
	return (0);
}
