#include <stdio.h>

int main() {
	int num;
	int rev = 0;
	printf("输入一个整数：");
	scanf("%d", &num);
	while ( num != 0) {
		rev = rev * 10 + num % 10;
		num /= 10;
	}
	printf("反转后的数是：%d\n", rev);
	return 0;
}	
