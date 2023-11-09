#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */

int main(void)
{
	pid_t child_pid;
	int status;
	char *argv[] = { "ls", "-l", "/tmp", NULL};

	for(int i = 0; i < 5; i++)
	{
		child_pid = fork();
		printf("###################################### %d\n", i);
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
	}
	if (child_pid == 0)
	{
		execve("/usr/bin/ls", argv, NULL);
		perror("Error:");
		exit(1);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
