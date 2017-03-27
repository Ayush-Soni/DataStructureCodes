#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 30

//Tree of strings. (Normal binary)
//Inorder iterative, PreOrder iterative, Postorder iterative.

typedef struct Tree_
{
	char *str;
	struct Tree_ *left;
	struct Tree_ *right;
}Tree;

typedef struct
{
	Tree* arr[MAX];
	int top;
}TreeStack;

void treeStackInit(TreeStack *s)
{
	s->top=-1;
}

bool isFullStack(TreeStack *s)
{
	if(s->top==MAX-1) return true;
	else return false;
}

bool isEmptyStack(TreeStack *s)
{
	if(s->top==-1) return true;
	else return false;
}

void push(TreeStack *s, Tree* root)
{
	if(isFullStack(s))
	{
		printf("\nStack Overflow");
		return;
	}
	else
	{
		s->top++;
		s->arr[s->top]=root;
	}
}

Tree* pop(TreeStack *s)
{
	if(isEmptyStack(s))
	{
		//printf("\nStack Underflow.");
		return NULL;
	}
	else
	{
		return s->arr[s->top--];
	}
}

Tree* treeInit(Tree *root)
{
	root=NULL;
	return root;
}

Tree* getNode(char a[])
{
	Tree* temp=malloc(sizeof(Tree));
	temp->str=a;
	temp->left=temp->right=NULL;
	return temp;
}

Tree* insertNode(Tree *root, char a[])  //Recursive
{
	if(root==NULL)
	{
		return getNode(a);
	}
	else
	{
		printf("\nCurrent node occupied, insert in which child? Press 1 for left, 2 for right.");
		int ch;
		scanf("%d",&ch);
		if(ch==1)
		{
			root->left=insertNode(root->left,a);
		}
		else if(ch==2)
		{
			root->right=insertNode(root->right,a);
		}
		else printf("\nWrong choice, returning to menu.");
		return root;
	}

}

void displayInorder(Tree *root)
{
	if(root)
	{
		displayInorder(root->left);
		printf("\t%s",root->str);
		displayInorder(root->right);
	}
}

void displayInorderIterative(Tree *root)
{
	TreeStack s;
	treeStackInit(&s);
	printf("\nInorder traversal:");
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
		{
			printf("\t%s",root->str);
			root=root->right;
		}
	}
}

void postOrderIterativeTwo(Tree* root)
{
	TreeStack s1;
	treeStackInit(&s1);
	TreeStack s2;
	treeStackInit(&s2);
	push(&s1,root);
	Tree *temp;
	while(!isEmptyStack(&s1))
	{
		temp=pop(&s1);
		push(&s2,temp);
		if(temp->left) push(&s1,temp->left);
		if(temp->right) push(&s1,temp->right);
	}
	
	printf("\nPost order traversal:");
	
	while(!isEmptyStack(&s2))
	{
		temp=pop(&s2);
		printf("\t%s",temp->str);
	}
}

Tree* peek(TreeStack *s)
{
	if(s->top==-1) return NULL;
	else return s->arr[s->top];
}

void postOrderIterativeOne(Tree* root)
{
	TreeStack s;
	treeStackInit(&s);
	if(root==NULL) return;
	printf("\nPost order traversal:");
	do
	{
		while(root)
		{
			if(root->right) push(&s,root->right);
			push(&s,root);
			root=root->left;
		}
		root=pop(&s);
		if(root->right&&(root->right==peek(&s)))
		{
			pop(&s);
			push(&s,root);
			root=root->right; //Remember this.	
		}
		else
		{
			printf("\t%s",root->str);
			root=NULL;
		}
	}while(!isEmptyStack(&s));
}

//Cloning a tree

Tree* cloneTree(Tree* root)
{
	if(root)
	{
		Tree *temp=malloc(sizeof(Tree));
		temp->str=malloc(50*sizeof(char));  //Cant send null pointer to string copy function. SIGSEGV.
		if(root->right) temp->right=cloneTree(root->right);
		if(root->left) temp->left=cloneTree(root->left);
		if(temp) strcpy(temp->str,root->str);
		return temp;
	}
}

int main()
{
	Tree* root;
	Tree* rootCloned;
	rootCloned=treeInit(rootCloned);
	root=treeInit(root);
	printf("\n1.Insert into Tree.\n2.Display Inorder iterative.\n3.Display Inorder recursive.\n4.Display Postorder iterative.(2 Stacks)\n5.Display Postorder iterative.(1 Stack)\n6.Clone Tree.\n7.Exit.");
	int choice;
	do{
		printf("\nEnter Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nEnter the string you want to insert:");
					char *a=malloc(50*sizeof(char));
					scanf("%s",a);
					root=insertNode(root,a);
					break;
			
			case 2: displayInorderIterative(root);
					break;
					
			case 3:printf("\nInorder traversal:");
				 	displayInorder(root);
					break;
			
			case 4: postOrderIterativeTwo(root);
					break;
					
			case 5: postOrderIterativeOne(root);
					break;
			
			case 6: printf("\nOriginal Tree:");
					displayInorder(root);
					printf("\nCloned Tree:");
					rootCloned=cloneTree(root);
					displayInorder(rootCloned);
					break;
		}
	}while(choice!=7);
	return 0;
}
