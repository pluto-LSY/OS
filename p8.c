#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	int rc = fork();
	if(rc<0)
	{
		printf("failed.\n");
		exit(1);
	}
	else if(rc==0)
	{
		close(STDOUT_FILENO);
		open("p4.output.txt",O_CREAT | O_WRONLY |O_TRUNC,S_IRWXU);
		
		char *v[]={"wc","p4.c",NULL};
		execvp("wc",v);
		exit(1);
	}
	else
	{
		wait(NULL);
		exit(1);
	}
	return 0;
}
