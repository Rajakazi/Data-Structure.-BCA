#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;  // Stack is initially empty

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value; // Increment top, then insert element
}

// Display function to see the stack's current elements
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();  // Stack after push operations: 10, 20, 30

    return 0;
}
