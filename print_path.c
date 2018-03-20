#include "holberton.h"
/**
 *print_path - prints PATH variable directories on separate lines
 *@str: PATH variable
 *
 *Return: void
 */
void print_path(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ':')
			write(STDOUT_FILENO, "\n", 1);

		else
			write(STDOUT_FILENO, &str[i], 1);
		i++;
	}
}
