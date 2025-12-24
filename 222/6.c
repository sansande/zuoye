#include <stdio.h>
#include <math.h>

int main() {
	int n;
	int prime = 1;
	printf("输入一个正数n：");
	scanf("%d", &n);

	if (n < 2)
		prime = 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			prime = 0;
			break;
		}
	}
	printf("%s\n", prime?"yes":"no");
	return 0;
}
