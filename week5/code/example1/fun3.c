#include <time.h>
#include <stdlib.h>

//产生随机数
void urand(int *m,int n){
	int i;
	srand((int)time(0));
	for(i=0;i<n;i++)
		m[i]=1+(int)(100.0*rand()/(RAND_MAX+1.0));
}
