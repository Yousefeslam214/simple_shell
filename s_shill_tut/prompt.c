#include <stdio.h>
#include <stdlib.h>

int main(void)
{
/*
	size_t n = 10;
	char *buf;

	buf = (char *)malloc(sizeof(char) * 10);
*/

	size_t n = 0;
	char *buf = NULL;

	printf("Enter Your name : ");
	getline(&buf, &n, stdin);
	printf("your name is : %s\n", buf);
	printf("Buffer size : %ld\n",n);
	free(buf);
	return(0);
}
