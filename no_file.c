#include "holberton.h"
/**
 *no_file - write an error message if file is not found
 *
 *Return: void
 */
void no_file_error(char **argv)
{
	perror(argv[0]);
	_exit(0);
}
