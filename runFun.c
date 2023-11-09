#include "shell.h"

/*i use char ** to make like array*/
void run(char **argv)
{
	int d, stat;
	if (!argv || !argv[0])
		return;
	d = fork();
	if (d == -1)
		perror("");
	if (d == 0)
	{
		execve(argv[0], argv, environ);
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&stat);
	printf("yousef");
}



