#include <stdio.h>

void bucketSort(float arr[], int n) {
    int i, j;
    float buckets[10][10];
    int bucketCount[10] = {0};

    for (i = 0; i < n; i++) {
        int index = (int)(arr[i] * 10);
        buckets[index][bucketCount[index]] = arr[i];
        bucketCount[index]++;
    }

    for (i = 0; i < 10; i++) {
        for (j = 0; j < bucketCount[i] - 1; j++) {
            for (int k = j + 1; k < bucketCount[i]; k++) {
                if (buckets[i][j] > buckets[i][k]) {
                    float temp = buckets[i][j];
                    buckets[i][j] = buckets[i][k];
                    buckets[i][k] = temp;
                }
            }
        }
    }

    int index = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < bucketCount[i]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}

void printArray(float arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    float arr[] = {0.42f, 0.32f, 0.23f, 0.52f, 0.25f, 0.47f, 0.51f};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
