#include <stdio.h>
#include "module.h"  

int main() {
    int ret1 = func1();  
    int ret2 = func2();  

    printf("func1 返回值：%d\n", ret1);  
    printf("func2 返回值：%d\n", ret2);  

    printf("全局变量：%d\n", g_magic_number);  

    return 0;
}
