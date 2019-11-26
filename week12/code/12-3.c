#include "my.h"
/*创建三个子进程而不产生额外进程*/
int count=0;
int main(){
	pid_t p,i,d;
	p=fork();
	int s1,s2,s3,r1,r2,r3;
	if(p<0){
		perror("fork failed.\n");
		return -1;
	}
	else if(p==0){
		count+=1;
		printf("child p pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
		exit(99);
	}
	else{
		printf("parent fork second time\n");
		i=fork();
		if(i<0){
			perror("fork failed.\n");
			return -1;
		}
		else if(i==0){
			count+=1;
			printf("child i pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
			exit(34);
		}
		else{
			printf("parent fork third time\n");
			d=fork();
			if(d<0){
				perror("fork failed.\n");
				return -1;
			}
			else if(d==0){
				count+=1;
				printf("child d pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
				exit(77);
			}
			else{
				printf("parent is waiting\n");
				r1=wait(&s1);
				r2=wait(&s2);
				r3=wait(&s3);
printf("r1=%d,s1=%d,r2=%d,s2=%d,r3=%d,s3=%d\n",r1,WEXITSTATUS(s1),r2,WEXITSTATUS(s2),r3,WEXITSTATUS(s3));
				printf("parent pid=%d,count=%d\n",getpid(),count);
			}
		}
	}
}
