#include "uhead.h"

//产生随机数
void urand(int *m,int n){
	int i;
	srand((int)time(0));
	for(i=0;i<n;i++)
		m[i]=1+(int)(100.0*rand()/(RAND_MAX+1.0));
}

//显示数组
void show(int *m,int n){
	int i;
	for(i=0;i<n;i++)
		printf("m[%d]=%d\n",i,m[i]);
}

//计算数组和
int usum(int *m,int n){
	int i,s=0;
	for(i=0;i<n;i++)
		s=s+m[i];
	return s;
}

//比较函数
int compar(const void *a,const void *b){
	int *aa=(int *)a,*bb=(int *)b;
	if(* aa>* bb)	return 1;
	if(* aa==* bb)	return 0;
	if(* aa<* bb)	return -1;
}

//冒泡函数
void bsort(int *m,int n){
	int i,j,temp;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(m[j]>m[j+1]){
				temp=m[j+1];
				m[j]=temp;
				m[j+1]=m[j];
			}
}

//比较冒泡排序和快速排序
void compar_b_q_sort(int *m,int n){
	clock_t start, finish;
	double  duration;
	start=clock();
	qsort(m,n,sizeof(int),compar);
	finish=clock();
	duration=(double)(finish-start)/CLOCKS_PER_SEC;
	printf("快速排序用时:%lf s\n",duration);
	start=clock();
	bsort(m,n);
	finish=clock();
	duration=(double)(finish-start)/CLOCKS_PER_SEC;
	printf("冒泡排序用时:%lf s\n",duration);
}
