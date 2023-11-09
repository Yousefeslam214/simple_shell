#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void check_command (char * command)
{
	if(access(command, F_OK) == 0)
		printf("%s: foundThe file\n", command);
	else
		printf("%s: Not found The file\n", command);
}


int main(void)
{
	/*prompt*/
	size_t bufSiz = 0;
	char *buf = NULL;
	char *token;


	while (1)
	{
		write(1, "#ghjkhl$ ", 10);
		getline(&buf, &bufSiz, stdin);
		token = strtok(buf, " \t\n");
		if(strcmp(token, "which") == 0)
		{
			token = strtok(NULL, " \t\n");
			while (token)
			{
				check_command(token);
				token = strtok(NULL, " \t\n");
			}
		}
		else
			write(1, "COMMAND DOSEN'T EXIST\n", 23);
	}
	return (0);
}
