#include <stdio.h>
#include <stdlib.h>

//Stack using LL

typedef struct node_1
{
	int data;
	struct node_1 *link;
}node;

void push(node **head, int item)
{
	node *temp=malloc(sizeof(node));
	temp->link=NULL;
	temp->data=item;
	if(*head==NULL) *head=temp;
	else
	{
		temp->link=(*head);
		*head=temp;
	}	
}

int pop(node **head)
{
	if(*head==NULL)
	{
		printf("\nStack Underflow.");
		return -1;
	}
	
	int item=(*head)->data;
	node *temp=*head;
	(*head)=(*head)->link;
	free(temp);
	return item;
}

void display(node *head)
{
	node *temp=head;
	printf("\nStack:");
	while(temp!=NULL)
	{
		printf("\t%d",temp->data);
		temp=temp->link;
	}
}

void main()
{
    node *head=NULL;
    printf("\n1.Push\n2.Pop\n3.Display\nPress 4 to exit.");
    int ch;
    do
    {
        printf("\nEnter Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                {
                    printf("\n \n Enter the integer to be pushed:");
                    int item;
                    scanf("%d",&item);
                    push(&head,item);
                    break;
                }

            case 2:
                {
                    int r=pop(&head);
                    if(r!=-1) printf("\n \n The popped element is: %d",r);
                    break;
                }

            case 3:
                {
                    display(head);
                    break;
                }
        }

    }while(ch!=4);
}
