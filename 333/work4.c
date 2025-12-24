#include <stdio.h>
int main() {
	int A[2][3] = {{1,2,3},{4,5,6}};
	int total = 6;
	printf("二维数组A的内存存储顺序为：\n");
	for (int i = 0; i < total; i++) {
		printf("%d",A[0][i]);
	}
	printf("\n");
	return 0;
}

