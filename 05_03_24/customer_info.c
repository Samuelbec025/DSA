#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct customer_info
{
    char name[10];
    char id[10];
    int order_num;
    float order_value;
}customer;

void read_write(customer *I, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("Enter Customer%d info: ", (i + 1));
        scanf("%s", (I + i)->name);
        scanf("%s", (I + i)->id);
        scanf("%d", &(I + i)->order_num);
        scanf("%f", &(I + i)->order_value);
    }
    for (int j = 0; j < count; j++)
    {
        printf("Customer%d info: ", (j + 1));
        printf("%s\t", (I + j)->name);
        printf("%s\t", (I + j)->id);
        printf("%d\t", (I + j)->order_num);
        printf("%f\t", (I + j)->order_value);
    }
}

void coupon(customer *I, int count)
{
    float price = 0;
    char coupon[10];
    for (int i = 0; i < count; i++)
    {
        if ((I + i)->order_num == 1)
        {
            printf("Enter coupon code: ");
            scanf("%s", coupon);
            if (!strcmp(coupon, "BUY"))
            {
                price = (I + i)->order_value - ((I + i)->order_value * 0.1);
                printf("Amt Payable -> Customer%d: %f", (i + 1), price);
            }  
        }
        else 
        {
            price = (I + i)->order_value;
            printf("Amt Payable -> Customer%d: %f", (i + 1), price);
        }
    } 
}

int main()
{
    int num; 
    customer *I;
    printf("Enter the number of students: ");
    scanf("%d", &num);
    I = (customer*)calloc(num,sizeof(customer));
    read_write(I, num);
    coupon(I, num);
    free(I);
    return 0;
}
