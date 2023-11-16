#include "shell.h"


void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;
	char *old;

	unsigned int i;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);
	old = ptr;
	if (new == NULL)
		return (NULL);

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			new[i] = old[i];
		free(ptr);
		for (i = old_size; i < new_size; i++)
			new[i] = '\0';
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			new[i] = old[i];
		free(ptr);
	}
	free(old);
	return (new);
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
