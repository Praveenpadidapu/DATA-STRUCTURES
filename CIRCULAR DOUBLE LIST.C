#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
	struct node *prev;
};
void display(struct node *);
void display(struct node *tail)
{
	struct node *ptr;
	ptr=tail->next;
	do
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}while(ptr!=tail->next);
	printf("\n");
}
struct node * create_node(int );
struct node * create_node(int d)
{
	struct node *temp=malloc(sizeof(struct node *));
	temp->data=d;
	temp->next=temp;
	temp->prev=temp;
	return temp;
}
void insert_at_beginning(struct node *,int );
void insert_at_beginning(struct node *tail,int d)
{
	if(tail==NULL)
	{
		printf("List is empty\n");
		return;
	}
	struct node *temp=create_node(d);
	struct node *ptr=tail->next;
	temp->prev=tail;
	tail->next=temp;
	ptr->prev=temp;
	temp->next=ptr;
}
void insert_at_end(struct node **,int d);
void insert_at_end(struct node **tail,int d)
{
	if((*tail)==NULL)
	{
		printf("List is empty\n");
		return;
	}
	struct node *temp=create_node(d);
	temp->prev=(*tail);
	temp->next=(*tail)->next;
	(*tail)->next=temp;
	(*tail)=temp;
}
void insert_at_position(struct node *,int , int  );
void insert_at_position(struct node *tail,int pos, int d  )
{
struct node *temp=create_node(d);
struct node *ptr=tail->next;
pos--;
while(pos>1)
{
	ptr=ptr->next;
	pos--;
	}	
	temp->prev=ptr;
	temp->next=ptr->next;
	ptr->next=temp;
	temp->next->prev=temp;
}
void delete_at_beginning(struct node **);
void delete_at_beginning(struct node **tail)
{
	struct node *ptr=(*tail)->next;
	(*tail)->next=ptr->next;
	ptr->next->prev=(*tail);
	free(ptr);
	
}
void delete_at_end(struct node *);
void delete_at_end(struct node *tail)
{
struct node*ptr=tail->next;
while(ptr->next!=tail)
{
	ptr=ptr->next;
}
ptr->next=tail->next;
tail->next->prev=ptr;
free(tail);
tail=ptr;

}
void delete_at_position(struct node *,int );
void delete_at_position(struct node *tail,int pos)
{
struct node*ptr=tail->next;
while(pos>2)
{
	ptr=ptr->next;
	pos--;
}
struct node *ptr1=ptr->next;
ptr->next=ptr1->next;
ptr1->next->prev=ptr;
free(ptr1);

}

int main() 
{
	struct node *tail=malloc(sizeof(struct node *));
	tail->data=10;
	tail->next=tail;
	tail->prev=tail;
	display(tail);
	insert_at_beginning(tail,20);
	insert_at_beginning(tail,30);
	display(tail);
	insert_at_end(&tail,50);
	display(tail);
	insert_at_position(tail,2,60);
	display(tail);
	delete_at_beginning(&tail);
	display(tail);
	delete_at_end(tail);
	display(tail);
	delete_at_position(tail,2);
	display(tail);	
}
