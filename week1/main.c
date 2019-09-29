#include "uhead.h"

void main(){
	struct arg k;
	int m[NUMBER];	
	urand(m,NUMBER);
	show(m,NUMBER);
	printf("sum=%d\n",usum(m,NUMBER));
	k=count(m,NUMBER);
	printf("suum=%d,ave=%f\n",k.sum,k.ave);
}
