#include <stdio.h>
int main() {
	int arr[20];
	int i , temp;
	printf("请输入十个整数：\n");
	for (i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < 5; i++) {
		temp = arr[i];
		arr[i] = arr[9-i];
		arr[9-i] = temp;
	}
	printf("逆序后的数组；\n");
	for (i = 0; i < 10; i++) {
		printf("%d",arr[i]);
	}
	printf("\n");
	return 0;
}
	


