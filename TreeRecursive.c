#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 35

typedef struct Tree_
{
	char *str;
	struct Tree_ *left, *right;
}Tree;

void createTree(Tree **root)
{
	*root=NULL;
}

Tree* getNode(char a[])
{
	Tree* temp=malloc(sizeof(Tree));
	temp->left=NULL;
	temp->right=NULL;
	temp->str=malloc(MAX*sizeof(char));
	strcpy(temp->str,a);
	return temp;
}

Tree* insertData(Tree *root, char a[])
{
	if(root==NULL)
	{
		root=getNode(a);
		return root;
	}
	else
	{
		printf("\nCurrent node occupied, insert into left child or right child?\nPress 1 for left, 2 for right:");
		int ch;
		scanf("%d",&ch);
		if(ch==1)
		{
			root->left=insertData(root->left,a);
		}
		else if(ch==2)
		{
			root->right=insertData(root->right,a);
		}
		else printf("\nWrong choice.");
	}
	return root;
}

void displayInorder(Tree *root)
{
	if(root)
	{
		displayInorder(root->left);
		printf("\t %s",root->str);
		displayInorder(root->right);
	}
}

int max(int a, int b)
{
	int max;
	max=a>b?a:b;
	return max;
}

int findheight(Tree *root)
{
	if(root==NULL) return -1;
	else return 1+max(findheight(root->left),findheight(root->right));
}

typedef struct
{
	Tree* arr[MAX];
	int top;
}treeStack;

void treeStackInit(treeStack *s)
{
	s->top=-1;
}

bool isfull(treeStack *s)
{
	if(s->top==MAX-1) return true;
	else return false;
}

bool isempty(treeStack *s)
{
	if(s->top==-1) return true;
	else return false;
}

void push(treeStack *s, Tree* item)
{
	if(isfull(s)) return;
	else
	{
		s->top++;
		s->arr[s->top]=item;
	}
}

Tree* pop(treeStack *s)
{
	if(isempty(s)) return NULL;
	else
	{
		return s->arr[(s->top)--];
	}
}

void countNodesNLeaves(Tree *root, int *nodes, int *leaves)
{
	treeStack s;
	treeStackInit(&s);
	*nodes=*leaves=0;
	if(root==NULL) return;
	while(1)
	{
		while(root)
		{
			push(&s,root);
			root=root->left;
		}
		root=pop(&s);
		if(!root) break;
		else
		(*nodes)++;
		if(root->left==NULL&&root->right==NULL) (*leaves)++;
		root=root->right;
	}
}

int main()
{
	Tree *root;
	createTree(&root);
	int leaves=0;
	int nodes=0;
	int height=0;
	printf("\n1.Insert a leaf.\n2.Display Inorder.\n3.Count leaves and nodes.\n4.Find height.\n5.Exit");
	int ch;
	do{
		printf("\nEnter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the string you want to insert:");
					char a[MAX];
					scanf("%s",a);
					root=insertData(root,a);
					break;
					
			case 2: printf("\nInorder Traversal:");
					displayInorder(root);
					break;
					
			case 3: countNodesNLeaves(root,&nodes,&leaves);
					printf("\nLeaves:%d\tNodes:%d",leaves,nodes);
					break;
			
			case 4: height=findheight(root);
					printf("\nHeight:%d",height);
					break;
		}
	}while(ch!=5);
	return 0;
}
