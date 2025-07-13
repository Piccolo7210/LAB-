// C program for insertion and deletion in Circular Queue using structure
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *arr;        
    int front, size; 
    int capacity;    
};

// Initialize the queue
void initQueue(struct Queue* q, int c) {
    q->arr = (int*)malloc(c * sizeof(int));
    q->capacity = c;
    q->size = 0;
    q->front = 0;
}

// Free the queue memory
void freeQueue(struct Queue* q) {
    free(q->arr);
}

// Get the front element
int getFront(struct Queue* q) {
    // Queue is empty
    if (q->size == 0) 
        return -1; 
    return q->arr[q->front];
}

// Get the rear element
int getRear(struct Queue* q) {
    // Queue is empty
    if (q->size == 0) 
        return -1; 
    int rear = (q->front + q->size - 1) % q->capacity;
    return q->arr[rear];
}

// Insert an element at the rear
void enqueue(struct Queue* q, int x) {
    // Queue is full
    if (q->size == q->capacity) {
        printf("Queue is full\n");
        return;
    }
    int rear = (q->front + q->size) % q->capacity;
    q->arr[rear] = x;
    q->size++;
}

// Remove an element from the front
int dequeue(struct Queue* q) {
    // Queue is empty
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    int res = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return res;
}

int main() {
    struct Queue q;
    initQueue(&q, 4);
    
    enqueue(&q, 10);
    printf("%d %d\n", getFront(&q), getRear(&q));
    
    enqueue(&q, 20);
    printf("%d %d\n", getFront(&q), getRear(&q));
    
    enqueue(&q, 30);
    printf("%d %d\n", getFront(&q), getRear(&q));
    
    enqueue(&q, 40);
    printf("%d %d\n", getFront(&q), getRear(&q));
    
    dequeue(&q);
    printf("%d %d\n", getFront(&q), getRear(&q));
    
    dequeue(&q);
    printf("%d %d\n", getFront(&q), getRear(&q));
    
    enqueue(&q, 50);
    printf("%d %d\n", getFront(&q), getRear(&q));
    
    freeQueue(&q);
    return 0;
}