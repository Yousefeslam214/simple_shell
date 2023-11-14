#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdbool.h>
#include "shell.h"


bool _isatty(void)
{
	if (isatty(0))
	{
		write(1, "#ghjkhl$ ", 10);
		return (true);
	}
	return (false);
}

int main(void)
{
	/*prompt*/
	size_t bufSiz = 0;
	char *buf = NULL;
	char *token, *pathnameoffile, *path;
	char **array;
	int i = 0;
	/*pid_t child_pid;
	int status;
	int len = 0;*/
	list_path *head = '\0';
	void (*fun)(char **);



	while (1)
	{
		_isatty();
		
		if (getline(&buf, &bufSiz, stdin) == -1)
		{
			if (_isatty())
				printf("\n");
			break;
		}
		token = strtok(buf, "\t\n");
		array = (char **)malloc(sizeof(char *) * 1024);
		while (token)
		{
			array[i] = token;
			token = strtok(NULL, "\t\n");
			i++;
			array[i] = token;
		}
		/*if(*(array[0]) == *("exit"))
		{
			return(0);
		}*/
		
			run(array);
		if(!array || !array[0])
			run(array);
		else
		{
			path = _getenv("PATH");
			head = linkpath(path);
			pathnameoffile = _which((array[0]), head);
			fun = commands(array);
			if (fun)
			{
				fun(array);
			}
			else if (!pathnameoffile)
				run(array);
			else if (pathnameoffile)
			{
				/*free(array[0]);*/
				array[0] = pathnameoffile;
				run(array);
			}
		}
	i = 0;
	//free(array);
	free(buf);
	
	//free_list(head);
	//freearv(argv);
	
	}
	return (0);
}
