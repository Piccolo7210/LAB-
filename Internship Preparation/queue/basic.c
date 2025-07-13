#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Queue structure
struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

// Initialize the queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Enqueue operation
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (q->front == -1) {
            q->front = 0; // If the queue is empty
        }
        q->arr[++(q->rear)] = value;
    }
}

// Dequeue operation
int dequeue(struct Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        return q->arr[(q->front)++];
    }
}

// Front operation
int front(struct Queue* q) {
    if (q->front != -1) {
        return q->arr[q->front];
    }
    return -1;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == -1 || q->front > q->rear);
}

int main() {
    struct Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element is: %d\n", front(&queue)); // Output: 10

    printf("Dequeued element: %d\n", dequeue(&queue)); // Output: 10

    return 0;
}