#include<stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};
void deletelast(struct node *head);
void insertfirst(int val,struct node *head,struct node *new);
void printlinkedlist(struct node *ptr);
void last(int value,struct node *one,struct node *n);
void deletefirst(struct node *ss);
void deleteitem(struct node *head,int item);
int main(){
	struct node *head;
	struct node *a;
	struct node *b;
	struct node *c;
	a= NULL;
	b= NULL;
	c= NULL;
	a= malloc(sizeof(struct node ));
	b=malloc(sizeof(struct node));
	c=malloc(sizeof(struct node));
	a->num=10;
	b->num=20;
	c->num=30;
	a->next=b;
	b->next=c;
	c->next=NULL;
	head->next=a;
	struct node *new;
	new=NULL;
	//new->next=NULL;
	new = malloc(sizeof(struct node));
	//new->next =head;
	//head=new;
	//new->num=5;
	
	//insertfirst(5,head,new);
	//last(50,head,new);
	//deletefirst(head);
	deleteitem(head,20);
	deletelast(head);
	printlinkedlist(head);
	return 0;
}
void insertfirst(int val,struct node *ss,struct node *new){
	new->num=val;
	new->next =ss->next;
	ss->next=new;
	
}
void last(int value,struct node *one,struct node *n){
	n->num =value;	
	struct node *ptr;
	ptr=one;		
	while(ptr->next){
	ptr=ptr->next;	
	}
	ptr->next=n;
	n->next=NULL;
	
}
void printlinkedlist(struct node *ptr){
	ptr = ptr->next;
while(ptr != NULL){
	
	//printf("Name : %s\n",ptr->name);
	printf("Number : %d\n",ptr->num);
	ptr = ptr->next;
	}
}
void deletefirst(struct node *ss){
	struct node *ptr;
	ptr=ss->next;
	ptr=ptr->next;
	ss->next=ptr;
}
void deleteitem(struct node *ss,int item){
	struct node *change;
	struct node *ptr;	
	ptr=ss->next;
	while(ptr!=NULL){
		change=ptr->next;
		if(change->num == item){
			ptr->next=change->next;
			break;	
		}
		ptr=ptr->next;
	}
}
void deletelast(struct node *head){
	struct node *ptr;
	struct node *last;
	ptr=head->next;
	while(ptr!=NULL){
		last=ptr->next;
		if(last->next == NULL){
		ptr->next=NULL;
		break;	
	}
	ptr=ptr->next;

	}	
}
