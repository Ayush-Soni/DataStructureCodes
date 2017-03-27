#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 30

//Merge, Union, Intersection.

typedef struct node_
{
	char *str;
	struct node_* link;
}node;

void createList(node **head)
{
	*head=NULL;
}

void insertList(node **head, char a[])
{
	node *temp=malloc(sizeof(node));
	if(*head==NULL)
	{
		*head=temp;
	}
	else if((*head)->link!=*head)
	{
		node *t1=*head;
		while(t1->link!=*head)
		{
			t1=t1->link;
		}
		t1->link=temp;
	}
	else //head->link is head
	{
		(*head)->link=temp;
	}
	temp->link=*head;
	temp->str=malloc(MAX*sizeof(char));
	strcpy(temp->str,a);
}

char* deleteList(node **head)
{
	if(*head==NULL) return NULL;
	else
	{
		node *t1=*head;
		node *prev=NULL;
		while(t1->link!=*head)
		{
			prev=t1;
			t1=t1->link;
		}
		if(prev==NULL)
		{
			char *s=t1->str;
			free(t1);
			*head=NULL;
			return s;
		}
		else
		{
			prev->link=*head;
			char *s=t1->str;
			free(t1);
			return s;
		}
	}
}

void displayList(node **head)
{
	node *t1=*head;
	if(t1==NULL) return;
	//printf("\nList is as follows:");
	do//while(t1->link!=*head)
	{
		printf("%s\t",t1->str);
		t1=t1->link;
	}while(t1!=*head);
}

bool listContains(node **head, char a[])
{
	node *t1=*head;
	do
	{
		if(strcmp(t1->str,a)==0) return true;
	}while(t1!=*head);	
	return false;
}

void mergeLists(node **h1, node **h2, node **h3)
{
	node *t1=*h1;
	node *t2=*h2;
	do//while(t1->link!=*h1&&t2->link!=*h2)
	{
		int val=strcmp(t1->str,t2->str);
		if(val<0)
		{
			insertList(h3,t1->str);
			t1=t1->link;
		}
		else if(val==0)
		{
			insertList(h3,t1->str);
			insertList(h3,t2->str); //For union just insert one of them and move both pointers.
			t1=t1->link;
			t2=t2->link;
		}
		else
		{
			insertList(h3,t2->str);
			t2=t2->link;
		}
		
	}while(t1!=*h1&&t2!=*h2);
	
	if(t1==*h1&&t2!=*h2)
	{
		do//while(t2->link!=h2)
		{
			insertList(h3,t2->str);
			t2=t2->link;
		}while(t2!=*h2);
	}
	
	if(t2==*h2&&t1!=*h1)
	{
		do//while(t1->link!=h1)
		{
			insertList(h3,t1->str);
			t1=t1->link;
		}while(t1!=*h1);
	}
	displayList(h3);
}

void intersectionList(node **h1, node **h2, node **h4)
{
	node *t1=*h1;
	do//while(t1->link!=*h1)
	{
		if(listContains(h2,t1->str))
		{
			insertList(h4,t1->str);
		}
		t1=t1->link;
	}while(t1!=*h1);
	displayList(h4);
}

int main()
{
	node *h1,*h2,*h3,*h4;
	createList(&h1);
	createList(&h2);
	createList(&h3);
	createList(&h4);
	printf("\n1.Enlist.\n2.Delete from list.\n3.Merge two lists.\n4.Intersection of two lists.\n5.Display lists.\n6.Exit.");
	int choice;
	do{
		printf("\nEnter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nEnter the string to be inserted:");
					char *ar=malloc(MAX*sizeof(char));
					scanf("%s",ar);
					printf("\nInsert into which list? Press 1 for A, 2 for B:");
					int ch;
					scanf("%d",&ch);
					if(ch==1) insertList(&h1,ar);
					else if(ch==2) insertList(&h2,ar);
					else printf("\nWrong choice.");
					break;
			
			case 2: printf("\nDelete from which list? Press 1 for A, 2 for B:");
					int ch1;
					char *s=NULL;
					scanf("%d",&ch1);
					if(ch1==1) s=deleteList(&h1);
					else if(ch==2) s=deleteList(&h2);
					else printf("\nWrong choice.");
					if(s==NULL) printf("\nFailed to delete.");
					else printf("\t%s",s);
					break;
					
			case 3: mergeLists(&h1,&h2,&h3);
					break;
					
			case 4: intersectionList(&h1,&h2,&h4);
					break;
					
			case 5: printf("\nList A:"); 
					displayList(&h1);
					printf("\nList B:");
					displayList(&h2);
					printf("\nMerged A and B:");
					displayList(&h3);
					printf("\nIntersection of A and B:");
					displayList(&h4);
					break;
		}
	}while(choice!=6);
	return 0;
}
