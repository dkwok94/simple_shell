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
char **tokensplit(char *line);
int executeprog(char **array);
#endif
