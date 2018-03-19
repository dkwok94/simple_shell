#include <stdio.h>
#include <unistd.h>
#include "holberton.h"
int main(void)
{
	pid_t my_pid;

	my_pid = getppid();
	printf("%d\n", my_pid);
	return (0);
}
