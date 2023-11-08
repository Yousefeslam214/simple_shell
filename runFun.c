#include "shell.h"

void run(char **argv)
{
    pid_t child_pid;
    char **array;
    array = (char **)malloc(sizeof(char *) * 1024);
    int status;

    if (!argv || !argv[0])
		return;
    child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(array[0], array, NULL) == -1)
				perror("error");
		}
		else
		{
			wait(&status);
		}
        
    free(array);
}

