#include "shell.h"

void run(char **argv)
{
	int stat;
	pid_t child_pid;

	if (!argv || !argv[0])
		return;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror(_getenv("_"));
	}
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror(argv[0]);
		}
		exit(EXIT_FAILURE);
	}
		wait(&stat);
}
