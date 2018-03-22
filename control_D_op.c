#include "holberton.h"
/**
 *control_D_op - actions for when Ctrl+D is entered into the shell
 *@line: the main line buffer to free
 *
 *Return: 0 on success
 */
int control_D_op(char *line)
{
	free(line);
	if (isatty(0) == 1)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
