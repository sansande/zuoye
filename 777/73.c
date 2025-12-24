#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN sizeof(struct student)
#define FORMAT "%-8d%-15s%-12.1lf%-12.1lf%-12.1lf%-12.1lf\n"
#define DATA stu[i].num, stu[i].name, stu[i].math, stu[i].english, stu[i].cLang, stu[i].sum

struct student {
    int num;          
    char name[15];    
    double math;      
    double english;   
    double cLang;     
    double sum;       
};

struct student stu[50];  

void in();        
void show();      
void order();       
void menu();      
void search();    

void main() {
    int n;
    menu();        
    scanf("%d", &n);
    while (n) {
        switch (n) {
            case 1:
                in();     
                break;
            case 2:
                search(); 
                break;
            case 3 :
                order();  
                break;
            case 4:
                show();   
                break;
            default:
                break;
        }
        getchar();
        menu();          
        scanf("%d", &n);
    }
}

void menu() {
    system("clear");
    printf("\n\n\n\n");
    printf("\t\t\t---- 学生信息管理系统 ----\n");
    printf("\t\t\t\t\t\n");
    printf("\t\t\t 1. 录入学生信息\t\n");
    printf("\t\t\t 2. 查找学生信息\t\n");
    printf("\t\t\t 3. 排序\t\t\n");
    printf("\t\t\t 4. 显示所有学生信息\t\n");
    printf("\t\t\t 0. 退出系统\t\t\n");
    printf("\t\t\t--------------------------\n\n");
    printf("\t\t\t请选择(0-4):");
}

void in() {
    int i, m = 0;
    char ch[2];
    FILE *fp;
    if ((fp = fopen("data.txt", "a+")) == NULL) {
        printf("文件不存在！\n");
        return;
    }
    while (!feof(fp)) {
        if (fread(&stu[m], LEN, 1, fp) == 1) {
            m++;
        }
    }
    fclose(fp);
    if (m == 0) {
        printf("文件中没有记录!\n");
    } else {
        show(); 
    }
    if ((fp = fopen("data.txt", "wb")) == NULL) {
        printf("文件不存在！\n");
        return;
    }
    printf("输入学生信息(y/n):");
    scanf("%s", ch);
    while (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0) {
        printf("number:");
        scanf("%d", &stu[m].num);
        for (i = 0; i < m; i++) {
            if (stu[i].num == stu[m].num) {
                printf("number 已经存在了，按任意键继续!");
                fclose(fp);
                return;
            }
        }
        printf("name:");
        scanf("%s", stu[m].name);         
        printf("math:");
        scanf("%lf", &stu[m].math);       
        printf("english:");
        scanf("%lf", &stu[m].english);     
        printf("cLang:");
        scanf("%lf", &stu[m].cLang);       
        stu[m].sum = stu[m].math + stu[m].english + stu[m].cLang;
        if (fwrite(&stu[m], LEN, 1, fp) != 1) {
            printf("不能保存！");
            getchar();
        } else {
            printf("%s 被保存\n", stu[m].name);
        }
        printf("继续?(y/n)");
        scanf("%s", ch);
        m++;
    }
    fclose(fp);
    printf("\n\n");
}

void search() {
    FILE *fp;
    int snum, i, m = 0;
    if ((fp = fopen("data.txt", "rb")) == NULL) {
        printf("文件不存在！\n");
        return;
    }
    while (!feof(fp)) {
        if (fread(&stu[m], LEN, 1, fp) == 1) {
            m++;
        }
    }
    fclose(fp);
    if (m == 0) {
        printf("文件中没有记录！\n");
        return;
    }
    printf("请输入 number:");
    scanf("%d", &snum);  
    for (i = 0; i < m; i++) {
        if (snum == stu[i].num) { 
            printf("number\tname\tmath\tenglish\tcLang\tsum\n");
            printf(FORMAT, DATA); 
            break;
        }
    }
    if (i == m) { 
        printf("没有找到这名学生!\n");
    }
}

void show() {
    FILE *fp;
    int i, m = 0;
    fp = fopen("data.txt", "rb"); 
    while (!feof(fp)) {
        if (fread(&stu[m], LEN, 1, fp) == 1) {
            m++;
        }
    }
    fclose(fp); 
    printf("number\tname\tmath\tenglish\tcLang\tsum\n");
    for (i = 0; i < m; i++) {
        printf(FORMAT, DATA); 
    }
}

void order() {
    FILE *fp;
    struct student t;
    int i = 0, j = 0, m = 0;
    if ((fp = fopen("data.txt", "r+")) == NULL) { 
        printf("文件不存在！\n");
        return;
    }
    while (!feof(fp)) {
        if (fread(&stu[m], LEN, 1, fp) == 1) {
            m++;
        }
    }
    fclose(fp);
    if (m == 0) {
        printf("文件中没有记录\n");
        return;
    }
    for (i = 0; i < m - 1; i++) {
        for (j = i + 1; j < m; j++) {
            if (stu[i].sum < stu[j].sum) {
                t = stu[i];
                stu[i] = stu[j];
                stu[j] = t;
            }
        }
    }
    if ((fp = fopen("data.txt", "wb")) == NULL) { 
        printf("文件不存在！\n");
        return;
    }
    for (i = 0; i < m; i++) {
        if (fwrite(&stu[i], LEN, 1, fp) != 1) {
            printf("%s 不能保存文件!\n", stu[i].name);
            getchar();
        }
    }
    fclose(fp);
    printf("保存成功\n");
}
