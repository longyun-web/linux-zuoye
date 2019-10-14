#include "../example1/lib/lib.h"
int main()
{
	int a[10]={1,45,-8,9,10,12,4,78,9,46};
	printf("max=%d",max(a,10));
	printf("sum=%d",sum(a,10));
	return 0;
}
