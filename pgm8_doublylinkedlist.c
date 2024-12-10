#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *Llink;
	struct Node *Rlink;
};
struct Node *header = NULL;
struct Node *Create_Node(int data)
{
	struct Node *newnode;
	newnode =(struct Node*) malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->Llink = NULL;
	newnode->Rlink = NULL;
	return newnode;
}
void insert_at_front(int data)
{
	struct Node *newnode;
	if(header==NULL)
	{
		newnode=Create_Node(data);
		header=newnode;
	}
	else
	{
		newnode=Create_Node(data);
		newnode->Rlink=header;
		header->Llink=newnode;
		header=newnode;
	}
}
void insert_at_end(int data)
{
	struct Node *newnode;
	struct Node *ptr;
	newnode=Create_Node(data);
	while(ptr->Rlink!=NULL)
	{
		ptr=ptr->Rlink;
	}
	if(newnode==NULL)
	{
		printf("Not Enough Memory");
	}
	else
	{
		ptr->Rlink=newnode;
		header->Llink=ptr;
	}
}
void delete_at_front()
{
	struct Node *ptr;
	ptr=header;
	header=ptr->Rlink;
	free(ptr);
}
void delete_at_end()
{
	struct Node *ptr;
	struct Node *ptr1;
	ptr=header;
	while(ptr->Rlink!=NULL)
	{
		ptr1=ptr;
		ptr=ptr->Rlink;
	}
	ptr1->Rlink=NULL;
	free(ptr);
}	
void insert_at_any(int key, int data)
{
    struct Node *newnode, *ptr;
    newnode = Create_Node(data);

    if (key == 1)
    {
        insert_at_front(data);
        return;
    }

    ptr = header;
    for (int i = 1; i < position - 1 && ptr != NULL; i++)
    {
        ptr = ptr->Rlink;
    }

    if (ptr == NULL)
    {

        printf("Position out of bounds\n");
        free(newnode);
    }
    else
    {
        newnode->Rlink = ptr->Rlink;
        newnode->Llink = ptr;
        if (ptr->Rlink != NULL)
        {
            ptr->Rlink->Llink = newnode;
        }
        ptr->Rlink = newnode;
        printf("Inserted %d at position %d\n", data, position);
    }
}
void delete_at_any(int position)
{
    struct Node *ptr = header;

    if (header == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (position == 1)
    {
        delete_at_front();
        return;
    }

    for (int i = 1; i < position && ptr != NULL; i++)
    {
        ptr = ptr->Rlink;
    }

    if (ptr == NULL)
    {
        printf("Position out of bounds\n");
    }
    else
    {
        if (ptr->Rlink != NULL)
        {
            ptr->Rlink->Llink = ptr->Llink;
        }
        if (ptr->Llink != NULL)
        {
            ptr->Llink->Rlink = ptr->Rlink;
        }
        free(ptr);
    }
}

int search(int value)
{
    struct Node *ptr = header;
    int position = 1;
    int found = 0;

    while (ptr != NULL)
    {
        if (ptr->data == value)
        {
            printf("Element %d found at position %d\n", value, position);
            found = 1;
        }
        ptr = ptr->Rlink;
        position++;
    }

    if (!found)
    {
        printf("Element %d not found in the list.\n", value);
    }

    return found;
}

void traversal()
{
	struct Node*ptr;
	ptr=header;
	while(ptr!=NULL)
	{
		printf("%d",ptr->data);
		ptr=ptr->Rlink;
	}
}
int main()
{
	
	int data,position,choice,value;
	printf("1.insert at front\n");
	printf("2.insert at end\n");
	printf("3.insert at any\n");
	printf("4.delete at front\n");
	printf("5delete at end\n");
	printf("6delete at any\n");
	printf("7.search\n");
`	printf("8.traversal\n");
	printf("9.exit\n");
	do
	{
		printf("\nenter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("enter the data:");
				scanf("%d",&data);
				insert_at_front( data);
				break;
			case 2:
				printf("enter the data:");
				scanf("%d",&data);
				insert_at_end(data);
				break;
			case 3:
				printf("enter the data:");
				scanf("%d",&data);
				printf("enter the position:");
				scanf("%d",&position);
				insert_at_any(data,position);
				break;
			case 4:
				delete_at_front;
				break;
			case 5:
				delete_at_end;
				break;
			case 6:
				printf("enter the data:");
				scanf("%d",&data);
				printf("enter the position:");
				scanf("%d",&position);
				delete_at_any(position);
				break;
			case 7:
				printf("enter the data:");
				scanf("%d",&data);
				search(value);
				break;
			case 8:
				printf("enter the data:");
				scanf("%d",&data);
				traversal();
				break;
			case 9:
				return(0);
		}

	}
	while(choice!=9);
	return(0);
}

