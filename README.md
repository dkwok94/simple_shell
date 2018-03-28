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
|builtins.c | Handles exit, cd and env built-in commands |
|ctrl.c| Actions for when Ctrl+D and Ctrl+C is entered into the shell |
|executeprog.c | Containing function, that execute a line of code in the shell as well as a function that checks for build-ins |
|holberton.h   | Header file containing all function prototypes and struct declarations |
|_freeops.c | Freeing all varibles used as well as tokens in a tokenarray and a linked list |
|_getenv.c | Looks at environment variable and returns a pointer to string that matches |
|man_1_simple_shell | Man page for the created shell |
|no_file.c | Write an error message, if file not found |
|path_handler.c | Iterates through PATH variable and concatinates command into it |
|_realloc.c | Reallocates memory for an array |
|_strops.c | Contains functions needed for the string manipulations |
|tokensplit.c | Splits a line into tokens and stores into a char* array |
|_llops.c | functions for creating an empty linked list and filling it with the contents of the $PATH variable |


### Function Descriptions

| **Function** | **Description** |
| -------------- | ----------------- |
|void printprompt(void) | prints the $ prompt at every new loop iteration |
|int _strlen(char *buf)| Calculates the length of the string|
|int _strcmp(char *s1, char *s2)| compares two strings |
|char *_strdup(char *str)| returns pointer to allocated space containing copy of string |
|char *str_concat(char *s1, char *s2)| contatenates two strings |
|char *_concat(char *concatenate, char *s1, char *s2)| concatenates two strings |
|int _atoi(char *s)| converts a string to an integer |
|char *printint(int num) | converts an integer to a string |
|path_t *create_ll(char *str)| creates an empty linked list the size of the $PATH variable |
|path_t *fill_list(char *str, path_t *list)| fills an empty linked list with PATH variable contents |
|void free_list(path_t *head)| frees a path_t list |
|void free_tokens(char **tokenarray)| frees the tokens in the tokenarray |
|void free_all(char *line, char *newline, char **tokenarray) | frees all of the variables used |
|int ctrld(char *line)| actions for when Ctrl+D is entered into the shell |
|void ctrlc(int signum)| Ctrl+C handler (ie does not exit when SIGINT is sent |
|void no_file_er(char **argv, char **ar, int cmdnum, char *line, char *nline)| write an error message if file is not found |
|int exit_op(char **array, char *line, char *newline)| handles exit builin |
|int cd_op(char **array, char **env)| handles the cd builtin |
|int env_op(char **env)| handles env builtin |
|char **tokensplit(char *line)| splits a line into tokens and stores into a char* array |
|int exec(char **ar, char **env, char **av, char *line, char *nline, int cdnum)| executes a line of code in the shell |
|char *_getenv(const char *name, char **env)| looks at enviroment variable and returns a pointer to string |
|char **_realloccharss(char **ptr, int n)| reallocates memory for char** |
|char *_reallocchar(char *ptr)| reallocates memory for char* |
|char *path_handler(char *str, char **env)| iterates through $PATH variable end concatenates command into it |

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
```
vagrant@vagrant-ubuntu-trusty-64:~/holbertonschool-low_level_programming/shelll$ ./hsh
$ pwd
/home/vagrant/simple_shell
$
```
```
vagrant@vagrant-ubuntu-trusty-64:~/holbertonschool-low_level_programming/shelll$ ./hsh
$ env
XDG_SESSION_ID=2
TERM=cygwin
SHELL=/bin/bash
SSH_CLIENT=10.0.2.2 60471 22
SSH_TTY=/dev/pts/0
USER=vagrant
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arj=01;31:*.taz=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lz=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.axv=01;35:*.anx=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.axa=00;36:*.oga=00;36:*.spx=00;36:*.xspf=00;36:
MAIL=/var/mail/vagrant
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games
PWD=/home/vagrant/simple_shell
LANG=en_US.UTF-8
SHLVL=1
HOME=/home/vagrant
LOGNAME=vagrant
SSH_CONNECTION=10.0.2.2 60471 10.0.2.15 22
LESSOPEN=| /usr/bin/lesspipe %s
XDG_RUNTIME_DIR=/run/user/1000
LESSCLOSE=/usr/bin/lesspipe %s %s
OLDPWD=/home/vagrant
_=./hsh
$
```

### Authors
Derek Kwok, Elena Serebryakova
