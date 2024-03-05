#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a transaction
struct Transaction 
{
    char type[20];
    float amount;
    struct Transaction* next;
};

// Function to create a new transaction node
struct Transaction* createTransaction(const char* type, float amount) 
{
    struct Transaction* newTransaction = (struct Transaction*)malloc(sizeof(struct Transaction));
    strcpy(newTransaction->type, type);
    newTransaction->amount = amount;
    newTransaction->next = NULL;
    return newTransaction;
}

// Function to add a transaction to the linked list
void addTransaction(struct Transaction** head, const char* type, float amount) 
{
    struct Transaction* newTransaction = createTransaction(type, amount);
    
    if (*head == NULL) 
    {
        *head = newTransaction;
    } 
    else 
    {
        struct Transaction* current = *head;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = newTransaction;
    }
}


// Function to display all transactions
void displayAllTransactions(struct Transaction* head) 
{
    printf("All Transactions:\n");
    printf("-----------------\n");
    
    struct Transaction* current = head;
    
    while (current != NULL) 
    {
        printf("Type: %s\n", current->type);
        printf("Amount: %.2f\n", current->amount);
        printf("-----------------\n");
        current = current->next;
    }
}

// Function to reverse the linked list
void reverseList(struct Transaction** head)
{
    struct Transaction* prev = NULL;
    struct Transaction* current = *head;
    struct Transaction* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Function to search and display recharge transactions
void displayRechargeTransactions(struct Transaction* head) 
{
    printf("Recharge Transactions:\n");
    printf("-----------------\n");
    
    struct Transaction* current = head;
    
    while (current != NULL) {
        if (strcmp(current->type, "Recharge") == 0) 
        {
            printf("Type: %s\n", current->type);
            printf("Amount: %.2f\n", current->amount);
            printf("-----------------\n");
        }
        current = current->next;
    }
}

// Function to free the memory allocated for the linked list
void freeList(struct Transaction* head) 
{
    struct Transaction* current = head;
    while (current != NULL) {
        struct Transaction* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() 
{
    struct Transaction* head = NULL;
    int choice;
    char type[20];
    float amount;
    
    do {
        printf("1. Add a transaction\n");
        printf("2. Display all transactions\n");
        printf("3. Display recharge transactions\n");
        printf("4. Reverse the transaction list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1:
                printf("Enter the transaction type: ");
                scanf("%s", type);
                printf("Enter the transaction amount: ");
                scanf("%f", &amount);
                addTransaction(&head, type, amount);
                printf("Transaction added successfully!\n");
                break;
            case 2:
                displayAllTransactions(head);
                break;
            case 3:
                displayRechargeTransactions(head);
                break;
            case 4:
                reverseList(&head);
                printf("Transaction list reversed!\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
        printf("\n");
    } 
    while (choice != 5);
    
    freeList(head);
    
    return 0;
}
