#include <stdio.h>

void towerOfHanoi(int n, char from, char to, char auxillary)
{
	if (n == 1)
	{
		printf("\n Move disk 1 from rod %c to rod %c", from, to);
		return;
	}
	towerOfHanoi(n-1, from, auxillary, to);
	printf("\n Move disk %d from rod %c to rod %c", n, from, to);
	towerOfHanoi(n-1, auxillary, to, from);
}

int main()
{
	int n; // Number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);
	towerOfHanoi(n, 'A', 'C', 'B'); //Names of rods
	return 0;
}*//*
#include<stdio.h>
int sum(int k);

int main() {
  int result = sum(10);
  printf("%d", result);
  return 0;
}

int sum(int k) {
  if (k > 0) {
    return k + sum(k - 1);
  } else {
    return 0;
  }
}
