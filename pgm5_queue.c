#include<stdio.h>
#define max 5
int queue[max];
int front=-1;
int rear=-1;
void enqueue();
void dequeue();
void traversal();
int main()
{
	int choice;
	printf("1.enqueue\n2.dequeue\n3.traversal\n4.exit\n");
	do
	{
		printf("\nenter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				traversal();
				break;
			case 4:
				return(0);
			default:
				printf("wrong choice");
				break;
		}

	}
	while(choice!=4);
	return(0);
}
	
void enqueue()
{
	int element;
	printf("enter the element:");
	scanf("%d",&element);
	if(rear==max-1)
	{	
		printf("queue is full\n");
	}
	else
	{
		if(rear==-1)
		{
			front=rear=0;
			queue[rear]=element;
		}
		else
		{
			rear++;
			queue[rear]=element;
		}
	
	}
}		
void dequeue()
{
	int element;
	if(front==-1)
	{
		printf("queue is empty ");
	}
	else
	{
		if (front==rear)
		{	
			printf(" deleted item is %d",queue[front]);
			front=-1,rear=-1;
		}
		else
		{
			printf("deleted item is %d",queue[front]);	
			front++;
		}
	}
}
void traversal()
{
	int i;
	if(front==-1)
	{
		printf("queue is empty");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d",queue[i]);
		}
	}
}


