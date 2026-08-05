#include <stdio.h>

void countingSort(int arr[], int n) {
    int i;
    int max = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int count[max + 1];

    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    i = 0;
    for (int j = 0; j <= max; j++) {
        while (count[j] > 0) {
            arr[i] = j;
            i++;
            count[j]--;
        }
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    countingSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
