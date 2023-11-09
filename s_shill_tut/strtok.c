#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *str = "This is a separated word by spaces";
    char *stc = malloc(sizeof(char)*strlen(str));
    char delim[5] = " ";
    char *trunks;

    /*
    trunks = strtok(stc, delim);
    printf("%s\n", trunks);
    trunks = strtok(NULL, delim);
    printf("%s\n", trunks);
    */
    strcpy(stc, str);
    trunks = strtok(stc, delim);
    while (trunks != NULL)
    {
        printf("%s\n", trunks);
        trunks = strtok(NULL, delim);
    }

    for (int i = 0; i < 35; i++)
    {
        if (stc[i] == '\0')
            printf("\\0");
        else
            printf("%c", stc[i]);
        /*
        if (stc == '\0')
            printf("\\0");
        else
            printf("%c", stc[i]);
        */
    }
    printf("\n");
    return (0);
}
