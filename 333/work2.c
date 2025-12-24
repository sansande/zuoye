#include <stdio.h>
int main() {
	int nums[10];
	int count[10] = {0};
	int i,num;
	printf("输入十个0-9的整数；\n");
	for (i = 0; i < 10; i++) {
		scanf("%d",&nums[i]);
	}
	for (i = 0; i < 10; i++) {
		num = nums[i];
		count[num]++;
	}
	for (i = 0; i < 10; i++) {
		printf("数字%d出现了%d次\n",i,count[i]);
	}
	return 0;
}




