#include "ourhdr.h"
#define BUFF 8192
int main(void){
	int n;
	char buf[BUFF];
	while ((n=read(STDIN_FILENO,buf,BUFF))>0)
		if(write(STDOUT_FILENO,buf,n)!=n)
			err_sys("write erroer");
	if(n<0)
		err_sys("read erroe");
	exit(0);
}
