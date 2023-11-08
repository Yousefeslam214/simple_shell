#include "shell.h"

int main(void)
{
	/*prompt*/
	size_t bufSiz = 0;
	char *buf = NULL;
	char *token;
	char **array;
	int i = 0;
	pid_t child_pid;
	int status;

	while (1)
	{
		write(1, "#cisfun$ ", 10);
		getline(&buf, &bufSiz, stdin);
		token = strtok(buf, "\t\n");
		array = (char **)malloc(sizeof(char *) * 1024);
		while (token)
		{
			array[i] = token;
			token = strtok(NULL, "\t\n");
			
			i++;
			array[i] = token;
		}
		if(*(array[0]) == *("exit"))
		{
			return(0);
		}
		/*array[i] = NULL;*/
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
	i = 0;
	free(array);
	/*free(buf);*/
	}
	return (0);
}
