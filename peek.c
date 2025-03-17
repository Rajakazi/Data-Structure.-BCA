#include <stdio.h>
#include <stdlib.h>

// Stack Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL; // Initially empty stack

// Push function
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Peek function
int peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data; // Return top element without removing it
}

// Display function
void display() {
    struct Node* temp = top;
    if (!temp) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();

    printf("Top element (Peek): %d\n", peek()); // Output: 30
    display(); // Stack remains unchanged

    return 0;
}
