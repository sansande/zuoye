#include <stdio.h>
int main() {
	int a[5] = {1,2,3,4,5};
	int *p;
	p = a;
	for (int i = 0; i < 5; i++) {
		printf("a[%d}的值：%d,地址；%p\n",i, p[i], p + i);
	}
	return 0;
}







