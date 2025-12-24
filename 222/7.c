#include <stdio.h>
#include <math.h>

int prime(int n) {
	if (n < 2)
		return 0;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return 0;
	return 1;
}

int main() {
	int x;
	printf("输入一个比1大的正数x：\n");
	scanf("%d", &x);
	printf("[1,x]范围内的所有素数：");
	for (int i = 2; i <= x; i++) {
		if (prime(i))
			printf("%d",i);
	}
	printf("\n");
	return 0;
}
