#include <stdio.h>
#include <string.h>
void sortRow(char row[], int cols) {
    for (int i = 0; i < cols - 1; i++) {
        for (int j = 0; j < cols - i - 1; j++) {
            if (row[j] > row[j + 1]) {
                char temp = row[j];
                row[j] = row[j + 1];
                row[j + 1] = temp;
            }
        }
    }
}
int calculateRowSum(char row[], int cols) {
    int sum = 0;
    for (int i = 0; i < cols; i++) {
        sum += row[i];
    }
    return sum;
}
void sort2DArray(char arr[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        sortRow(arr[i], cols);
    }

    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            int sumJ = calculateRowSum(arr[j], cols);
            int sumJ1 = calculateRowSum(arr[j + 1], cols);
            if (sumJ > sumJ1) {
                char temp[100];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}
int main() {
    char A[][100] = {
        {'S', 'D', 'U', 'Y', 'E', 'S'},
        {'C', 'H', 'I', 'N', 'A', 'I'},
        {'A', 'F', 'T', 'E', 'R', 'X'},
        {'h', 'e', 'r', 'o', 'a', 'b'},
        {'C', 'y', 'y', 'D', 'S', 'I'}
    };
    int rows = 5;
    int cols = 6;  
    printf("排序前：\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", A[i][j]);
        }
        printf("\n");
    }

    sort2DArray(A, rows, cols);

    printf("\n排序后：\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
