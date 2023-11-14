#include "shell.h"

void run(char **argv)
{
	int stat;
	pid_t child_pid;
	
	
	
	if (!argv || !argv[0])
		return;

	if (strcmp(argv[0], "exit") == 0)
	{
		return;
	}
	if (strcmp(argv[0], "") == 0)
	{
		return;
	}

	if (strcmp(argv[0], "ls") == 0)
	{

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
		}
		else if (child_pid == 0)
		{
			if (execvp("ls", argv) == -1)
			{
				perror("ls");
			}

			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&stat);
		}
		return;
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("");
	}
	else if (child_pid == 0)
	{

		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(argv[0]);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&stat);
	}
}
