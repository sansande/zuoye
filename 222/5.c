#include <stdio.h>

int main() {
	int n;
	int sum = 0;
	printf("输入一个正整数n：");
	scanf("%d", &n);

	for (int i = 1; i <= n; i += 2)
		sum += i;
	printf("1到n之间的奇数和：%d\n", sum);
	return 0;
}
