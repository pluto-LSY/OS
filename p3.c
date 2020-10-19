#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int rc = fork();
	if(rc<0)
	{
		printf("failed");
	}
	else if(rc>0)
	{
		wait(NULL);
		printf("goodbye.\n");
	}
	else
	{
		printf("hello.\n");
	}
	exit(1);
	return 0;
} 
