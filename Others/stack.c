#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	char name[50];
	int roll;
	struct node *next;
};
struct node *head;
void print(struct node *ptr);
void push(int x);
int pop();
int main(){
	head=NULL;
	head=malloc(sizeof(struct node));
	head->next=NULL;
	int time,i,val;	
	printf("How many elements? ");
	scanf("%d",&time);
	/*struct node *a;
	struct node *b;
	struct node *c;
	
	a=NULL;
	a=malloc(sizeof(struct node));
	b=NULL;
	b=malloc(sizeof(struct node));
	c=NULL;
	c=malloc(sizeof(struct node));
	head->next=a;
	a->next=b;
	b->next=c;
	c->next=NULL;
	a->roll=1;
	b->roll=2;
	c->roll=3;*/
	printf("Enter the value of the elements:\n");
	for(i=1;i<=time;i++){		
		scanf("%d",&val);
		push(val);
	}
	printf("\nStack:\n");
	print(head);
	int m;
	m=pop();
	printf("Pop value = %d",m);
	printf("\nAfter popping:\n");
	print(head);
	return 0;

}
void push(int x){
	struct node *ptr;
	struct node *new;
	new=NULL;
	new=malloc(sizeof(struct node));
	new->next=NULL;
	new->roll=x;
	if(head == NULL){
		
	head=new;	
	}
	else{
	ptr=head;
	new->next=ptr;
	head=new;	
	}
	
}
int pop(){
	struct node *ptr;
	int x;
	ptr=head;
	x=ptr->roll;
	head=head->next;
	free(ptr);
	return x;
}
void print(struct node *ptr){
while(ptr != NULL){
	printf("%d\n",ptr->roll);
	ptr = ptr->next;
	}
}
