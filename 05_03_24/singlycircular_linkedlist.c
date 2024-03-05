#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        newNode->next = (*head)->next;
        (*head)->next = newNode;
        int temp = (*head)->data;
        (*head)->data = newNode->data;
        newNode->data = temp;
    }
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* current = *head;
    struct Node* prev;

    if (current->data == key) {
        while (current->next != *head)
            current = current->next;
        *head = (*head)->next;
        current->next = *head;
        free(current);
        return;
    }

    while (current->next != *head && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current->data == key) {
        prev->next = current->next;
        free(current);
    } else {
        printf("Key not found in the list.\n");
    }
}

// Main function
int main() {
    struct Node* head = NULL;
  
    insertAtFront(&head, 3);
    insertAtFront(&head, 2);
    insertAtFront(&head, 1);

    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Circular Linked List: ");
    display(head);

    deleteNode(&head, 2);
    deleteNode(&head, 5);

    printf("Updated Circular Linked List: ");
    display(head);

    return 0;
}
