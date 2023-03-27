#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head;
struct node *tail;
void delete(int x);
void insert(int x);
void insertpos(int x ,int y);
void display(struct node *first,struct node *last);
int count();
int search(int x);
int main(){
	head=NULL;
	insert(10);
	insert(20);
	insert(30);
	insertpos(30,35);
	//delete(20);
	//display(head,tail);
	printf("Searched item position = %d",search(20));
}
void insert(int x){
	struct node *ptr;
	struct node *new;
	new=malloc(sizeof(struct node));
	new->next=NULL;
	new->prev=NULL;
	new->data=x;
	ptr=head;
	if(head == NULL){
		//new->prev=head;
		head=new;
		tail=new;
		
	}
	else{
		while(ptr->next){
			ptr=ptr->next;
		}
		new->prev=ptr;
		ptr->next=new;
		tail=new;
	}
}
void display(struct node *first,struct node *last){
	while(first){
	printf("%d\t",first->data);
	first=first->next;
	}
	/*printf("\n");
	while(last){
	printf("%d\t",last->data);
	last=last->prev;	
	}*/
	
}
void insertpos(int x ,int y){
	struct node *ptr;
	struct node *new;
	new=malloc(sizeof(struct node));
	new->next=NULL;
	new->prev=NULL;
	new->data=y;
	ptr=head;
	while(ptr->data!=x && ptr->next != NULL){
		ptr=ptr->next;		
	}
	if(ptr->next ==NULL){
		new->prev=ptr;
		ptr->next=new;	
	}
	else{
		new->prev=ptr;
		new->next=ptr->next;
		ptr->next=new;	
	}
	
}
void delete(int x){
	struct node *ptr;
	ptr=head;
	if(ptr == NULL){
		printf("Empty Linkied List.\n");	
	}
	else
	{
		while(ptr->data!=x && ptr->next != NULL)
		{
			ptr=ptr->next;	
		}
		if(ptr->data == x)
		{
			
			if(ptr->prev== NULL){
				head=ptr->next;			
			}
			else{
				ptr=ptr->prev;
				ptr->next=ptr->next->next;				
			}
				
		}
		else{
			printf("Deleting Item not found\n");
		}	
	}
	


}
int search(int x){
	struct node *ptr1;
	struct node *ptr2;
	ptr1=head;
	ptr2=tail;
	int total=count();
	int f=0,l=total;
	while(ptr1->next !=NULL && ptr2->prev!=NULL){
		f++;		
		if(ptr2->data == x){
			return l;			
		}
		if(ptr1->data ==x)
		{
			return f;	
		}	
			l--;	
	}
		
	
}
int count(){
	struct node *ptr;
	int count=0;
	ptr=head;	
	while(ptr)
	{
		ptr=ptr->next;	
		count++;
	}
return count;	
}
