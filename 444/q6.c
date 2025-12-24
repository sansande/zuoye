#include <stdio.h>
struct Student {
	char name[20];
	int score;
};

int main() {
	struct Student students[3], *p = students;

	int maxScore = -1;
	int maxIndex = 0;
	for (int i = 0; i < 3; i++) {
	       printf("请输入第 %d 名学生姓名：", i + 1);
	       scanf("%s",p->name);
	       printf("请输入第 %d 名学生成绩：", i + 1);
	       scanf("%d", &(p->score));
	       p++;
	}
	p = students;
	for (int i = 0; i < 3; i++) {
		if (p->score > maxScore) {
			maxScore = p->score;
		        maxIndex = i;
		}
		p++;
	}
	p = &students[maxIndex];
	printf("\n最高分学生：\n姓名：%s,成绩；%d\n",p->name,p->score);
	return 0;
}

