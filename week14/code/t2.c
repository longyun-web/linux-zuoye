#include "my.h"
//修改程序
#define NUM_THREADS 8
int main(int argc,char *argv[]){
	pthread_t threads[NUM_THREADS];
	int rc,t;
	for(t=0;t<NUM_THREADS;t++){
		ptintf("Creating thread %d\n",t);
		rc=pthread_create(&threads[t],NULL,PrintHello,(void*)&t);
		if(rc){
			printf("ERROR;return code is %d\n",rc);
			exit(-1);
		}
	}
	pthread_exit(NULL);
}
