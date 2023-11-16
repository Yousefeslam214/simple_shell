#include "shell.h"


/**
 * _strdup - copy string
 * @str: string
 * Return:newstring or NULL on fail
*/

char *_strdup(char *str)
{
    char *newstr;
    int i;
    if (str == NULL)
        return (NULL);
    newstr = (char *)malloc(sizeof(char) * _strlen(str) + 1);
    if (newstr == NULL)
    {
        free(newstr);
        return (NULL);
    }
    for (i = 0; i < (int)_strlen(str); i++)
        newstr[i] = str[i];
    newstr[i] = '\0';
    return (newstr);
}

/**
 * _strlen - calculate length of string
 * @str: string
 * Return: length
*/
int _strlen(char *str)
{
    int len = 0;

    while (str[len])
        len++;
    
    return(len);
}


char **splitstring(char *str, const char *delim)
{
	int i, wn;
	char **array;
	char *token;
	char *copy;

	copy = malloc(strlen(str) + 1);
	if (copy == NULL)
	{
		perror(_getenv("_"));
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';

	token = strtok(copy, delim);
	array = (char **)malloc(sizeof(char *) * 1024);
	array[0] = _strdup(token);

	i = 1;
	wn = 3;
	while (token)
	{
		token = strtok(NULL, delim);
		array = (char **)malloc(sizeof(char *) * 1024);
		array[i] = _strdup(token);
		i++;
		wn++;
	}
	free(copy);
	free(token);
	return (array);
}
