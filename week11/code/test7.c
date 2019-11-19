#include "my.h"
int main(){
	pid_t pid;
	int k,status;
	pid=fork();
	if(pid<0){
		perror("fork failed");
		return -1;
	}
	else if(pid==0){
		printf("child %d : runing!\n",getpid());
		//while(1);
		exit(120);
	}
	else{
		if((k=wait(&status))!=0){
			if(WIFEXITED(status))
				printf("child exit with exit!exit code=%d\n",WEXITSTATUS(status));
			else if(WIFSIGNALED(status))
				printf("child terminatated with signal!\n signal number =%d\n",WTERMSIG(status));
		}
	exit(0);
	}
}
