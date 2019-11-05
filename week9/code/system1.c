#include <stdio.h>
#include <stdlib.h>

int main(int argc,const char *arcv[]){
	int ret=1;
	if(argc>=2)printf("arcv[1]=%s\r\n",arcv[1]);
	else printf("arcv[0]=%s\r\n",arcv[0]);
	ret=system("ls -a");
	printf("ret=%d,Byebye...\r\n");
	return 0;
}
