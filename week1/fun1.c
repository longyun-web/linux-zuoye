#include "uhead.h"

struct arg count(int *m,int n){
	int i;
	struct arg k;
	k.sum=0;
	for(i=0;i<n;i++)
		k.sum+=m[i];
	k.ave=(float)k.sum/n;
	return k;
}
