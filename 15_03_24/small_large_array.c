#include <stdio.h>

void findMinMax(int arr[], int size) {
    int min = arr[0], max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    printf("Smallest number: %d\n", min);
    printf("Largest number: %d\n", max);
}

int main() {
    int arr[] = {3, 1, 5, 7, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    findMinMax(arr, size);
    return 0;
}
