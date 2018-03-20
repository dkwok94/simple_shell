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

	while (1)
	{
		line = NULL;
		len = 0;

		write(STDOUT_FILENO, "$ ", 2);
		characters = getline(&line, &len, stdin);
		if (characters == EOF && characters == -1)
		{
			free(line);
			write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
<<<<<<< HEAD
		i = 0;
		while (line[i] != '\n')
			i++;
		line[i] = '\0';
=======
>>>>>>> a7f7cd47a3ed10dd614430455b69c6caf8ffda23
		newline = _reallocchar(line);
		tokenarray = tokensplit(newline);
		executeprog(tokenarray);
		free(line);
		free(newline);
		free(tokenarray);
	}
	free(line);
	return (0);
}
