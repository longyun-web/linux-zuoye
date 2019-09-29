#include "uhead.h"

void urand(int *m,int n){
	int i;
	srand((int)time(0));
	for(i=0;i<n;i++)
		m[i]=1+(int)(100.0*rand()/(RAND_MAX+1.0));
}

void show(int *m,int n){
	int i;
	for(i=0;i<n;i++)
		printf("m[%d]=%d\n",i,m[i]);
}

int usum(int *m,int n){
	int i,s=0;
	for(i=0;i<n;i++)
		s=s+m[i];
	return s;
}
