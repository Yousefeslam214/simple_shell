#include "shell.h"

char *_getenv(const char *name)
{
	int i = 0,j = 0;
	char *str;
	if(!name)
		return (NULL);
	while (environ[i])
	{
		if(name[j] == environ[i][j])
		{
			while (name[j])
			{
				if(name[j] != environ[i][j])
					break;
				j++;
			}
			if(name[j] == '\0')
			{
				str = (environ[i] + j + 1);
				return (str);
			}
		}
		i++;
	}
	return (NULL);
}

/*
int main() {
    // Sample environment variables
    char *env[] = {
        "HOME=/usr/home",
        "USER=chatgpt",
        "PATH=/usr/local/bin:/usr/bin:/bin/yousef",
        NULL
    };

    // Call the _path function to retrieve the PATH
    char *path = get_path(env);

    printf("PATH: %s\n", path);

    // Free the allocated memory
    free(path);

    return 0;
}
*/
