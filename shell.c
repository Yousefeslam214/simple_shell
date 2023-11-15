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

void endoffile(int len, char *buf)
{
	(void)buf;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			putchar('\n');
			free(buf);
		}
		exit(0);
	}
}


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
	size_t bufSiz = 0;
	char *buf = NULL;
	char *token, *pathnameoffile, *path;
	char **array;
	int i = 0;
	list_path *head = '\0';
	void (*fun)(char **);
	int length = 0;
	while (length != EOF)
	{
		_isatty();
		/*if (getline(&buf, &bufSiz, stdin) == -1)
		{
			if (_isatty())
				printf("\n");
			break;
		}*/
		length = getline(&buf, &bufSiz, stdin);
		endoffile(length, buf);
		token = strtok(buf, " \n");
		array = (char **)malloc(sizeof(char *) * 1024);
		while (token)
		{
			array[i] = token;
			token = strtok(NULL, " \n");
			i++;
			array[i] = token;
		}
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
	}
	free(array);
	/*
	//free_list(head);
	*/
	free(buf);
	return (0);
}
