#include "holberton.h"
#define BUFF 1024

/**
 *_getline - delimited string input
 *@lineptr: stores adress of the buffer containing hte text
 *@size: number characters to read
 *@file: file to read from
 *
 *Return: the array of strings
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *file)
{
	char *buf;
	size_t size;
	size_t i = 0;
	int c;

	if (lineptr == NULL || n == NULL || file == NULL)
		return (-1);
	buf = *lineptr;
	size = *n;
	char *real;

	if (buf == NULL)
	{
		buf = malloc(sizeof(BUFF));
		if (buf == NULL)
			return (-1);
        }
	c = fgetc(file);
	if (c == EOF)
	{
		if (buf[c] == '\0')
		{
			size = i;
			return (i);
		}
		else
		{
			free (buf);
			return (-1);
		}
	}
	if (c == '\n')
	{
		buf[c] = '\n';
		buf[c+1] = '\0';
		size = i + 1;
		i = i + 1;
		return (i);
	}
	buf = malloc(sizeof(char) * size + 1);
	if (buf == NULL)
		return (-1);
	while (i < (size-1))
	{
		real = realloc(buf, sizeof(char) * size + 1);
		if (real == NULL)
		{
			free (buf);
			return (-1);
		}
		i++;
	}
	buf[i] = '\0';
	size = i;
	return (i);
}
