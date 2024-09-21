#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
	struct node *prev;
};
int count_of_nodes(struct node *);
int count_of_nodes(struct node *head)
{
	int count=0;
	struct node *temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
	return count;
}
struct node * create_node(int );
struct node * create_node(int d)
{
	struct node *temp=malloc(sizeof(struct node *));
	temp->data=d;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}
void display(struct node *);
void display(struct node *head)
{
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	struct node *ptr=head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}
void insert_at_end(struct node *,int );
void insert_at_end(struct node *head,int d)
{
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	struct node *temp=create_node(d);
	struct node *ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	temp->prev=ptr;
	ptr->next=temp;
}
void insert_at_beginning(struct node **,int );
void insert_at_beginning(struct node **head,int d)
{
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	struct node *temp=create_node(d);
	(*head)->prev=temp;
	temp->next=(*head);
	(*head)=temp;
}
void insert_at_position(struct node *,int ,int ,int);
void insert_at_position(struct node *head,int pos,int d,int size)
{
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(pos<1)
	{
		printf("Invaild position\n");
		return;
	}
	if(pos==1)
	{
		insert_at_beginning(&head,d);
		return;
	}
	if(pos==size+1)
	{
		insert_at_end(head,d);
		return;
	}
	struct node *temp=create_node(d);
	struct node *ptr=head;
	pos--;
	while(pos!=1)
	{
		ptr=ptr->next;
		pos--;
	}
	struct node *ptr1=ptr->next;
	ptr->next=temp;
	temp->prev=ptr;
	temp->next=ptr1;
	ptr1->prev=temp;
}
void delete_at_end(struct node *);
void delete_at_end(struct node *head)
{
	struct node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	struct node *ptr=temp->prev;
	ptr->next=NULL;
	temp->prev=NULL;
	free(temp);
}
void delete_at_beginning(struct node **);
void delete_at_beginning(struct node **head)
{
	struct node *temp=(*head);
	(*head)=(*head)->next;
	(*head)->prev=NULL;
	temp->next=NULL;
	free(temp);
}
void delete_at_position(struct node *,int ,int );
void delete_at_position(struct node *head,int pos,int size)
{
		if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(pos<1)
	{
		printf("Invaild position\n");
		return;
	}
	if(pos==1)
	{
		delete_at_beginning(&head);
		return;
	}
	if(pos==size+1)
	{
		delete_at_end(head);
		return;
	}
	struct node *ptr=head;
	pos--;
	while(pos!=1)
	{
		ptr=ptr->next;
		pos--;
	}
	struct node *temp=ptr->next;
	struct node *ptr1=temp->next;
	ptr->next=ptr1;
	ptr1->prev=temp->prev;
	free(temp);
}
void search(struct node *,int );
void search (struct node *head,int key)
{
	
	struct node *temp=head;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		if(temp->data==key)
		{
		 printf("Data is found at node %d\n",count);
		 return;
	    }
	    temp=temp->next;
	}
	printf("Data is not found\n");
}
int main ()
{
	struct node *head=malloc(sizeof(struct node *));
	head->data=10;
	head->prev=NULL;
	head->next=NULL;
	insert_at_end(head,30);
	insert_at_end(head,40);
	display(head);
	printf("After inserting at end\n");
	insert_at_end(head,40);
	display(head);
	printf("After inserting at beginning\n");
	insert_at_beginning(&head,50);
	display(head);
	printf("After inserting at position\n");
	insert_at_position(head,2,69,count_of_nodes(head));
	display(head);
        printf("After deleting at end\n");
	delete_at_end(head);
	display(head);
	printf("After deleting at position\n");
	delete_at_position(head,2,count_of_nodes(head));
	display(head);
	printf("After inserting at beginning\n");
	delete_at_beginning(&head);
	display(head);
	int key;
	printf("Enter an element to search in double linked list:");
	scanf("%d",&key);
	search(head,key);
	return 0;
}
