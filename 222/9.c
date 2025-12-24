#include <stdio.h>

int main() {
	int n;
	printf("输入一个正奇数n：");
	scanf("%d", &n);
	int mid = n / 2;

	for (int i = 0; i <= mid; i++) {
		for (int j = 0; j < mid - i; j++)
			printf(" ");
		for (int j = 0; j < 2 * i + 1; j++)
			printf("*");
		printf("\n");
	}

	for (int i = mid - 1; i >= 0; i--) {
	       for (int j = 0; j < mid - i; j++)
	       		printf (" ");
	       for (int j = 0; j < 2 * i + 1; j++)
			printf("*");
	       printf("\n");
	}
	return 0;
}
