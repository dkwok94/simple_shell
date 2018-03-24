#include "holberton.h"
/**
 *no_file_error - write an error message if file is not found
 *@argv: the array of passed in function argument strings
 *
 *Return: void
 */
void no_file_error(char **argv)
{
	perror(argv[0]);
	_exit(0);
}
