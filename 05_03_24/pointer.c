#include <stdio.h>

void sorter(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void main()
{
    int a, b, c;
    printf("Enter num1: ");
    scanf("%d", &a);
    printf("Enter num2: ");
    scanf("%d", &b);
    sorter(&a, &b);
    printf("num1: %d\tnum2: %d", a, b);
}
