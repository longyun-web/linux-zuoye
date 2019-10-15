#include "lib.h"
#include <stdio.h>

#define NUMBER 100

int main()
{
	int a[NUMBER];
	
	urand(a,NUMBER);
	printf("max=%d\n",max(a,NUMBER));
	printf("sum=%d\n",sum(a,NUMBER));

	return 0;
}
