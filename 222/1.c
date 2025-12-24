#include <stdio.h>

int main() {
	int year;
	int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	printf("输入年份：");
	scanf("%d",&year);

	if ((year%4==0 && year%100!=0)||(year%400==0))
		days[1] = 29;
	for (int i = 0; i < 12; i++)
		printf("%d月；%d天\n", i+1, days[i]);
	return 0;
}
