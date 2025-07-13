#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = *head_ref;

    if (*head_ref != NULL)
        (*head_ref)->prev = new_node;

    *head_ref = new_node;
}
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    struct Node* temp = *head_ref;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
    new_node->prev = temp;
}
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found.\n", key);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head_ref = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}
void printForward(struct Node* head) {
    printf("Forward: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
void printBackward(struct Node* head) {
    if (head == NULL) return;

    // Move to the last node
    while (head->next != NULL)
        head = head->next;

    printf("Backward: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 1);

    printForward(head);    // Output: Forward: 20 10 5 1
    printBackward(head);   // Output: Backward: 1 5 10 20

    deleteNode(&head, 10);
    printForward(head);    // Output: Forward: 20 5 1

    freeList(head);
    return 0;
}
