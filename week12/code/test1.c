#include "my.h"
/*创建三个子进程而不产生额外进程*/
int main(){
	pid_t p,i,d;
	p=fork();
	if(p<0){
		perror("fork failed.\n");
		return -1;
	}
	else if(p==0){
		printf("child p pid = %d\n",getpid());
	}
	else{
		i=fork();
		printf("parent p pid = %d\n",getpid());
		if(i<0){
			perror("fork failed.\n");
			return -1;
		}
		else if(i==0){
			printf("child i pid = %d\n",getpid());
		}
		else{
			d=fork();
			printf("parent i pid = %d\n",getpid());
			if(d<0){
				perror("fork failed.\n");
				return -1;
			}
			else if(d==0){
				printf("child d pid = %d\n",getpid());
			}
			else{
				printf("parent d pid = %d\n",getpid());
			}
		}
	}
}
/*尝试产生3个子进程而不产生其他进程，虽然目的达到，但会重复创建相同进程*/
