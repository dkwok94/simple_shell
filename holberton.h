#ifndef _HOLB_
#define _HOLB_
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#define DELIMS " \t\n\r\v\f"

/**
 *struct path_s - linked list structure for PATH variable
 *@directory: directory to search
 *@next: pointer to the next node
 *
 *Description: singly linked list node structure for PATH variable
 */
typedef struct path_s
{
	char *directory;
	struct path_s *next;
} path_t;

int _strlen(char *buf);
int printpath(char *path);
void print_path(char *str);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
char *_concat(char *concatenate, char *s1, char *s2);
path_t *create_ll(char *str);
path_t *fill_list(char *str, path_t *list);
void free_list(path_t *head);
int control_D_op(char *line);
char *_getenv(const char *name);
char **tokensplit(char *line);
int executeprog(char **array, char **env);
char *_getenv(const char *name);
char **_realloccharss(char **ptr, int n);
char *_reallocchar(char *ptr);
char *path_handler(char *str);
#endif
