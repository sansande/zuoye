#include <stdio.h>
int main() {
	long x = 1;
	*((char *)&x + 0) = 'c';
	*((char *)&x + 1) = '!';
	*((char *)&x + 2) = 'y';
	*((char *)&x + 3) = 'y';
	*((char *)&x + 4) = 'd';
	*((char *)&x + 5) = 's';
	*((char *)&x + 6) = '!';
	*((char *)&x + 7) = '\0';
	printf("%s",(char *)&x);
	return 0;
}
