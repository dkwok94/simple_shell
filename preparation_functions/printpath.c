#include "holberton.h"
/**
 *printpath - prints each entry of path
 *@path: pointer to the path variable
 *
 *Return: 0 upon success
 */
int printpath(char *path)
{
        char buf[1024];
        int i = 0, j = 0, length;
        while (path[i] != '\0')
        {
                if (i == 0)
                {
                        while (path[i] != '=')
                                i++;
                        i++;
                }
                while (path[i] != ':' && path[i] != '\0')
                {
                        buf[j] = path[i];
                        i++;
                        j++;
                }
                if (path[i] == ':')
                        i++;
                buf[j++] = '\n';
                buf[j] = '\0';
                length = _strlen(buf);
                write(1, buf, length);
                j = 0;
        }
        return (0);
}
