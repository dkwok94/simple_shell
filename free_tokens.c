#include "holberton.h"
/**
 *free_tokens - frees the tokens in the tokenarray
 *@tokenarray: array of tokens
 *
 *Return: void
 */
void free_tokens(char **tokenarray)
{
	int i = 0;

	while (tokenarray[i] != NULL)
	{
		free(tokenarray[i]);
		i++;
	}
	free(tokenarray[i]);
}
