#include "my.h"
//编译时末尾加上 -lpthread
void *threadfun(void *arg){
	printf("thread fun .pid=[%5d] \n",getpid());
}
int main(){
	pthread_t tid;
	int error;
	error=pthread_create(&tid,NULL,threadfun,NULL);
	if(error!=0){
		perror("thread creat failed!\n");
		return -1;
	}
	printf("master thread pid %d,work thread tid=%lx\n",getpid(),tid);
	pthread_join(tid,NULL);//不加这句不会执行线程
	return 0;
}
