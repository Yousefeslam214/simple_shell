#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0;
	char *token;

	while (environ[i])
	{
		token = strtok(environ[i], "=");
		if (strcmp(token, name) == 0)
		{
			return (strtok(NULL, "="));
		}
		i++;
	}
	return (NULL);
}

int main(void)
{
	char *homeValue = _getenv("_");
	perror("");
	printf("%s\n", homeValue);
	return (0);
}
