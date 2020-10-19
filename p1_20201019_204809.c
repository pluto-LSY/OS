#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int x=0;
	int rc =fork();

	if(rc<0)
	{
		printf("failed.\n");
		exit(1);
	}
	else if(rc==0)
	{
		printf("child x is:%d\n",x);
		//x=3;
		printf("child x has changed is %d\n",x);
		exit(1);

	}
	else
	{
		x=100;
		printf("parent x has changed is %d\n",x);
	}
	exit(1);
	return 0;
}
