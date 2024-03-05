#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Node inserted at the beginning successfully!\n");
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        printf("Node inserted at the end successfully!\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Node inserted at the end successfully!\n");
}

// Function to insert a node at a specific position in the linked list
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Position exceeds the length of the linked list!\n");
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position exceeds the length of the linked list!\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d successfully!\n", position);
}

// Function to delete a node at a specific position in the linked list
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }
    if (position == 1) {
        struct Node* temp = *head;
        *head = temp->next;
        free(temp);
        printf("Node deleted from position %d successfully!\n", position);
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    for (int i = 1; i < position; i++) {
        if (temp == NULL) {
            printf("Position exceeds the length of the linked list!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position exceeds the length of the linked list!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node deleted from position %d successfully!\n", position);
}

// Function to delete the front node of the linked list
void deleteFront(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }
    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
    printf("Front node deleted successfully!\n");
}

// Function to delete the back node of the linked list
void deleteBack(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Back node deleted successfully!\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    printf("Back node deleted successfully!\n");
}

// Function to search for a node in the linked list
void searchNode(struct Node* head, int data) {
    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("Node with data %d found at position %d.\n", data, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Node with data %d not found in the linked list.\n", data);
}

// Function to search for a node and replace its value in the linked list
void searchAndReplace(struct Node* head, int searchData, int replaceData) {
    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == searchData) {
            temp->data = replaceData;
            printf("Node with data %d replaced with %d.\n", searchData, replaceData);
            return;
        }
        temp = temp->next;
    }
    printf("Node with data %d not found in the linked list.\n", searchData);
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked list elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, searchData, replaceData;

    while (1) {
        printf("\n**** Singly Linked List Operations ****\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("4. Delete at a specific position\n");
        printf("5. Delete front\n");
        printf("6. Delete back\n");
        printf("7. Search for a node\n");
        printf("8. Search and replace a node\n");
        printf("9. Display the linked list\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                printf("Enter the position of the node to be deleted: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 5:
                deleteFront(&head);
                break;
            case 6:
                deleteBack(&head);
                break;
            case 7:
                printf("Enter the data to be searched: ");
                scanf("%d", &searchData);
                searchNode(head, searchData);
                break;
            case 8:
                printf("Enter the data to be searched: ");
                scanf("%d", &searchData);
                printf("Enter the data to replace: ");
                scanf("%d", &replaceData);
                searchAndReplace(head, searchData, replaceData);
                break;
            case 9:
                displayList(head);
                break;
            case 10:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}
