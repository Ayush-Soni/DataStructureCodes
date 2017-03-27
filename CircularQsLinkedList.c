#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 40
//Multiple circular Qs in a linked list. //Strings
typedef struct node_
{
	char *s;
	struct node_* link;
}node;

void insertList(node **front, node **rear, char a[])
{
	node *temp=malloc(sizeof(node));
	temp->s=malloc(MAX*sizeof(char));
	strcpy(temp->s,a);
	if(*front==NULL&&*rear==NULL)
	{
		*front=temp;
		*rear=temp;
		temp->link=*front;
	}
	else
	{
		(*rear)->link=temp;
		temp->link=*front;
		*rear=temp;
	}
}

char* deleteList(node **front, node **rear)
{
	if(*front==NULL&&*rear==NULL)
	{
		printf("\nAttempt Failed.");
		return NULL;
	}
	else
	{
		char *s=(*front)->s;
		node *temp=*front;
		(*front)=(*front)->link;
		(*rear)->link=*front;
		free(temp);
		return s;
	}
}

void displayList(node *front, node *rear)
{
	node *temp=front;
	do{
		printf("\t%s",temp->s);
		temp=temp->link;
	}while(temp!=front);
}

int main()
{
	printf("\nEnter the number of Queues to be implemented:");
	int noOfQs;
	scanf("%d",&noOfQs);
	node **front=(node**)calloc(noOfQs,sizeof(node*));
	node **rear=(node**)calloc(noOfQs,sizeof(node*));
	printf("\n1| Enqueue\n2| Dequeue\n3| Display queue\n4| Exit");
	int ch;
	do{
		printf("\nEnter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:{
					printf("\nEnter the string you want to insert:");
					char *s=calloc(MAX,sizeof(char));
					scanf("%s",s);
					printf("\nInsert into which queue? :");
					int n;
					scanf("%d",&n);
					if(n>noOfQs)
					{
						printf("\nInvalid Queue Number.");
						continue;
					}
					insertList(&front[n-1],&rear[n-1],s);
					break;
			}
			
			case 2:{
					printf("\nDelete from which queue? :");
					int n;
					scanf("%d",&n);
					if(n>noOfQs)
					{
						printf("\nInvalid Queue Number.");
						continue;
					}
					char *s=deleteList(&front[n-1],&rear[n-1]);
					printf("\nThe deQ'd string is: %s",s);
					break;
			}
			
			case 3:{
					int i=0;
					for(i=0;i<noOfQs;i++)
					{
						printf("\nQueue %d:",i+1);
						displayList(front[i],rear[i]);
					}
					break;
			}
		}
	}while(ch!=4);
	return 0;
}
