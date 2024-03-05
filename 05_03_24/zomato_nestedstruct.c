#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Order_Info
{
    char name[10];
    int quantity;
} order;

typedef struct Customer_Info
{
    char name[10];
    char tid[15];
    int number;
    order id[10];
} customer;

void read(customer *I, int num)
{
    for(int i = 0; i < num; i++)
    {
        printf("Enter Customer%d details: ", (i + 1));
        printf("\nEnter customer name: ");
        scanf("%s", (I + i)->name);
        printf("Enter customer transaction Id: ");
        scanf("%s", (I + i)->tid);
        printf("Enter the no. of dishes odered by the customer: ");
        scanf("%d", &(I + i)->number);

        printf("Enter Order details of Customer%d:\n", (i + 1));
        for(int j = 0; j < (I + i)->number; j++)
        {
            printf("Enter the name of Order%d: ", (j + 1));
            scanf("%s", (I + i)->id[j].name);
            printf("Enter the quantity of Order%d: ", (j + 1));
            scanf("%d", &(I + i)->id[j].quantity);
        }
    }
}

void write(customer *I, int num)
{
    for(int i = 0; i < num; i++)
    {
        printf("\n\nCustomer%d: ", (i + 1));
        printf("%s-->", (I + i)->name);
        printf("%s ", (I + i)->tid);

        printf("\nOrder details of Customer%d: ", (i + 1));
        for(int j = 0; j < (I + i)->number; j++)
        {
            printf("%s x %d, ", (I + i)->id[j].name, (I + i)->id[j].quantity);
        }
        printf("\n");
    }
}

void billing(customer *I, int count)
{
    char search[15];
    int cost = 0, discount = 0;
    printf("Enter Transaction Id:");
    scanf("%s", search);
    for (int i = 0; i < count; i++)
    {
        if (!strcmp((I + i)->tid, search))
        {
            for(int j = 0; j < (I + i)->number; j++)
            {
                if(!strcmp((I + i)->id[j].name, "burger") || !strcmp((I + i)->id[j].name, "Burger"))
                {
                    cost += 100 * (I + i)->id[j].quantity;
                }
                else if(!strcmp((I + i)->id[j].name, "pizza") || !strcmp((I + i)->id[j].name, "Pizza"))
                {
                    cost += 500 * (I + i)->id[j].quantity;
                }
                else if(!strcmp((I + i)->id[j].name, "bread") || !strcmp((I + i)->id[j].name, "Bread"))
                {
                    cost += 35 * (I + i)->id[j].quantity;
                }
                else if(!strcmp((I + i)->id[j].name, "curry") || !strcmp((I + i)->id[j].name, "Curry"))
                {
                    cost += 250 * (I + i)->id[j].quantity;
                }
                else if(!strcmp((I + i)->id[j].name, "rice") || !strcmp((I + i)->id[j].name, "Rice"))
                {
                    cost += 90 * (I + i)->id[j].quantity;
                }
                else if(!strcmp((I + i)->id[j].name, "fries") || !strcmp((I + i)->id[j].name, "Fries"))
                {
                    cost += 50 * (I + i)->id[j].quantity;
                }

                discount = (I + i)->number > 5 || (I + i)->id[j].quantity > 5 ? cost - (cost * 0.1) : cost;
            }
        }
        printf("Amt Payable by Customer%d: %d", (i + 1), discount);
    }
}

void search(customer *I, int count)
{
    char search[15];
    printf("Search: ");
    scanf("%s", search);
    for (int i = 0; i < count; i++)
    {
        if (!strcmp((I + i)->name, search) || !strcmp((I + i)->tid, search))
        {
            printf("\n\nCustomer%d: ", (i + 1));
            printf("%s-->", (I + i)->name);
            printf("%s ", (I + i)->tid);

            printf("\nOrder details of Customer%d: ", (i + 1));
            for(int j = 0; j < (I + i)->number; j++)
            {
                printf("%s x %d, ", (I + i)->id[j].name, (I + i)->id[j].quantity);
            }
            printf("\n");
        }
    }
}

int main()
{
    int num;
    printf("Enter the number of Customers: ");
    scanf("%d", &num);

    customer *I = (customer*) calloc(num, sizeof(customer));
    
    read(I, num);
    write(I, num);
    billing(I, num);
    //search(I, num);

    free(I);
    return 0;
}
