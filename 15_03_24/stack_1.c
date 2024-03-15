#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int item) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = item;
    }
}

int pop() {
    int item;
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        item = stack[top];
        top--;
        return item;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    push(1);
    push(2);
    push(3);
    display();
    printf("Popped item: %d\n", pop());
    display();
    return 0;
}
