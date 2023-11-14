#include "tst.h"


void run(char **argv) {
    int stat;
    pid_t child_pid;

    if (!argv || !argv[0])
        return;

    if (strcmp(argv[0], "ls") == 0 && (argv[1] == NULL || strcmp(argv[1], "-l") == 0)) {
        child_pid = fork();
        if (child_pid == -1) {
            perror("fork");
        }
        else if (child_pid == 0)
        {
            // Child process
            if (argv[1] == NULL) {
                execlp("ls", "ls", (char *)NULL);
            } else {
                execlp("ls", "ls", "-l", (char *)NULL);
            }
            perror("ls");
            exit(EXIT_FAILURE);
        } else {
            wait(&stat);
        }
        return;
    }
}
