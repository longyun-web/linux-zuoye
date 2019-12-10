#include "my.h"
//通过参数往子进程传值过去
//0-3子进程分别计算1-100,1-200,1-300,1-400的和
#define NUM 4
struct shuzu{int m;int n;};//m编号,n100个数
struct rval{int sum;pthread_t tid;};
void fun(void *t){
	pthread_t mytid;
	struct shuzu *y;
	int s=0;
	y=(struct shuzu *)(t);
	for(int i=0;i<=(y->n);i++){
		s+=i;
	}
	mytid=pthread_self();
	printf("\tThread %d:my tid is %lx,hello word\n",(int)y->m+1,mytid);
	printf("\tThread %d:sum 1 to %d is %d\n",(int)y->m,y->n,s);
}
int main(){
	pthread_t tid;
	struct shuzu a[4];
	int rv,i;
	for(i=0;i<NUM;i++){
		a[i].m=i;
		a[i].n=100*(i+1);
		rv= pthread_create(&tid,NULL,(void *(*)())fun,(void *)&a[i]);
//(void *(*)())fun,*(*)()fun是函数指针，因为函数是void类型,所以要强转为void
		if(rv!=0){
			printf("thread create failed!\n");
			return -1;
		}
		printf("Create thread %lx\n",tid);
	}
	printf("Good bye!\n");
	pthread_exit(NULL);
	return 0;
}
