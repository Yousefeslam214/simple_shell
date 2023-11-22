#include "shell.h"

void _exitt(char **arv)
{
	int exit_status = 0;

	if (arv[1])
	{
		exit_status = atoi(arv[1]);
		if (exit_status < 0)
		{
			exit_status = 2;
		}

		free(arv);
		exit(exit_status);
	}


	for (int i = 0; arv[i]; i++)
	{
		free(arv[i]);
	}
	free(arv);
	exit(0);

    int exit_status = 0,i = 0;

    if (arv[1]) {
        exit_status = atoi(arv[1]);
        if (exit_status < 0) {
            exit_status = 2;
        }
        freearg(arv);
        exit(exit_status);
    }
	while (arv[i])
	{
		free(arv[i]);
		i++;
	}
    free(arv);
    exit(0);

}
void _env(char **arv __attribute__ ((unused)))
{
	char **env_var = environ;

	while (*env_var)
	{
		puts(*env_var);
		puts("\n");
		env_var++;
	}

    while (*env_var) {
        puts(*env_var);
    	/*puts("\n");*/
        env_var++;
    }


}
void _setenv(char **argv)
{
	*argv = "yousef";
	printf("argv\n");
}
void _unsetenv(char **argv)
{
	*argv = "yousef";
	printf("ayo\n");
}



void(*commands (char **argv))(char **argv)
{
	int j , i;
	command cod[] = {
		{"exit", _exitt},
		{"env", _env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (i = 0; cod[i].word; i++)
	{
		j = 0;
		if (cod[i].word[j] == argv[0][j])
		{
			for (j = 0; argv[0][j]; j++)
			{
				if (cod[i].word[j] != (argv[0][j])){
					break;
					return (0);
				}
			}
			if (!argv[0][j] && !cod[i].word[j])
			return(cod[i].func);
		}
	}
	return (0);
}	
