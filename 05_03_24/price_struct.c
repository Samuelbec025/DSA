#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product_info {
    char name[10];
    float price;
    int quantity;
} pro;

void read_write(pro *I, int count) {
    for (int i = 0; i < count; i++) {
        printf("Product%d:\n", (i + 1));
        printf("Enter name: ");
        scanf("%s", (I + i)->name);
        printf("Enter price:");
        scanf("%f", &(I + i)->price);
        printf("Enter quantity:");
        scanf("%d", &(I + i)->quantity);
    }

    // Arrange the items in descending order based on price
    pro temp;
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if ((I + j)->price > (I + i)->price) {
                temp = *(I + i);
                *(I + i) = *(I + j);
                *(I + j) = temp;
            }
        }
    }

    printf("\nProducts in descending order of price:\n");
    for (int i = 0; i < count; i++) {
        printf("%s >> %.2f >> %d\n", (I + i)->name, (I + i)->price, (I + i)->quantity);
    }
}

void search(pro *I, int count) {
    char search[10];
    printf("\nEnter the Name of Product: ");
    scanf("%s", search);
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (!strcmp((I + i)->name, search)) {
            printf("Item Found!!!\n");
            printf("%s >> %.2f >> %d\n", (I + i)->name, (I + i)->price, (I + i)->quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found.\n");
    }
}

void highest(pro *I, int count) {
    int max = (I + 0)->quantity;
    int index = 0;

    for (int i = 1; i < count; i++) {
        if ((I + i)->quantity > max) {
            max = (I + i)->quantity;
            index = i;
        }
    }

    printf("%s has the highest quantity: %d\n", (I + index)->name, (I + index)->quantity);
}

int main() {
    int num;
    printf("Enter the number of Products: ");
    scanf("%d", &num);

    pro *I;
    I = (pro*)calloc(num, sizeof(pro));

    read_write(I, num);
    search(I, num);
    highest(I, num);

    free(I);
    return 0;
}
