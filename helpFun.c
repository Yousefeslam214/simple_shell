#include "shell.h"

int _putchar(char c)
{
	return (write(1, &c, 1));
}

void _print(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}

