#include <stdio.h>

void swap(int *x,int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int main () {
	int num1,num2;
	printf("请输入第一个整数：");
	scanf("%d",&num1);
	printf("请输入第二个整数：");
	scanf("%d",&num2);

	swap(&num1, &num2);
	printf("两个整数交换后；%d %d\n",num1,num2);
	return 0;
}





	

	


