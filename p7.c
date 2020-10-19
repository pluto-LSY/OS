#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int rc = fork();
	if(rc<0)
	{
		printf("failed.\n");
	}
	else if(rc==0)
	{
		printf("child.\n");
		close(STDOUT_FILENO);
		printf("child_1.\n");
		exit(1);
	}
	else
	{
		printf("father.\n");
		exit(1);
	}
	return 0;
}
		
