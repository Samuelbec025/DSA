#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};
typedef struct node* Node;

Node createNode()
{
    Node newNode = (Node)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Node not created");
        exit(0);
    }
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node insertRear(Node root)
{
    Node newNode = createNode();
    if(root == NULL)
    {
        return newNode;
    }
    Node temp = root;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return root;
}

Node insertFront(Node root)
{
    Node newNode = createNode();
    if(root == NULL)
    {
        return newNode;
    }
    newNode->next = root;
    root->prev = newNode;
    root = newNode;
    return root;
}

void displayForward(Node root)
{
    Node temp = root;
    if(temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayBackward(Node root)
{
    Node temp = root;
    if(temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

Node deleteFront(Node root)
{
    if(root == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    Node temp = root;
    root = root->next;
    if(root != NULL)
    {
        root->prev = NULL;
    }
    free(temp);
    return root;
}

Node deleteRear(Node root)
{
    if(root == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    Node temp = root;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    if(temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    free(temp);
    return root;
}

Node search(Node root)
{
    int key, flag = 0;
    if(root == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    printf("Enter the key to be found: ");
    scanf("%d", &key);
    Node temp = root;
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if(flag == 1)
    {
        printf("Key is found\n");
    }
    else
    {
        printf("Key is not found\n");
    }
    return root;
}

Node deleteGreaterThanKey(Node root)
{
    int key;
    if(root == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    printf("Enter the key: ");
    scanf("%d", &key);
    Node temp = root;
    while(temp != NULL)
    {
        if(temp->data > key)
        {
            if(temp->prev != NULL)
            {
                temp->prev->next = temp->next;
            }
            if(temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
            Node toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
        else
        {
            temp = temp->next;
        }
    }
    return root;
}

int main()
{
    Node root = NULL;
    int choice;
    do
    {
        printf("1: Insert at end\n");
        printf("2: Insert at beginning\n");
        printf("3: Display forwards\n");
        printf("4: Display backwards\n");
        printf("5: Delete rear element\n");
        printf("6: Delete front element\n");
        printf("7: Search an element\n");
        printf("8: Delete if key is greater than data\n");
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                root = insertRear(root);
                break;
            case 2:
                root = insertFront(root);
                break;
            case 3:
                displayForward(root);
                break;
            case 4:
                displayBackward(root);
                break;
            case 5:
                root = deleteRear(root);
                break;
            case 6:
                root = deleteFront(root);
                break;
            case 7:
                root = search(root);
                break;
            case 8:
                root = deleteGreaterThanKey(root);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 0);

    return 0;
}
