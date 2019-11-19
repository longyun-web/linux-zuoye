#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
 
int main()
{
	pid_t pid;
	int fd;
	int status;
	char *ch1="child writed\n";
	char *ch2="parent writed\n";

	fd = open("test.txt",O_RDWR|O_CREAT,0644);
	if(fd==-1)
	{
		printf("open or creat file error:%m\n");
		exit(-1);
	}
	pid=fork();
	if(pid==-1)
	{
		printf("error fork\n");
		exit(-1);
	}
	else if(pid==0)
	{
		printf("in child process\n");
		if(write(fd,ch1,strlen(ch1))==-1)
		{
			printf("child write error:%m\n");
			exit(-1);
		}
	}
	else
	{
		sleep(1);
		printf("in parent process\n");
		if(write(fd,ch2,strlen(ch2))==-1)
		{
 			printf("parent wirte error%m\n");
			exit(-1);
		}
		wait(&status);
	}
	return 0;
}
