#include "shell.h"

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
// /*

// int main(void)
// {

// 	char *path = _getenv("PATH");

//     printf("PATH: %s\n", path);
// 	char *argv[] = {"ls", "-la", NULL};

// 	run(argv);


// 	/*prompt*/
	
// 	size_t bufSiz = 0;
// 	char *buf = NULL;
// 	char *token;
// 	char **array;
// 	int i = 0;
//     array = (char **)malloc(sizeof(char *) * 1024);

// 	while (1)
// 	{
// 		if(isatty(STDIN_FILENO))
// 			_print("#cisfun$ ");
// 		getline(&buf, &bufSiz, stdin);
// 		token = strtok(buf, " \n");
// 		while (token)
// 		{
// 			array[i] = token;
// 			token = strtok(NULL, "\t\n");
// 			i++;
// 			array[i] = token;
// 			run((array));
// 		}
// 		run(array);

// 		/*array[i] = NULL;*/

		
// 	/*free(buf);*/
	
// 	i = 0;
// 	}
// 	return (0);
	
// }
// */
