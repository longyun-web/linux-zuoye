#include "my.h"
//两个线程共享一个数据，交替运行
void* worker1(void*);
void* worker2(void*);
int c=100;
sem_t mutex,full;
int main()
{
	int ret;
	pthread_t tid[2];
	ret=sem_init(&mutex,0,1);
	ret=sem_init(&full,0,0);
	ret=pthread_create(&tid[0],NULL,worker1,NULL);
	if(ret!=0)
    {
        perror("thread1 failed!\n");
        exit(1);
    }
	ret=pthread_create(&tid[1],NULL,worker2,NULL);
	if(ret!=0)
    {
        perror("thread1 failed!\n");
        exit(1);
    }
	for(int i=0;i<2;i++)
	pthread_join(tid[i],NULL);
	return 0;
}
void* worker1(void* arg)
{
	while(1)
	{
		sem_wait(&mutex);//相当于P操作
		if(c>0)
		{
			usleep(1000);
            printf("thread 1 sell ticket: %d\n",c--);
            sem_post(&full);//相当于V操作
        }
        else
        {
            sem_post(&full);
            break;
         }
	}
	return NULL;
}
void* worker2(void* arg)
{
	int ret; 
	while(1)
	{
		sem_wait(&full);
		if(c>0)
        {
            usleep(1000);
            printf("thread 2 sell ticket: %d\n",c--);
            sem_post(&mutex);

        }
        else
        {
             sem_post(&mutex);
            break;
         }
     }
    return NULL;
}
