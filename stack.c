#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int data[MAX_SIZE];
} Stack;

// Function to initialize a stack
void initializeStack(Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(Stack *stack, int element) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = element;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1; // Return a sentinel value to indicate underflow
    }
    int poppedElement = stack->data[stack->top];
    stack->top--;
    return poppedElement;
}

// Function to peek at the top element without removing it
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1; // Return a sentinel value to indicate emptiness
    }
    return stack->data[stack->top];
}

int main() {
    Stack myStack;
    initializeStack(&myStack);

    // Push elements onto the stack
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    // Peek at the top element
    printf("Top element: %d\n", peek(&myStack));

    // Pop elements from the stack
    printf("Popped: %d\n", pop(&myStack));
    printf("Popped: %d\n", pop(&myStack));
    printf("Popped: %d\n", pop(&myStack)); // Attempt to pop from an empty stack

    return 0;
}