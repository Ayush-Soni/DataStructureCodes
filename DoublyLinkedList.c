//Doubly linked list.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Dll_
{
	char *str;
	struct Dll_* left;
	struct Dll_* right;
}node;

void listInit(node **head)
{
	*head=NULL;
}

void insertList(node **head, char a[])
{
	node *temp=malloc(sizeof(node));
	temp->str=a;
	temp->left=temp->right=NULL;
	if(*head==NULL)
	{
		*head=temp;
		return;
	}
	else
	{
		node *t1=*head;
		while(t1->right!=NULL)
		{
			t1=t1->right;
		}
		t1->right=temp;
		temp->left=t1;
	}
}

void deleteList(node **head,char a[])
{
	node *t1=*head;
	while((strcmp(t1->str,a)!=0)&&t1!=NULL)
	{
		t1=t1->right;
	}
	if(t1==NULL) printf("\nNode not found");
	else
	{
		if(t1->left) t1->left->right=t1->right;
		else
		{
			*head=(*head)->right;
		}
		if(t1->right) t1->right->left=t1->left;
		free(t1);
		t1=NULL;
	}
	return;
}

void displayList(node *head)
{
	printf("\nDoubly linked list is as follows:");
	node *t1=head;
	while(t1!=NULL)
	{
		printf("\t%s",t1->str);
		t1=t1->right;
	}
	return;
}


int main()
{
	node* head;
	listInit(&head);
	printf("\n1.Insert into DLL.\n2.Display DLL.\n3.Delete from DLL\n4.Exit.");
	int choice;
	do{
		printf("\nEnter Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nEnter the string you want to insert:");
					char *a=malloc(50*sizeof(char));
					scanf("%s",a);
					insertList(&head,a);
					break;
			
			case 2: displayList(head);
					break;
					
			case 3:printf("\nEnter the string you want to delete from DLL:");
				 	char *a1=malloc(50*sizeof(char));
				 	scanf("%s",a1);
				 	deleteList(&head,a1);
					break;
		}
	}while(choice!=4);
	return 0;
}
