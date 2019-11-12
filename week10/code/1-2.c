#include "my.h"
static void callback1(){
	printf("------- callback1 --------\n");
}
static void callback2(){
	printf("\n------- callback2 --------\n");
}
static void __attribute__ ((constructor)) before_main(){
	printf("------- constructor --------\n");
}
static void __attribute__ ((destructor)) after_main(){
	printf("\n------- destructor --------\n");
}
int main(){
	atexit(callback1);
	atexit(callback2);
	FILE *fp;
	char buf[]="test data form full buffer!";
	if((fp=fopen("test.dat","w+"))==NULL){
		perror("create file failed!\n");
		return -1;
	}
	if(fputs(buf,fp)==EOF){
		perror("fputs file failed!\n");
		return -1;
	}
	printf("printf:data from line buffer\n");
	//exit(0);
	//_exit(0);
	return 0;
}
