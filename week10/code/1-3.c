#include"my.h"                                                                                                                                                                                                                                 

int v=99;
int g=88;
int main(){
	int v=99;
	pid_t pid;
	pid=fork();
	if(pid<0){
		perror("fork failed!");
		exit(-1);
	}
	else if(pid==0){
		g++;
		v++;
		printf("child:pid=%d,g=%d,v=%d",getpid(),g,v);
		_exit(0);
	}
	else{
		printf("return value=%d\n",pid);
		printf("parent :pid=%d,g=%d,v=%d\n",pid,g,v);
		return 0;
	}
}
