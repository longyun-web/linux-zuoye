#include "myhead.h"

void interface(){
	printf("********************************\n");
	printf("0.退出\n");
	printf("1.创建新文件\n");
	printf("2.写文件\n");
	printf("3.读文件\n");
	printf("4.修改文件权限\n");
	printf("5.查看当前文件权限\n");
	printf("********************************\n");
	printf("Please input your choice(0-5):");
}
void menu(){
	char choice;
	char fname[F_NAME];
//	FILE *fp;
	do{
		interface();
		scanf("%c",&choice);
		getchar();
		switch(choice){
			case '0': 
				exit(0);break;
			case '1':
				printf("请输入新文件名：");
				scanf("%s",fname);
				getchar();
				new_f(fname);
				/*if((fp=fopen(fname,"wb"))==NULL){
					printf("\nopen file fail,close!");
					getchar();
					return 0;
				}
				fclose(fp);*/
				break;
			case '2':
				printf("请输入写文件名：");
				break;
			case '3':
				printf("请输入读文件名：");
				break;
			case '4':
				printf("修改文件权限为：");
				break;
			case '5':
				printf("当前文件权限为：");
				break;
			default:printf("请输入0-5！\n");
		}
	}while(choice);
}
