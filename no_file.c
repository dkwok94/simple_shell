#include "holberton.h"
/**
 *no_file_error - write an error message if file is not found
 *@argv: the array of passed in function argument strings
 *
 *Return: void
 */
void no_file_error(char **argv, char **array, int commandcount)
{
	char *num;

	num = printint(commandcount);
	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, num, _strlen(num));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, array[0], _strlen(array[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "not found\n", 10);
	free(num);
	exit(0);
}
/**
 *printint - prints an integer
 *@list: variadic list of arguments
 *
 *Return: number of characters printed to stdout
 */
char *printint(int num)
{
	int tens = 1;
	int i = 0;
	int tensit = num;
	char *integer;

	integer = malloc(33);
	if (integer == NULL)
		return (NULL);
	if (num == 0)
	{
		integer[i] = 0 + '0';
		return (integer);
	}
	num = num / 10;

	while (num != 0)
	{
		num = num / 10;
		tens *= 10;
	}

	while (tens != 0)
	{
		integer[i] = (tensit / tens) + '0';
		tensit = tensit % tens;
		tens /= 10;
		i++;
	}
	integer[i] = '\0';
	return (integer);
}
