#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Get the value of the PATH environment variable
    const char* path = getenv("PATH");

    if (path != NULL) {
        // Create a copy of the path string to avoid modifying the original
        char* pathCopy = strdup(path);

        if (pathCopy != NULL) {
            // Tokenize the path string using the ':' delimiter
            char* token = strtok(pathCopy, ":");

            while (token != NULL) {
                // Print each directory
                printf("%s\n", token);

                // Get the next token
                token = strtok(NULL, ":");
            }

            // Free the dynamically allocated memory
            free(pathCopy);
        }
    }

    return 0;
}
