#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define NUMBER 100

struct arg{
	int sum;
	float ave;
	int max;
	int min;
};

void urand(int *,int);
int usum(int *,int);
void show(int *,int);
void bsort(int *,int);
int compar(const void *,const void *);
void compar_b_q_sort(int *,int);
struct arg count(int*,int);
