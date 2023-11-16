#include "shell.h"

char *_getenv(const char *name)
{
	int i = 0,j = 0;
	char *str;
	if(!name)
	{
		return (NULL);
	}
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

list_path *linkpath(char *path)
{
	char *token, *copy_path = _strdup(path);
	list_path *head = NULL;

	token = strtok(copy_path, ":");
	while (token)
	{
		head = add_node_to_end(&head, token);
		token = strtok(NULL, ":");
	}
	free(copy_path);
	free(token);
	free(path);
	return (head);
}

list_path *add_node_to_end(list_path **head ,char * token)
{
	list_path *new_path = (list_path *)malloc(sizeof(list_path));
	list_path *temp;
	if (!token || !new_path)
	{
		free_list(new_path);
		return (NULL);
	}
	new_path->directory = _strdup(token);
	/*new_path->path = '\0';*/
	new_path->path = NULL;
	if (!*head)
		*head = new_path;
	else
	{
		temp = *head;
		while (temp->path)
		{
			temp = temp->path;
		}
		temp->path = new_path;
	}
	free_list(new_path);
	return (*head);
}





char *_which(char *filename, list_path *head)
{
	struct stat st;
	char *string;

	list_path *tmp = head;

	while (tmp)
	{

		string = concat_all(tmp->directory, "/", filename);
		if (stat(string, &st) == 0)
		{
			return (string);
		}
		free(string);
		tmp = tmp->path;
	}
	free_list(tmp);
	return (NULL);
}
char *concat_all(char *name, char *sep, char *value)
{
	char *result;
	int l1, l2, l3, i, k;

	l1 = _strlen(name);
	l2 = _strlen(sep);
	l3 = _strlen(value);

	result = (char *)malloc(l1 + l2 + l3 + 1);
	if (!result)
	{
		free(result);
		return (NULL);
	}
	for (i = 0; name[i]; i++)
		result[i] = name[i];
	k = i;

	for (i = 0; sep[i]; i++)
		result[k + i] = sep[i];
	k = k + i;

	for (i = 0; value[i]; i++)
		result[k + i] = value[i];
	k = k + i;

	result[k] = '\0';
	free(name);
	free(value);
	/*
	free(sep);
	
	*/
	return (result);
}

