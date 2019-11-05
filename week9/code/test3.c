#include "my.h"

static void __attribute__ ((constructor)) before_main(){
	printf("-1:Running befored main!\n");
}

static void __attribute__ ((destructor)) after_main(){
	printf("999:Running befored main!\n");
}

static void callback1(){
	printf("1:Running after main!\n");
}

static void callback2(){
	printf("2:Running after main!\n");
}

static void callback3(){
	printf("3:Running after main!\n");
}

int main(){
	atexit(callback1);
	atexit(callback2);
	atexit(callback3);
	printf("test3:pid=%d,ppid-%d\n",getpid(),getppid());
	while(1);	//与test2相比，新增无限循环，程序无法正常结束
	sleep(2);
	return 0;
}
