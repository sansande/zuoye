#include <stdio.h>
int main() {
	int a = 10;
	int b = 20;
	int* p;
	p = &a;
	printf("a = %d\n",a);
	printf("a的地址：%p\n",&a);
	printf("p = %p\n",p);
	printf("*p = %d\n",*p);
	p = &b;
	b = *p+10;
	printf("修改后b = %d\n",b);
	return 0;
}

