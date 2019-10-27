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
	interfacee();
	scanf("%s",&choice);
	switch(choice){
		case 0: exit();break;
		case 1:break;
		case 2:break;
		case 3:break;
		case 4:break;
		case 5:break;
		default:printf("请输入0-5！");
	}
}
