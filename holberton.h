#ifndef _HOLB_
#define _HOLB_
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
int line_handler(void);
int _strlen(char *buf);
int printpath(char *path);
char *_getenv(const char *name);
char **tokensplit(char *line);
int executeprog(char **array);
char *_getenv(const char *name);
char **_realloccharss(char **ptr, int n);
char *_reallocchar(char *ptr);
#endif
