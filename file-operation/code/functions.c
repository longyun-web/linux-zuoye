#include "myhead.h"

void new_f(char *fname){
	FILE *fp;
	if((fp=fopen(fname,"wb"))==NULL){
		printf("\nopen file fail,close!");
		getchar();
		return;
	}
	else printf("%s文件创建成功！\n",fname);
	fclose(fp);
}
void write_f(){

}
void read_f(){

}
void modify_f(){

}
void view_f(){

}
