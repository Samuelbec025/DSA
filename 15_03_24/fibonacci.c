#include <stdio.h>

int main() {
    int n, prev = 0, current = 1, next;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", prev);
        next = prev + current;
        prev = current;
        current = next;
    }
    printf("\n");
    return 0;
}
