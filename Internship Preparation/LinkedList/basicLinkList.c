#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void createHead(struct Node** head,int data);
void insertEnd(struct Node** head, int data);
void insertFirst(struct Node** head, int data);
void reverseList(struct Node** head);
struct Node* mergeSortedLists(struct Node* a, struct Node* b) ;
void deletebyvalue(struct Node** head, int data);
void printList(struct Node* head);
void printMiddle(struct Node* head);
int main(){
  struct Node* head=NULL;
    createHead(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    printList(head);
    insertFirst(&head, 5);
    printList(head);
    printMiddle(head);
    return 0;
}
void createHead(struct Node** head,int data){
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
}
void insertEnd(struct Node** head, int data){
    if(*head == NULL) {
        createHead(head, data);
        return;
    }
    struct Node* temp=NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    temp = *head;
    while((temp->next) != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertFirst(struct Node** head, int data){
    if(*head == NULL) {
        createHead(head, data);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
void printList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void reverseList(struct Node** head){
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    
    while(current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev to current
        current = next;       // Move to next node
    }
    *head = prev; // Update head to new first node
}
struct Node* mergeSortedLists(struct Node* a, struct Node* b) {
    if (!a) return b;
    if (!b) return a;

    struct Node* result = NULL;

    if (a->data < b->data) {
        result = a;
        result->next = mergeSortedLists(a->next, b);
    } else {
        result = b;
        result->next = mergeSortedLists(a, b->next);
    }

    return result;
}
void printMiddle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow != NULL)
        printf("Middle element: %d\n", slow->data);
}
void deletebyvalue(struct Node** head, int data){
     struct Node* temp = *head, *prev = NULL;

    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; // Key not found

    prev->next = temp->next;
    free(temp);
}
