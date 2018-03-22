#include "holberton.h"
/**
 *free_all - frees all of the variables used
 *@line: the original line entered by user
 *@newline: line truncated to remove new line char
 *@tokenarray: array of token strings
 *
 *Return: void
 */
void free_all(char *line, char *newline, char **tokenarray)
{
	free_tokens(tokenarray);
	free(line);
	free(newline);
	free(tokenarray);
}
