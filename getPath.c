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
	token = NULL;
	path = NULL;
	free(path);
	path = NULL;
	return (head);
}

list_path *add_node_to_end(list_path **head ,char * token)
{
	list_path *new_path = (list_path *)malloc(sizeof(list_path));
	list_path *temp;
	if (!token || !new_path)
	{
		free_list(new_path);
		
		new_path = NULL;
		
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
	new_path = NULL;
	free_list(new_path);
	new_path = NULL;
	token = NULL;
	free(token);
	token = NULL;
	/*
	don't do it
	free_list(temp);
	*/
	return (*head);
}

char *_which(char *name, list_path *head)
{
	struct stat sta;
	char *str;
	list_path *temp = head;

	while (temp)
	{
		str = concat_all(temp->directory, "/", name);
		if (stat(str, &sta) == 0)
			return (str);
		free(str);
		str = NULL;
		temp = temp->path;
	}
	free_list(head);
	/*
	don't do this
	free_list(tmp);
	*/
	return (NULL);
}
