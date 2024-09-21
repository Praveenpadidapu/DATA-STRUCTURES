#include<stdio.h>
#include<stdlib.h>
#define max 100
int Q[max];
int front=-1;
int rear=-1;
int isEmpty();
int isEmpty()
{
	if(front==-1 && rear==-1 || front>rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isFull();
int isFull()
{
	if(rear==max-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void display();
void display()
{
	int i;
	printf("Queue is ");
	if(isEmpty())
	{
		printf("empty\n");
	}
	for(i=front;i<=rear;i++)
	{
		printf("%d ",Q[i]);
	}
	printf("\n");
}
void enqueue(int );
void enqueue(int d)
{
	if(isFull())
	{
		printf("Queue is full\n");
	}
	if(front==-1 && rear==-1)
	{
		front++;
	}
	rear++;
	Q[rear]=d;
}
int dequeue();
int  dequeue()
{
	if(isEmpty())
	{
		printf("Queue is empty\n");
		exit(1);
	}
	int d=Q[front];
	front++;
	return d; 
}
int main()
{
	int x,d;
	while(1)
	{
		printf(" 1:Enqueue \n 2:Dequeue \n 3:display \n 4:To exit the programm \n");
		scanf("%d",&x);
		switch(x) 
		{
			case 1:
					printf("Enter a number to enqueue:");
					scanf("%d",&d);
					enqueue(d);
					break;
			case 2:dequeue();
					break;
			case 3:display();
					break;
			case 4:exit(1);		
		}
	}
	return 0;
}
