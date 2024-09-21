#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
struct node*front=NULL;
struct node*rear=NULL;
struct node* create_node(int d);
struct node* create_node(int d)
{
	struct node*temp=malloc(sizeof(struct node*));
	temp->data=d;
	temp->next=NULL;
	return temp;
}
int isempty();
int isempty()
{
	if(front==NULL)
	{
	return 1;
	}
	else
	{
	return 0;
	}
}
void enqueue(int d);
void enqueue(int d)
{
	struct node*temp=create_node(d);
	if(isempty())
	{
	front=temp;
	}
	if(rear!=NULL)
	{
	rear->next=temp;
	}
rear=temp;
}
void display();
void display()
{
struct node*ptr=front;
if(isempty())
{
printf("LIST IS EMPTY");
}
while(ptr!=NULL)
{
printf("%d",ptr->data);
ptr=ptr->next;
}

}
int dequeue();
int dequeue()
{
	struct node*ptr=front;
if(ptr!=rear)
{
front=front->next;
}
else
{
front=rear=NULL;
}
int d=ptr->data;
free(ptr);
return d;
}

int main()
{
enqueue(19);
enqueue(10);
dequeue();
display();
}
