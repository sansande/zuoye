#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_STUDENTS 50
#define FORMAT "%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n"

struct Student {
    int num;
    char name[15];
    double math;
    double english;
    double cLang;
    double sum;
};

struct Student stu[MAX_STUDENTS];
int count = 0;

void input();
void display();
void sort();
void search();
void menu();

int main() {
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: input();    break;
            case 2: search();   break;
            case 3: sort();     break;
            case 4: display();  break;
            case 0: printf("系统退出！\n"); break;
            default: printf("输入无效，请重新选择！\n");
        }
        if (choice != 0) {
            printf("按任意键继续...");
            getchar();
            getchar();
        }
    } while (choice != 0);
    return 0;
}

void menu() {
    system("clear");
    printf("\n==== 学生成绩管理系统 ====\n");
    printf("1. 录入学生信息\n");
    printf("2. 查找学生信息\n");
    printf("3. 按总分排序\n");
    printf("4. 显示所有学生信息\n");
    printf("0. 退出系统\n");
    printf("请选择操作(0-4): ");
}

void input() {
    char flag = 'y';
    FILE *fp = fopen("data.txt", "ab+");
    if (fp == NULL) {
        printf("文件打开失败！\n");
        return;
    }
    count = 0;
    while (fread(&stu[count], sizeof(struct Student), 1, fp) == 1) {
        count++;
    }
    rewind(fp);
    while (flag == 'y' || flag == 'Y') {
        if (count >= MAX_STUDENTS) {
            printf("已达最大学生数量（%d），无法继续录入！\n", MAX_STUDENTS);
            break;
        }
        printf("\n录入第%d名学生:\n", count + 1);
        printf("学号: ");
        scanf("%d", &stu[count].num);
        printf("姓名: ");
        scanf("%s", stu[count].name);
        printf("数学成绩: ");
        scanf("%lf", &stu[count].math);
        printf("英语成绩: ");
        scanf("%lf", &stu[count].english);
        printf("C语言成绩: ");
        scanf("%lf", &stu[count].cLang);
        stu[count].sum = stu[count].math + stu[count].english + stu[count].cLang;
        if (fwrite(&stu[count], sizeof(struct Student), 1, fp) != 1) {
            printf("写入文件失败！\n");
            break;
        }
        count++;
        printf("继续录入(y/n)? ");
        scanf(" %c", &flag);
    }
    fclose(fp);
    printf("录入完成！当前共%d名学生。\n", count);
}

void search() {
    int snum, found = 0;
    FILE *fp = fopen("data.txt", "rb");
    if (fp == NULL) {
        printf("文件未找到或为空！\n");
        return;
    }
    printf("输入要查找的学号: ");
    scanf("%d", &snum);
    while (fread(&stu[0], sizeof(struct Student), 1, fp) == 1) {
        if (stu[0].num == snum) {
            printf("\n查询结果:\n");
            printf("学号\t姓名\t数学\t英语\tC语言\t总分\n");
            printf(FORMAT, stu[0].num, stu[0].name, stu[0].math, stu[0].english, stu[0].cLang, stu[0].sum);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("未找到学号为%d的学生！\n", snum);
    }
    fclose(fp);
}

void sort() {
    struct Student temp;
    FILE *fp = fopen("data.txt", "rb+");
    if (fp == NULL) {
        printf("文件操作失败！\n");
        return;
    }
    count = 0;
    while (fread(&stu[count], sizeof(struct Student), 1, fp) == 1) {
        count++;
    }
    rewind(fp);
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (stu[j].sum < stu[j + 1].sum) {
                temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
    ftruncate(fileno(fp), 0);
    for (int i = 0; i < count; i++) {
        if (fwrite(&stu[i], sizeof(struct Student), 1, fp) != 1) {
            printf("排序后写入文件失败！\n");
            break;
        }
    }
    fclose(fp);
    printf("排序完成！已按总分降序重新保存。\n");
}

void display() {
    FILE *fp = fopen("data.txt", "rb");
    if (fp == NULL) {
        printf("文件未找到或为空！\n");
        return;
    }
    printf("\n学生信息列表:\n");
    printf("学号\t姓名\t数学\t英语\tC语言\t总分\n");
    while (fread(&stu[0], sizeof(struct Student), 1, fp) == 1) {
        printf(FORMAT, stu[0].num, stu[0].name, stu[0].math, stu[0].english, stu[0].cLang, stu[0].sum);
    }
    fclose(fp);
}
