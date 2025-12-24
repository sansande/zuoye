#include <stdio.h>
void selectionSort( int arr[],int n) {
	for (int i = 0; i < n-1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			int temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}
}
int main() {
	int arr[] = {6,5,4,3,2,1};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("排序前：");
	for (int i = 0; i < n; i++) {
		printf("%d",arr[i]);
	}
	printf("\n");
	selectionSort(arr,n);
	printf("排序后；");
	for (int i = 0; i < n; i++) {
		printf("%d",arr[i]);
	}
	printf("\n");
	return 0;
}

