#include "shell.h"

void _exitt(char **argv)
{
	printf("ayo\n");
}
void _env(char **argv __attribute__ ((unused)))
{
	printf("ayo\n");
}
void _setenv(char **argv)
{
	printf("ayo\n");
}
void _unsetenv(char **argv)
{
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
			for(j = 0; argv[0][j]; j++)
			{
				if (cod[i].word[j] != (argv[0][j])){
					break;
					return(0);
				}
			}
			if (!argv[0][j] && !cod[i].word[j])
				return(cod[i].func);
		}
	}
	return (0);
}	



