#include "holberton.h"
/**
 *no_file - write an error message if file is not found
 *
 *Return: void
 */
void no_file_error(void)
{
	write(STDOUT_FILENO, "./hsh: No such file or directory\n", 33);
	_exit(0);
}
