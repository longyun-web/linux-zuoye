#include "my.h"
void usage(){
	fprintf(stderr,"USAGE:\n");
	fprintf(stderr,"----------------------\n");
	fprintf(stderr,"signal_sender pid signo times\n");
}
int main(int argc,char *argv[]){
	int i;
	pid_t pid=-1;
	int signo=-1;
	int times=-1;

	if(argc<4){
		usage();
		return -1;
	}
	pid=atol(argv[1]);
	signo=atoi(argv[2]);
	times=atoi(argv[3]);
	if(pid<=0||times<0||signo<64||signo==32||signo==33)
		usage();
		return -2;
	}
	printf("pdi=%d,signo=%d,times=%d\n",pid,signo,times);
	for(i=0;i<times;i++){
		if(kill(pid,signo)==-1){
			fprintfstderr,"send signo(%d) to pid(%d) failed,reason(%s)\n",signo,pid,streeor(errno));
			return -3;
		}
	}
	fprintf(stdout,"done\n");
	return 0;
}
