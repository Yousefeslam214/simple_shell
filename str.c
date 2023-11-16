#include "shell.h"


/**
 * _strdup - cpy string
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


char **splitstring(char *string, const char *delim)
{
	char **array, *token, *cpy;
	int i, j;

	cpy = malloc(strlen(string) + 1);
	if (cpy == NULL)
	{
		perror(_getenv("_"));
		return (NULL);
	}
	i = 0;
	while (string[i])
	{
		cpy[i] = string[i];
		i++;
	}
	cpy[i] = '\0';

	token = strtok(cpy, delim);
	array = (char **)malloc(sizeof(char *) * 1024);
	array[0] = _strdup(token);

	i = 1;
	j = 3;
	while (token)
	{
		token = strtok(NULL, delim);
		array = (char **)malloc(sizeof(char *) * 1024);
		array[i] = _strdup(token);
		i++;
		j++;
	}
	free(cpy);
	free(token);
	return (array);
}


char *concat_all(char *one, char *sep, char *two)
{
	char *concated;
	int l1, l2, l3, i, k;

	l1 = _strlen(one);
	l2 = _strlen(sep);
	l3 = _strlen(two);

	concated = (char *)malloc(l1 + l2 + l3 + 1);
	if (!concated)
	{
		free(concated);
		return (NULL);
	}
	for (i = 0; one[i]; i++)
		concated[i] = one[i];
	k = i;

	for (i = 0; sep[i]; i++)
		concated[k + i] = sep[i];
	k = k + i;

	for (i = 0; two[i]; i++)
		concated[k + i] = two[i];
	k = k + i;

	concated[k] = '\0';

	return (concated);
}
