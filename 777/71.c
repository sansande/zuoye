#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <dos,h>
#define LEN sizeof(struct student)
#define FORMAT "%-8d%-15s%-12.1lf%-12.1lf%-12.1lf%-12.1lf\n"
#define DATA stu[i].num,stu[i].name,stu[i].math,stu[i].english,stu[i].C_languag,stu[i].sum
struct student
{
	int num;
	char name[15];
	double math;
	double english;
	double C_language;
	double sum;
};
struct student stu[50];

void in();
void show();
void order();
void menu();
void search();
void menu()
{
	system("clear");
	printf("\n\n\n\n");
	printf("\t\t|       学生信息管理系统       |\n");
	printf("\t\t|\t\t 1.录入学生信息\t\t|\n");
	printf("\t\t|\t\t 2.查找学生信息\t\t|\n");
	printf("\t\t|\t\t 3.输入学生信息\t\t|\n");
	printf("\t\t|\t\t 4.排序\t\t        |\n");
	printf("\t\t|\t\t 5.显示所有学生信息\t\t|\n");
	printf("\t\t|\t\t 0.退出系统\t\t    |\n");
	printf("请选择（0-5）：");
}
void main()
{
	int n;
	menu();
	scanf("%d",&n);
	while(n)
	{
		switch(n)
		{
			case 1:
				in();
				break;
			case 2:
				search();
				break;
			case 3:
			        del();
		                break;
		        case 4:
				modify();
				break:
		 	case 5:
				insert();
				break:
			case 6:
				order();
				break:
			case 7:
				total():
				break;
			case 8:
				show():
				break;
			default:
				break;
		}
		getchar();
		menu();
		scanf("%d",&n);
	}
}
void in()
{
	int i, m = 0;
	char ch[2];
	FILE *fp;
	if((fp = fopen("data.txt","a+")) == NULL)
	{
		printf("文件不存在\n");
		return;
	}
	while(!feop(fp))
	{
		if(fread(&stu[m],LEN,1,fp) == 1)
		{
			m++;
		}
	}
	fclose(fp);
	if(m == 0)
	{
		printf("文件中没有记录\n");
	}
	else
	{
		show();
	}
	if((fp = fopen("data.txt","wb")) == NULL)
	{
		printf("文件不存在\n");
		return;
	}
	printf("输入学生信息(y/n):");
	scanf("%s",ch);
	while(strcmp(ch,"Y") == 0 || strcmp(ch,"y") == 0)
	{
