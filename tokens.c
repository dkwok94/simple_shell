#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 *tokens - splits a string into tokens
 *@str: the string to split
 *
 *Return: void
 */
char **tokens(char *str)
{
	int i = 0, j = 0, spacecount = 0;
	char *token;
	char **array;

	while (*(str + j) != '\0')
	{
		if (*(str + j) == ' ')
			spacecount++;
		j++;
	}
	spacecount += 1;

	array = malloc(sizeof(char *) * spacecount);
	if (array == NULL)
		return (NULL);

	token = strtok(str, " ");

	while (token != NULL)
	{
		*(array + i) = token;
		token = strtok(NULL, " ");
		i++;
	}
	*(array + i) = NULL;
	return (array);
}

/**
 *length - finds the length of a string
 *@str: the string to find the length of
 *
 *Return: the length of the string
 */
int length(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
/**
 *main - print all tokens of a string
 *
 *Return: 0 on success
 */
int main(void)
{
	char **array;
	int i = 0, strlen;
	char *str, *strcpy;

	str = "Hello World my name is Derek!";
	strlen = length(str);
	strcpy = malloc(strlen);
	if (strcpy == NULL)
		return (-1);
	while (i < strlen)
	{
		strcpy[i] = str[i];
		i++;
	}
	strcpy[i] = '\0';

	i = 0;
	array = tokens(strcpy);
	while (*(array + i) != NULL)
	{
		printf("%s\n", *(array + i));
		i++;
	}
	return (0);
}
