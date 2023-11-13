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



typedef struct list_t
{
	char *d;
	struct list_t *t;
} list_t;


typedef struct command
{
	char *word;
	void (*func)(char **);
} command;

char **splitstring(char *str, const char *delim);

/*Start helpFun*/
int _putchar(char c);
void _print(char *str);
/*End helpFun*/


void run(char **argv);

/*START getPath*/
char *_get_path();
char *_getenv(const char *name);
/*END getPath*/



/*
format_t fun[] = {{'c', print_char}, {'s', print_string},
		{'%', print_mod}, {'i', print_int},
		{'d', print_int}, {'r', reverse_string},
		{'x', print_hex}, {'X', print_Hex},
		{'o', print_octal}, {'u', print_unsigned},
		{'b', print_binary}, {'p', print_address},
		{'S', print_ex_str}
	};
*/

void(*commands (char **argv))(char **argv);
void _exitt(char **argv);
void _env(char **argv __attribute__ ((unused)));
void _setenv(char **argv);
void _unsetenv(char **argv);


#endif
