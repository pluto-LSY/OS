#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	char buff[13];
	int in,out;
	 in = open("A.txt",O_RDONLY);
	 out = open("A.txt",O_WRONLY | O_CREAT);
	int rc = fork();

	if(rc<0)
	{
		printf("failed\n");
	}
	else if(rc==0)
	{
		int rd = read(in,buff,13);
		if(rd==-1)
		{
			printf("c failed.\n");
		}
		else
		{
			printf("c successful.\n");
		}
		write(out,"I am child\n",10);
		
	}
	else
	{
		int rd_1=read(in,buff,13);
		if(rd_1==-1)
		{
			printf("d failed");
		}
		else
		{
			printf("d sucessfully");
		}
		write(out,"I am parent\n",14);	
		
	}
	exit(1);
	return 0;
}

