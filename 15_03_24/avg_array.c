#include <stdio.h>

#define MAX_SIZE 100

float average(int arr[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Average of array elements: %.2f\n", average(arr, size));
    return 0;
}
