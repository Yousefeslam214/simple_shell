#include "shell.h"


void *_realloc(void *ptr, unsigned int oldsize, unsigned int newsize)
{
	char *news= NULL;
	char *old = NULL;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(newsize));
	if (newsize == oldsize)
		return (ptr);
	if (newsize == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	news = (char *)malloc(newsize);
	old = ptr;
	if (news == NULL)
		return (NULL);
	if (newsize > oldsize)
	{
		for (i = 0; i < oldsize; i++)
			news[i] = old[i];
		free(ptr);
		for (i = oldsize; i < newsize; i++)
			news[i] = '\0';
	}
	if (newsize < oldsize)
	{
		for (i = 0; i < newsize; i++)
			news[i] = old[i];
		free(ptr);
	}
	free(old);
	return (news);
}


void freearg(char ** argv)
{
	int i = 0;
	while (argv[i])
	{
		free(argv[i]);
	}
	free(argv);
}

void free_list(list_path *head)
{
	list_path *stor;

	while (head)
	{
		stor =  head->path;
		free(head->directory);
		free(head);
		head = stor;
	}
}
