#include <stdio.h>

int main() {
    char ch;
    int bit;
    const char *bitNames[] = {"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth"};
    
    printf("输入1个字符：");
    scanf(" %c", &ch);  
    
    for (int i = 7; i >= 0; i--) {
        bit = (ch >> i) & 1;  
        printf("The %s bit is %d,\n", bitNames[i], bit);
    }
    return 0;
}
