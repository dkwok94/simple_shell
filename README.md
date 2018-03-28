![shell example gif](https://github.com/dkwok94/simple_shell/blob/master/shell_example.gif)
## Simple_shell
### Description
Shell is a command programming language that executes commands read from a terminal or a file.

### Environment
Shell  was developed and tested on Ubuntu 14.04 LTS via Vagrant in VirtualBox.

File Contents
The repository contains the following files:

|   **File**   |   **Description**   |
| -------------- | --------------------- |
| main.c | The main function |
| atoi.c | Converts a string to an integer |
| AUTHORS | Contains info about authors of the project |
| builtins.c | Handels exit, cd and env buil-in commands |
| ctrl.c| Actions for when Ctrl+D is entered into the shell |
| executeprog.c | Containing function, that execute a line of code in the shell as well as function, that checks for build-ins |
| holberton.h   | Header file containing all function prototypes and struct declaration |
| _freeops.c | Freeing all varibles used as well as tokens in a tokenarray and a linked list |
| _getenv.c | Looks at environment variable and returns a pointer to string |
| man_1_simple_shell | Man page for the created shell |
| no_file.c | Write an error message, if file not found |
| path_handler.c | Iterates through PATH variable and concatinates command into it |
| _realloc.c | Reallocates memory for an array |
| _strops.c | Contains functions, needed for the string manipulations |
| tokenspit.c | Splits a line into tokens and stores into a char array |

### Function Descriptions

| **Function** | **Description** |
| -------------- | ----------------- |
|int _strlen(char *buf)| Calculates the lenght of the string|
|int printpath(char *path)||
|void print_path(char *str)||
|int _strcmp(char *s1, char *s2)||
|char *_strdup(char *str)||
|char *str_concat(char *s1, char *s2)||
|char *_concat(char *concatenate, char *s1, char *s2)||
|int _atoi(char *s)||
|path_t *create_ll(char *str)||
|path_t *fill_list(char *str, path_t *list)||
|void free_list(path_t *head)||
|void free_tokens(char **tokenarray)||
|void free_all(char *line, char *newline, char **tokenarray)||
|int ctrld(char *line)||
|void ctrlc(int signum)||
|void no_file_error(char **argv)||
|int exit_op(char **array)||
|int cd_op(char **array, char **env)||
|int env_op(char **env)||
|char **tokensplit(char *line)||
|int executeprog(char **array, char **env, char **argv)||
|char *_getenv(const char *name, char **env)||
|char **_realloccharss(char **ptr, int n)||
|char *_reallocchar(char *ptr)||
|char *path_handler(char *str, char **env)||

### Usage and Installation
Clone the repository, compile with comliation flags, listed below, then run the executable.
```
$ git clone https://github.com/dkwok94/simple_shell.git
```
### Compilation
This code was compiled this way: 
` $ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh `

###### Example code
```
int main(int ac, char **av, char **env)
{
        (void)ac, (void)av;
        char *line, *newline;
        size_t len;
        ssize_t characters = 0;
        char **tokenarray;

        while (1)
        {
                line = NULL;
                len = 0;
                if (isatty(0) == 1)
                {
                 	write(STDOUT_FILENO, "$ ", 2);
			signal(SIGINT, ctrlc);
		}
                characters = getline(&line, &len, stdin);
		if (line[0] == '\n')
		{
                 	free(line);
			continue;
		}
                if (characters == EOF)
			return (ctrld(line));
		newline = _reallocchar(line);
		tokenarray = tokensplit(newline);
		if (tokenarray == NULL)
		{
                 	free(line);
			return (0);
		}
                executeprog(tokenarray, env, av);
		free_all(line, newline, tokenarray);
	}
        free(line);
	return (0);
  }
```
###### Example usage

```
vagrant@vagrant-ubuntu-trusty-64:~/holbertonschool-low_level_programming/shelll$ ./hsh
$ ls
#README.md#  _getline.c~  build_ins.c	 holberton.h  no_file.c		     test_results
README.md    _llops.c	    build_ins.c~  hsh	            path_handler.c        tokensplit.c
_freeops.c   _realloc.c   builtins.c	   main.c       preparation_functions
_getenv.c    _strops.c	    ctrl.c	    man_shell    shelltest
_getline.c   atoi.c	      executeprog.c  man_shell~   test_2
$
```
### Authors
Derek Kwok, Elena Serebryakova
