#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#define NUMBER 100

int main()
{
	int a[NUMBER];
	void *handle;
	void (*f1)();
	int (*f2)(),(*f3)();
	char *error;

	handle=dlopen("/home/rlk/linuxprogram/week6/code/dynamiclib/libdynamic.so",RTLD_LAZY);
	if(!handle){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f1=dlsym(handle,"urand");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f2=dlsym(handle,"max");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f3=dlsym(handle,"sum");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f1(a,NUMBER);
	printf("max=%d\n",f2(a,NUMBER));
	printf("sum=%d\n",f3(a,NUMBER));
	f1=dlsym(handle,"urand");
	if(dlclose(handle)<0){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	return 0;
}
