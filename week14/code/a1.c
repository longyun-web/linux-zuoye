#include "my.h"
//测验栈的大小
int i=0;
void foo(){
	int buffzer[256];
	i++;
	printf("foo %d\n",i);
	foo();
}
int main(){
	foo();
	return 0;
}
