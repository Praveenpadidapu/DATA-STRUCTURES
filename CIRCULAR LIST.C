#include<stdio.h>
#include<stdlib.h>

	/*void create_node(struct node**tail,int d);
	void display(struct node*tail);
	void insert_at_beginning(struct node**tail,int d);
	void insert_at_end(struct node**tail,int d);
	void insert_at_position(struct node*tail,int pos,int d);
	void delete_at_end(struct node *tail);*/
struct node{
int data;
struct node*next;
};

void create_node(struct node **tail,int d)
{
struct node *temp=(struct node*)malloc(sizeof(struct node*));
temp->data=d;
temp->next=temp;
(*tail)=temp;
}

void display(struct node*tail)
{
struct node*ptr=tail->next;
do
{
printf("%d ",ptr->data);
ptr=ptr->next;
}
while(ptr!=tail->next);
}



void insert_at_beginning(struct node **tail,int d)
{
struct node *temp=(struct node*)malloc(sizeof(struct node*));
temp->data=d;
temp->next=NULL;
temp->next=(*tail)->next;
(*tail)->next=temp;

}

void insert_at_end(struct node **tail,int d)
{
struct node *temp=(struct node*)malloc(sizeof(struct node*));
temp->data=d;
temp->next=NULL;
temp->next=(*tail)->next;
(*tail)->next=temp;
(*tail)=temp;
}

void insert_at_position(struct node*tail,int pos,int d)
{
struct node*temp=malloc(sizeof(struct node*));
temp->data=d;
temp->next=NULL;
struct node*ptr=tail->next;
pos--;
while(pos>1)
{
ptr=ptr->next;
pos--;
}
temp->next=ptr->next;
ptr->next=temp;
}
void delete_at_beginning(struct node**tail)
{
struct node*ptr=(*tail)->next;
(*tail)->next=ptr->next;
free(ptr);
if(ptr==(*tail))
{
free(ptr);
(*tail)=NULL;
}
}

void delete_at_end(struct node*tail)
{
struct node*ptr=tail->next;
struct node*temp=malloc(sizeof(struct node*));
while(ptr->next!=tail){
ptr=ptr->next;
}
ptr->next=tail->next;
tail=NULL;
free(tail);
tail=ptr;
}
void delete_at_position(struct node*tail,int pos)
{
struct node*ptr=tail->next;
struct node*ptr1=malloc(sizeof(struct node*));
while(pos>2) 
{
ptr=ptr->next;
pos--;
}
ptr1=ptr->next;
ptr->next=ptr1->next;
free(ptr1);

}
int main()
{



struct node*tail=NULL;
tail=(struct node*)malloc(sizeof(struct node*));
create_node(&tail,10);
display(tail);
printf("\nINSERT AT BEGINNING\n");
insert_at_beginning(&tail,20);
display(tail);
printf("\nINSERT AT END\n");
insert_at_end(&tail,30);
display(tail);
printf("\nINSERT AT POSITION\n");
insert_at_position(tail,2,60);
display(tail);
printf("\nDELETE AT BEGINNING\n");
delete_at_beginning(&tail);
display(tail);
printf("\nDELETE AT END\n");
delete_at_end(tail);
display(tail);
printf("\nDELETE AT POSITION\n");
delete_at_position(tail,2);
display(tail);
}
