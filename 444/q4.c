#include <stdio.h>

int my_strlen(char *str) {
	int count = 0;
	while (*str != '\0') {
		count++;
		str++;
	}
	return count;
}

int main() {
	char str[50];
	printf("请输入一个字符串：");
	scanf("%s",str);
	int length = my_strlen(str);
	printf("字符串的长度为：%d\n",length);
	return 0;
}
	
