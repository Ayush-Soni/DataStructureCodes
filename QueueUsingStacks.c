#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 50

typedef struct stack_
{
	char **arr;
	int top,capacity;
}stack;

void createStack(stack *s)
{
	s->arr=malloc(2*sizeof(char*));
	s->top=-1;
	s->capacity=2;
}

bool isempty(stack *s)
{
	if(s->top==-1) return true;
	else return false;
}

void stackFull(stack *s)
{
	char **arrNew=malloc(2*s->capacity*sizeof(char*));
	int i=0;
	for(;i<=s->top;i++)
	{
		arrNew[i]=malloc(strlen(s->arr[i])*sizeof(char));
		strcpy(arrNew[i],s->arr[i]);
	}
	s->capacity*=2;
	s->arr=arrNew;
}

void push(stack *s, char a[])
{
	if(s->top>=s->capacity-1) stackFull(s);
	s->top++;
	s->arr[s->top]=malloc(30*sizeof(char));
	strcpy(s->arr[s->top],a);
}

char* pop(stack *s)
{
	if(s->top==-1) return NULL;
	else
	{
		return s->arr[(s->top)--];
	}
}

void displayStack(stack *s)
{
	int i=0;
	for(;i<=s->top;i++)
	{
		printf("\t%s",s->arr[i]);
	}
}

char* popQ(stack *s1, stack *s2)
{
	if(isempty(s2))
	{
		while(!isempty(s1))
		{
			push(s2,pop(s1));
		}
	}
	
	return pop(s2);
}

int main()
{
	stack s1,s2;
	createStack(&s1);
	createStack(&s2);
	printf("\n1.EnQ\n2.DeQ\n3.Display\n4.Exit");
	int ch;
	do{
		printf("\nEnter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the string you want to enQ:");
					char a[MAX];
					scanf("%s",a);
					push(&s1,a);
					break;

			case 2: printf("\nAttempting deQ..");
					char *str;
					str=popQ(&s1,&s2);
					if(str) printf("\nDeQ'd string :%s",str);
					else printf("\nQ empty.");
					break;

			case 3: printf("\nQueue is as follows:");
					displayStack(&s1);
					displayStack(&s2);
					break;
		}
	}while(ch!=4);
	return 0;
}
