#include<stdio.h>

void read(int arr[100][100], int num, int man)
{
	for(int i = 0; i < num; i++)
	{
		for(int j = 0; j < man; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
}

void addition(int arr[100][100], int brr[100][100], int num, int man)
{
	int result[num][man];
	for(int i = 0; i < num; i++)
	{
		for(int j = 0; j < man; j++)
		{
			result[i][j] = arr[i][j] + brr[i][j];
		}
	}
	printf("\nTotal Sales report: \n");
	for(int i = 0; i < num; i++)
	{
		printf("\n");
		for(int j = 0; j < man; j++)
		{
			printf("%d\t", result[i][j]);
		}
	}
}

int main(){
	int num, man;
	printf("Enter the number of Regions: ");
	scanf("%d", &num);
	printf("Enter the number of Salesmen: ");
	scanf("%d", &man);
	if(num > 0 && man > 0)
	{
		int arr[100][100];
		printf("Enter the sales report of Q1: \n");
		read(arr, num, man);

		int brr[100][100];
		printf("Enter the sales report of Q2: \n");
		read(brr, num, man);

		addition(arr, brr, num, man);
	}
	else{
		printf("invalid");
	}
	return 0;
}
