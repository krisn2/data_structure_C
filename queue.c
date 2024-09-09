#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int front;
    int rear;
    int data[MAX_SIZE];
} Queue;

void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue *queue) {
    return queue->front == -1;
}

int isFull(Queue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(Queue *queue, int element) {
    if (isFull(queue)) {
        printf("Queue overflow!\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = element;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow!\n");
        return -1; // Return a sentinel value to indicate underflow
    }
    int dequeuedElement = queue->data[queue->front];
    if (queue->front == queue->rear) {
        initializeQueue(queue); // Empty the queue
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return dequeuedElement;
}

int peek(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1; // Return a sentinel value to indicate emptiness
    }
    return queue->data[queue->front];
}

int main() {
    Queue myQueue;
    initializeQueue(&myQueue);

    // Enqueue elements
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    // Dequeue elements
    printf("Dequeued: %d\n", dequeue(&myQueue));
    printf("Dequeued: %d\n", dequeue(&myQueue));
    printf("Dequeued: %d\n", dequeue(&myQueue)); // Attempt to dequeue from an empty queue

    return 0;
}