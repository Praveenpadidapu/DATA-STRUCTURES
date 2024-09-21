#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
void create_node(struct node**head,int d);
void create_node(struct node**head,int d){
	struct node*temp=malloc(sizeof(struct node*));
	temp->data=d;
	temp->next=NULL;
	*head=temp;
}
void display(struct node*head);
void display(struct node*head)
{
	struct node*ptr=head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}
int count_of_nodes(struct node*head);
int count_of_nodes(struct node*head)
{
	int count=0;
struct node*ptr=head;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->next;
	}
	printf("number of nodes = %d",count);	
}
void insert_at_beginning(struct node**head,int d);
void insert_at_beginning(struct node**head,int d)
{
	struct node*temp=malloc(sizeof(struct node*));
	temp->data=d;
	temp->next=NULL;
	temp->next=*head;
	*head=temp;
}
void insert_at_end(struct node*head,int d);
void insert_at_end(struct node*head,int d)
{
struct node*temp=malloc(sizeof(struct node*));
	temp->data=d;
	temp->next=NULL;
	struct node*ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=temp;
		
}
void insert_at_position(struct node*head,int d,int pos);
void insert_at_position(struct node*head,int d,int pos)
{
	struct node*temp=malloc(sizeof(struct node*));
	temp->data=d;
	temp->next=NULL;
	struct node*ptr=head;
	pos--;
	while(pos!=1)
	{
		ptr=ptr->next;
		pos--;
	}
	temp->next=ptr->next;
	ptr->next=temp;
}
void delete_at_beginning(struct node**head);
void delete_at_beginning(struct node**head)
{
	struct node*ptr=*head;
	(*head)=(*head)->next;
	free(ptr);
	
}
void delete_at_end(struct node*head);
void delete_at_end(struct node*head){
	struct node*ptr=head;
	struct node*current=malloc(sizeof(struct node*));
	while(ptr->next!=NULL)
	{
		current=ptr;
		ptr=ptr->next;
	}
	current->next=NULL;
	free(ptr);
}
void delete_at_position(struct node*head,int pos);
void delete_at_position(struct node*head,int pos)
{
	struct node*ptr=head;
	struct node*temp=malloc(sizeof(struct node*));
	while(pos!=1)
	{
		temp=ptr;
		ptr=ptr->next;
		pos--;
	}
	temp->next=ptr->next;
	free(ptr);
}
int search(struct node*head,int key);
int search(struct node*head,int key)
{
	int count=0;
	struct node*ptr=head;
	while(ptr!=NULL)
	{
		count++;
		if(key==ptr->data){
		printf("ELEMENT FOUND AT %d",count);}
		ptr=ptr->next;
	}
}



int main(){
	struct node*head=NULL;
	head=(struct node*)malloc(sizeof(struct node*));
	create_node(&head,30);
	display(head);
	printf("\n");
	count_of_nodes(head);
	printf("\n");
	insert_at_beginning(&head,10);
	display(head);
	printf("\n");
	insert_at_end(head,40);
	display(head);
	printf("\n");
	insert_at_position(head,20,2);
	display(head);
        printf("\n");
	delete_at_beginning(&head);
	display(head);
	printf("\n");
	delete_at_end(head);
	display(head);
	printf("\n");
	insert_at_end(head,50);
	display(head);
	printf("\n");
	insert_at_beginning(&head,100);
	display(head);
	printf("\n");
	delete_at_position(head,3);
	display(head);
	printf("\n");
	search(head,50);
}
