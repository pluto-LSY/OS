#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	char buff[13];
	int in = open("B.txt",O_RDONLY | O_CREAT | O_WRONLY);
	int rc =fork();
	
	if(rc<0)
	{
		printf("failed.\n");
		exit(1);
	}
	else if(rc>0)
	{
		int rd = read(in,buff,13);
		if(rd==-1)
		{
			printf("c failed.\n");
		}
		else
		{
			printf("c successfully.\n");
		}
		write(in,"i am a child",12);
		close(in);
	}
	else
	{
		int rd_1 = read(in,buff,13);
		if(rd_1==-1)
		{
			printf("p failed.\n");
		}
		else
		{
			printf("p succesful.\n");
		}
		write(in,"i am a dad.\n",11);
		close(in);
		exit(1);	
	}
	return 0;
}

