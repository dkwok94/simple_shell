#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 *length - finds the length of a string
 *@line: the line to calculate length of
 *
 *Return: the length of line
 */
int length(char *line)
{
	int i = 0;

	while (line[i] != '\0')
		i++;
	return (i);
}
/**
 *main - reads a line from standard input
 *
 *Return: 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	int leng;
	ssize_t characters = 0;

	while (characters != -1)
	{
		write(1, "$ ", 2);
		characters = getline(&line, &len, stdin);
		leng = length(line);
		write(1, line, leng);
	}
	free(line);
	return (0);
}
