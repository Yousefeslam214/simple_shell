#include "shell.h"


int main(void)
{

	char *path = _get_path();

    printf("PATH: %s\n", path);

	/*prompt*/
	/*
	size_t bufSiz = 0;
	char *buf = NULL;
	char *token;
	char **array;
	int i = 0;
    array = (char **)malloc(sizeof(char *) * 1024);

	while (1)
	{
		if(isatty(STDIN_FILENO))
			_print("#cisfun$ ");
		getline(&buf, &bufSiz, stdin);
		token = strtok(buf, "\t\n");
		while (token)
		{
			array[i] = token;
			token = strtok(NULL, "\t\n");
			i++;
			array[i] = token;
			run((array));
		}*/

		/*array[i] = NULL;*/

		
	/*free(buf);*/
	/*
	i = 0;
	}
	return (0);
	*/
}
