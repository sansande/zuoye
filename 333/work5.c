#include <stdio.h>

int two_dim_array_access(int *x, int i, int j, int m, int n, int C) {
    return *(x + i * C + j);
}

int main() {
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int result1 = two_dim_array_access(&A[0][0], 1, 2, 2, 3, 3);
    int result2 = two_dim_array_access(&A[0][1], 0, 1, 2, 3, 3);

    printf("结果1：%d\n", result1);
    printf("结果2：%d\n", result2);

    return 0;
}
