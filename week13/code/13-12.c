#include "my.h"
//编译时末尾加上 -lpthread
void *threadfun(void *arg){
	printf("thread fun .pid=[%5d] \n",getpid());
	return (void *)0;
}
int main(int argc,char *argv[]){
	pthread_t tid;
	int error;
	error=pthread_create(&tid,NULL,threadfun,NULL);
	if(error!=0){
		perror("thread creat failed!\n");
		return -1;
	}
	pthread_join(tid,threadfun);//不加这句不会执行线程
	printf("Done!\n");
	return 0;
}
