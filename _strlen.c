#include "holberton.h"
/**
 *_strlen - calculates the length of a string
 *@buf: buffer to count length of strings
 *
 *Return: the length of the string
 */
int _strlen(char *buf)
{
        int i = 0;

        while (buf[i] != '\0')
        {
                i++;
        }
        return (i);
}
