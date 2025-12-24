#include <stdio.h>

int main() {
	int a,b,c,min;
	printf("输入三个整数：");
	scanf("%d %d %d", &a, &b, &c);
	
	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;

	printf("最小值：%d\n", min);
	return 0;
}

