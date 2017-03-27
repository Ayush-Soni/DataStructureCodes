#include<stdio.h>
#include<stdlib.h>

typedef struct node_1
{
	int data; //which is process ID
	int time;
	struct node_1*link;
}node;

void createList(node **head)
{
	*head=NULL;
}

void insertList(node **head, int item, int t)
{
	node *temp=malloc(sizeof(node));
	temp->data=item;
	temp->time=t;
	if(*head==NULL)
	{
		*head=temp;
		temp->link=temp;
	}
	else
	{
		node *t1=*head;
		while(t1->link!=*head)
		{
			t1=t1->link;
		}
		t1->link=temp;
		temp->link=*head;
	}
}

void displayList(node **head)
{
	node *temp=*head;
	printf("\nProcess list:");
	printf("\n\tProcess ID\t\tEstimated Completion");
	do
	{
		printf("\n\t%d\t\t\t%d",temp->data,temp->time);
		temp=temp->link;
	}while(temp!=*head);
}

int deleteList(node **head, int item)
{
	node *temp, *prev;
	prev=NULL;
	temp=*head;
	do
	{
		if(temp->data==item) break;
		prev=temp;
		temp=temp->link;
	}while(temp!=*head);
	if(prev==NULL)
	{
		//node *t1=*head;
		prev=*head;
		do{
			prev=prev->link;
		}while(prev->link!=*head);
		(*head)=(*head)->link;
		prev->link=*head;
		//free(t1);
	}
	else
	{			//No need to take care of the error condition.
		prev->link=temp->link;
		free(temp);
	}
	displayList(head);
}

void timeSlicer(node **head, int ts)
{
	node *temp=*head;
	displayList(head);
	while((*head)->link!=*head)
	{
		temp->time=temp->time-ts;
		if(temp->time<=0)
		{
			node *t1=temp;
			temp=temp->link;
			deleteList(head,t1->data);
		}
		else temp=temp->link;
	}
	displayList(head);
}

int main()
{
	node *head;
	createList(&head);
	int ch;
	printf("\n1| Insert a process.\n2| Delete a process manually.\n3| Display the process list.\n4| Round Robin.\n5| Exit.");
	do{
		printf("\nEnter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the Process_ID and Process time:");
				int id,time;
				scanf("%d%d",&id,&time);
				insertList(&head,id,time);
				break;
				
			case 2: printf("\nEnter the Process_ID:");
				int i;
				scanf("%d",&i);
				deleteList(&head,i);
				break;
				
			case 3: displayList(&head);
				break;
				
			case 4: printf("\nEnter the time_slice:");
				int timeslice;
				scanf("%d",&timeslice);
				timeSlicer(&head,timeslice);
				break;
		}
	}while(ch!=5);	
}
