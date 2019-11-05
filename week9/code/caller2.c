#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	int ret;
	printf("caller1:pid=%d,ppid=%d\n",getpid(),getppid());
	execl("/home/rlk/linuxprogram/week9/code/test1","./test1","123","456",NULL);
	printf("after calling!\n");
	sleep(1);
	return 0;
}
