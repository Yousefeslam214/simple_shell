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

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
extern char **environ;
int main(int ac, char **av, char **env)
{
    unsigned int i;

    i = 0;
	printf("%p\n %p\n", environ, env);
    while (env[i] != NULL)
    {
        printf("%s\n", env[i]);
        i++;
    }
    printf("%s\n", getenv(env));
    return (0);
}
