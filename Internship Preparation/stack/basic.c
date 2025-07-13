#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Initialize the stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Push operation
void push(struct Stack* s, int value) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

// Pop operation
int pop(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return s->arr[(s->top)--];
    }
}

// Peek operation
int peek(struct Stack* s) {
    if (s->top != -1) {
        return s->arr[s->top];
    }
    return -1;
}

// Check if stack is empty
int isEmpty(struct Stack* s) {
    return (s->top == -1);
}

int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is: %d\n", peek(&stack)); // Output: 30

    printf("Popped element: %d\n", pop(&stack)); // Output: 30

    return 0;
}