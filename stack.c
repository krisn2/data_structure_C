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

// Function to push an element at the bottom of the stack using an auxiliary stack
void push_at_bottom(Stack *stack, int element) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }

    Stack auxStack;
    initializeStack(&auxStack);

    // Move all elements from the original stack to the auxiliary stack
    while (!isEmpty(stack)) {
        push(&auxStack, pop(stack));
    }

    // Push the new element to the original stack
    push(stack, element);

    // Move all elements from the auxiliary stack back to the original stack
    while (!isEmpty(&auxStack)) {
        push(stack, pop(&auxStack));
    }
}

// Function to sort the stack using an auxiliary stack
void sortStack(Stack *stack) {
    if (isEmpty(stack)) {
        return;
    }

    Stack auxStack;
    initializeStack(&auxStack);

    // Pop elements from the original stack and insert them into the auxiliary stack in sorted order
    while (!isEmpty(stack)) {
        int temp = pop(stack);
        while (!isEmpty(&auxStack) && auxStack.data[auxStack.top] > temp) {
            push(stack, pop(&auxStack));
        }
        push(&auxStack, temp);
    }

    // Move the sorted elements back to the original stack
    while (!isEmpty(&auxStack)) {
        push(stack, pop(&auxStack));
    }
}

int main() {
    Stack myStack;
    initializeStack(&myStack);

    // Push elements onto the stack
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    push(&myStack, 5);
    push(&myStack, 15);

    // Sort the stack
    sortStack(&myStack);

    // Peek at the top element
    printf("Top element: %d\n", peek(&myStack));

    // Pop elements from the stack
    printf("Popped: %d\n", pop(&myStack));
    printf("Popped: %d\n", pop(&myStack));
    printf("Popped: %d\n", pop(&myStack));
    printf("Popped: %d\n", pop(&myStack));
    printf("Popped: %d\n", pop(&myStack)); // Attempt to pop from an empty stack

    return 0;
}