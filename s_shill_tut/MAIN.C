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

void strtrim(char *line)
{
	int i;

	for (i = 0; line[i] == ' '; i++)
		line++;
	i = strlen(line) - 1;

	while (line[i] == ' ' || line[i] == '\n')
		i--;
	line[++i] = '\0';
}

int main ()
{
    char *argv[] = { "ls", "-l", "/bin", NULL};

	execve("/usr/bin/ls", argv, NULL);
    return(0);
}
