#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*next;
}*top=NULL;
void push(int d);
void push(int d)
{
struct node*temp=malloc(sizeof(struct node*));
temp->data=d;
temp->next=NULL;
temp->next=top;
top=temp;
}
int display();
int display()
{
struct node*ptr=top;
while(top!=NULL)
{
printf("%d\n",top->data);
top=top->next;
}
}
int pop();
int pop()
{
int d;
struct node*temp=top;
d=top->data;
top=top->next;
free(temp);
temp=NULL;
return d;
}
int main()
{
push(60);
push(40);
push(80);
pop();
display();
}
