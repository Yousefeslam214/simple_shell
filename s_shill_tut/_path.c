#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *_path(char **env)
{
	int path_idx = 0, path_len = 0;
	char *path;

	while (env[path_idx] != NULL)
	{
		if (strncmp(env[path_idx], "PATH", 4) == 0)
			break;
		path_idx++;
	}

	if (!env[path_idx])
		return NULL;

	path_len = strlen(env[path_idx]);
	path = malloc(path_len - 4);
	if (!path)
		return (NULL);

	strcpy(path, env[path_idx]);
	return (path);
}
int main() {
    // Sample environment variables
    char *env[] = {
        "HOME=/usr/home",
        "USER=chatgpt",
        "PATH=/usr/local/bin:/usr/bin:/bin/yousef",
        NULL
    };

    // Call the _path function to retrieve the PATH
    char *path = _path(env);

    printf("PATH: %s\n", path);

    // Free the allocated memory
    free(path);

    return 0;
}
