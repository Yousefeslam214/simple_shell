#ifndef MAIN_H
#define MAIN_H

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

extern char **environ;
typedef struct list_path
{
	char *directory;
	struct list_path *path;
} list_path;
typedef struct command
{
	char *word;
	void (*func)(char **);
} command;

/*Start helpFun*/
int _putchar(char c);
void _print(char *str);

/*-------shell--------*/
void endoffile(int len, char *buf);
bool _isatty(void);

/*-------runfun-------*/
void run(char **argv);

/*-------commands------*/
void(*commands (char **argv))(char **argv);
void _exitt(char **argv);
void _env(char **argv __attribute__ ((unused)));
void _setenv(char **argv);
void _unsetenv(char **argv);

/*------free------*/
void *_realloc(void *ptr, unsigned int oldsize, unsigned int newsize);
void freearg(char ** argv);
void free_list(list_path *head);

/*--------getPath------*/
char *_getenv(const char *name);
list_path *linkpath(char *path);
list_path *add_node_to_end(list_path **head,char * token);
char *_which(char *name, list_path *head);

/*-------str-------*/
char *_strdup(char *str);
int _strlen(char *str);
char **splitstring(char *string, const char *delim);
char *concat_all(char *one, char *sep, char *two);

#endif
