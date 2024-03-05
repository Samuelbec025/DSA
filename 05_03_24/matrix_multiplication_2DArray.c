#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, m1, n2, m2, c, d, k, first[10][10], second[10][10], sum[10][10];
		printf("Enter no. of Rows 1st:");
		scanf("%d",&m1);
		printf("Enter no. of Columns 1st:");
		scanf("%d",&n1);
		printf("\nEnter the %d elements of the first matrix \n\n", m1*n1);
		for(c = 0; c < m1; c++) //rows
        {
			for(d = 0; d < n1; d++)   //columns
            {
				first[c][d] = rand() % (500 + 1);
            }
        }


        printf("Enter no. of Rows 2nd:");
		scanf("%d",&m2);
		printf("Enter no. of Columns 2nd:");
		scanf("%d",&n2);

		printf("\nEnter the %d elements of the second matrix \n\n", m2*n2);
		for(c = 0; c < m2; c++) //rows
        {
			for(d = 0; d < n2; d++)   //columns
            {
				second[c][d] = rand() % (500 + 1);
            }
        }

        //FIRST

        printf("\n\nFirst Matrix:\n\n");
        for(c = 0; c < m1; c++)
        {
            for(d = 0; d < n1; d++)
            {
                printf("%d\t", first[c][d]);
            }
            printf("\n");
        }

        printf("\n\nSecond Matrix:\n\n");
        for(c = 0; c < m2; c++)
        {
            for(d = 0; d < n2; d++)
            {
                printf("%d\t", second[c][d]);
            }
            printf("\n");
        }
		if(n1 != m2)
		{
			printf("\n\n\n\t\tERROR!!!");
		}
		else if(n1 == m2){
        printf("Product of the matrices: \n");
		for(c = 0; c < m1; c++){
			for(d = 0; d < n2; d++){
				sum[c][d] = 0;
				for(k = 0; k < n1; k++){
					sum[c][d] += first[c][k] * second[k][d];
				}
			}
		}

		for(c = 0; c < m1; c++)
		{
			for(d = 0; d < n2; d++)
			{
				printf("%d\t", sum[c][d]);
			}
			printf("\n");
		}
		}
		else{
			return 0;
		}
}
