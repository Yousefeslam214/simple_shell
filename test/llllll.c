#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "tst.h"


int main(void) {
    size_t bufSiz = 0;
    char *buf = NULL;
    char *token;
    char **array;
    int i = 0;

    while (1) {
        printf("#ghjkhl$ ");
        if (getline(&buf, &bufSiz, stdin) == -1) {
            printf("\n");
            break;
        }
        token = strtok(buf, " \t\n");
        array = (char **)malloc(sizeof(char *) * 1024);

        while (token) {
            array[i++] = token;
            token = strtok(NULL, " \t\n");
        }

        array[i] = NULL;
        
        if (array[0]) {
            run(array);
        }

        i = 0;
        free(array);
    }

    return 0;
}
