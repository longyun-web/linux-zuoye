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
	char *ch1="child writed\n";
	char *ch2="parent writed\n";

	fd = open("test1.txt",O_RDWR|O_CREAT,0644);
	if(fd==-1)
	{
		printf("open or creat file error:%m\n");
		exit(-1);
	}
	pid=vfork();
	if(pid==-1)
	{
		printf("error fork\n");
		exit(-1);
	}
	else if(pid==0)
	{
		printf("in child process\n");
		if((write(fd,ch1,strlen(ch1)))<0)
			perror("child write error:%m\n");
		exit(-1);	//一定要关闭，不然父进程不能写，发生越界错误
	}
	else
	{
		printf("in parent process\n");
		if((write(fd,ch2,strlen(ch2)))<0)
 			perror("parent wirte error%m\n");
		exit(-1);
	}
	return 0;
}
