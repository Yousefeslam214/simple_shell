#include "shell.h"

/*i use char ** to make like array*/
void run(char **argv)
{
	int stat;
	pid_t child_pid;
	
	if(*(argv[0]) == *("exit"))
	{
		return;
	}
	/*argv[0] = _getenv("PATH");*/
	if (!argv || !argv[0])
		return;
	child_pid = fork();
	if (child_pid == -1)
		perror(";;;;;;");
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



