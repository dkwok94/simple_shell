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
|main.c | The main function |
|atoi.c | Converts a string to an integer |
|AUTHORS | Contains info about authors of the project |
|builtins.c | Handels exit, cd and env buil-in commands |
|ctrl.c| Actions for when Ctrl+D is entered into the shell |
|executeprog.c | Containing function, that execute a line of code in the shell as well as function, that checks for build-ins |
|holberton.h   | Header file containing all function prototypes and struct declaration |
|_freeops.c | Freeing all varibles used as well as tokens in a tokenarray and a linked list |
|_getenv.c | Looks at environment variable and returns a pointer to string |
|man_1_simple_shell | Man page for the created shell |
|no_file.c | Write an error message, if file not found |
|path_handler.c | Iterates through PATH variable and concatinates command into it |
|_realloc.c | Reallocates memory for an array |
|_strops.c | Contains functions, needed for the string manipulations |
|tokenspit.c | Splits a line into tokens and stores into a char array |

### Function Descriptions

| **Function** | **Description** |
| -------------- | ----------------- |
|int _strlen(char *buf)| Calculates the lenght of the string|
|int _strcmp(char *s1, char *s2)| compares two strings |
|char *_strdup(char *str)| returns pointer to allocated space containing copy of string |
|char *str_concat(char *s1, char *s2)| contatenates two strings |
|char *_concat(char *concatenate, char *s1, char *s2)| concatenates two strins |
|int _atoi(char *s)| converts a string to an integer |
|path_t *create_ll(char *str)| creates an empty linked list the size of the path variable |
|path_t *fill_list(char *str, path_t *list)| fills an empty linked list with PATH variable contents |
|void free_list(path_t *head)| frees a list_t list |
|void free_tokens(char **tokenarray)| frees the tokens in the tokenarray |
|void free_all(char *line, char *newline, char **tokenarray) | frees all of the variables used |
|int ctrld(char *line)| actions for when Ctrl+D is entered into the shell |
|void ctrlc(int signum)| Ctrl+C handler |
|void no_file_error(char **argv)| write an error message if file is not found |
|int exit_op(char **array)| handles exit builin |
|int cd_op(char **array, char **env)| handles the cd builtin |
|int env_op(char **env)| handles env builtin |
|char **tokensplit(char *line)| splits a line into tokens and stores into a char array |
|int executeprog(char **array, char **env, char **argv)| executes a line of code in the shell |
|char *_getenv(const char *name, char **env)| looks at enviroment variable and returns a pointer to string |
|char **_realloccharss(char **ptr, int n)| reallocates memory for char** |
|char *_reallocchar(char *ptr)| reallocates memory for char* |
|char *path_handler(char *str, char **env)| iterates through PATH variable end cocncatenates commant into it |

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
