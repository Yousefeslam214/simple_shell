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

extern char **environ;



/*Start helpFun*/
int _putchar(char c);
void _print(char *str);
/*End helpFun*/


void run(char **argv);

/*START getPath*/
char *_get_path();
/*END getPath*/



/*
typedef struct format
{
	char *word;
	int (*f)(va_list);
} format_t;
*/
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


#endif
