#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int i = 0 , sum = 0;
	printf("argc = %d\n", argc);
	for (i = 1; i <argc; i++)
	{
		
		printf("arv[%d] : %s\n",i , argv[i]);
		sum += atoi(argv[i]);
	}
	printf("sum is %d\n", sum);
	return (0);
}
