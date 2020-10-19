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
		waitpid(-1,NULL,NULL);
		printf("goodbye.\n");
	}
	else
	{
		printf("hello.\n");
	}
	exit(1);
	return 0;
} 
