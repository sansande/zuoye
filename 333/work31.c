#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int swapped; 
    for (int i = 0; i < n - 1; i++) { 
        swapped = 0;  
        for (int j = 0; j < n - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) { 
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; 
            }
        }

        if (swapped == 0) { 
            break;
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]); 

    printf("排序前：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n);

    printf("排序后：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
