//Binary tree, integers, recursive.
//count leaves, find height, count nodes

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 30

typedef struct Tree_
{
	int data;
	struct Tree_ *left, *right;
}Tree;

void treeInit(Tree **root)
{
	*root=NULL;
}

Tree* getNode(int d)
{
	Tree* temp=malloc(sizeof(Tree));
	temp->data=d;
	temp->left=temp->right=NULL;
	return temp;
}

Tree* insertTree(Tree *root, int data)
{
	if(root==NULL)
	{
		root=getNode(data);
	}
	else
	{
		printf("\nCurrent node is occupied...\n1| Left\n2| Right\nEnter choice:");
		int ch;
		scanf("%d",&ch);
		if(ch==1)
		{
			root->left=insertTree(root->left,data);
		}
		else if(ch==2)
		{
			root->right=insertTree(root->right,data);
		}
	}
	return root;	
}

void displayInorder(Tree *root)
{
	if(root)
	{
		displayInorder(root->left);
		printf("\t%d",root->data);
		displayInorder(root->right);
	}
}

int maxOfTwo(int a, int b)
{
	int c=a>b?a:b;
	return c;
}

int findHeight(Tree *root)
{
	if(root==NULL) return -1;
	else return (1+maxOfTwo(findHeight(root->left),findHeight(root->right)));
}

int findLeaves(Tree *root)
{
	if(root==NULL) return 0;
	if(root->left==NULL&&root->right==NULL) return 1;
	else return (findLeaves(root->left)+findLeaves(root->right));
}

int findNodes(Tree *root)
{
	if(root==NULL) return 0;
	else return (1+findNodes(root->left)+findNodes(root->right));
}

int main()
{
	Tree *root;
	treeInit(&root);
	printf("\n1| Insert a leaf\n2| Display Tree\n3| Count leaves\n4| Calculate height\n5| Count nodes\n6| Exit");
	int ch;
	do{
		printf("\nEnter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:{
					printf("\nEnter the number you want to insert:");
					int item;
					scanf("%d",&item);
					root=insertTree(root,item);
					break;
			}
			
			case 2:{
					displayInorder(root);
					break;
			}
			
			case 3:{
					printf("\nNumber of leaves is: %d",findLeaves(root));
					break;
			}
			
			case 4:{
					printf("\nHeight of the tree is: %d",findHeight(root));
					break;
			}
			
			case 5:{
					printf("\nNumber of nodes in the tree is: %d",findNodes(root));
					break;
			}
		}
	}while(ch!=6);
	return 0;
}
