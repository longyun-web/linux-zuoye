#include "my.h"
/*测试管道最大容量为65536*/
int main(){
	pid_t r;
	char buf[1];
	int r_num;
	int pipefd[2];//管道
	memset(buf,0,sizeof(buf));
	if(pipe(pipefd)<0){
		perror("pipe failed.\n");
		return -1;
	}
	r=fork();
	if(r<0){
		perror("fork failed.\n");
		return -1;
	}
	else if(r==0){
		char b='a';
		close(pipefd[0]);
		printf("child pid = %d\n",getpid());
		//sprintf(w_buf,"child is running.pid=%d",getpid());
		/*if((wn=write(pipefd[1],w_buf,sizeof(w_buf)))<0){
			printf("write failed.\n");
			exit(-1);
		}*/
		for(int i=0;i<65536;i++){
			//printf("chikld write %d timer.\n",i);
			write(pipefd[1],&b,1);
		}
		printf("child write to ok\n");
		close(pipefd[1]);
		exit(0);
	}
	else{
		wait(NULL);
		close(pipefd[1]);
		/*if((rn=read(pipefd[0],r_buf,sizeof(r_buf)))<0){
			printf("read failed.\n");
			exit(-1);
		}*/
		for(int i=0;i<65537;i++){
			read(pipefd[0],buf,1);
			//printf("%d : parent read from pipe:%s\n",i,buf);
		}
		printf("parent read to ok\n");
		close(pipefd[0]);
		//printf("parent read from pipe total = %d,content %s\n",rn,r_buf);
		return 0;
	}
}
