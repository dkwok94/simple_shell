#include "holberton.h"
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
	token = strtok(line, DELIMS);
	while (token != NULL)
	{
		*(tokenarray + i) = token;
		token = strtok(NULL, DELIMS);
		i++;
	}
	*(tokenarray + i) = NULL;
	return (tokenrray);
}
