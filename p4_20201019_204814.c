#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

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
		execl("/bin/ls","ls","-l",NULL);
		execle("/bin/ls","ls","-l",NULL,NULL);
		execlp("/bin/ls","ls","-l",NULL);
		exit(1);
	}
	else
	{
		printf("parent\n");
		char *v[]={"ls","-l","NULL"};
		execv("/bin/ls",v);
		execve("/bin/ls",v,NULL);
		execvp("/bin/ls",v);
		exit(1);	
	}
	return 0;
}
