#include <stdio.h>
#include <stdlib>
#include <unistd>
int main(){
	int i;
	printf("------------1:Berfor Calling------------);
	sleep(3);
	i=system("./test2");
	printf("------------1:After  Calling------------);
	printf("1:return value =%d\n",i);
	printf("------------2:Berfor Calling------------);
	sleep(3);
	i=system("./proj2");
	printf("------------2:After  Calling------------);
	printf("2:return value =%d\n",i);
	return 0;
}
