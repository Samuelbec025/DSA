#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, c, d, first[10][10], second[10][10], sum[10][10], diff[10][10];
		printf("Enter no. of Rows:");
		scanf("%d",&m);
		printf("Enter no. of Columns:");
		scanf("%d",&n);
		printf("\nEnter the %d elements of the first matrix \n\n", m*n);
		for(c = 0; c < m1; c++) //rows
        {
			for(d = 0; d < n1; d++)   //columns
            {
				scanf("%d", &first[c][d]);
            }
        }

		printf("\nEnter the %d elements of the second matrix \n\n", m*n);
		for(c = 0; c < m; c++) //rows
        {
			for(d = 0; d < n; d++)   //columns
            {
				scanf("%d", &second[c][d]);
            }
        }

        //FIRST

        printf("\n\nFirst Matrix:\n\n");
        for(c = 0; c < m; c++)
        {
            for(d = 0; d < n; d++)
            {
                printf("%d\t", first[c][d]);
            }
            printf("\n");
        }

        printf("\n\nSecond Matrix:\n\n");
        for(c = 0; c < m; c++)
        {
            for(d = 0; d < n; d++)
            {
                printf("%d\t", second[c][d]);
            }
            printf("\n");
        }

        for(c = 0; c < m; c++)
			for(d = 0; d < n; d++)
				sum[c][d] = first[c][d] + second[c][d];

		printf("\n\nSUM:\n\n");
		for(c = 0; c < m; c++)
		{
			for(d = 0; d < n; d++)
			{
				printf("%d\t", sum[c][d]);
			}
			printf("\n");
		}
}
