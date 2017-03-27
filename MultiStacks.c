#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int *arr;
	int *top;
	int *boundary;
	int size;
}stack;

//Multiple stacks in an array.

void createStack(stack *s, int n, int t)
{
	s->size=n;
	s->arr=calloc(n,sizeof(int));
	s->top=malloc(t*sizeof(int));
	s->boundary=malloc(t*sizeof(int));
	int i;
	for(i=0;i<t;i++)
	{
		s->top[i]=(n/t)*(i)-1;
		s->boundary[i]=(n/t)*(i+1)-1;
	}
}

void push(stack *s, int item, int i)
{
	i--;
	if(s->top[i]>=s->boundary[i]) 
	{
		printf("\nStack overflow.");
		return;
	}
	else
	{
		s->top[i]++;
		s->arr[s->top[i]]=item;
	}
}

int pop(stack *s, int i)
{
	i--;
	if(i==0)
	{
		if(s->top[i]==-1)
		{
			printf("\nStack Underflow.");
			return -1;
		}
	}
	
	if(s->top[i]<=s->boundary[i-1])
	{
		printf("\nStack Underflow.");
		return -1;
	}
	
	int item=s->arr[s->top[i]];
	s->top[i]--;
	return item;
}

int display(stack *s, int k)
{
	int n=k-1; int i=0;
	printf("\nStack %d is as follows:\n",k);
	if(n==0)
	{
		for(i=0;i<=s->top[n];i++)
		{
			printf("\t%d",s->arr[i]);
		}
	}
	else
	{
		for(i=s->boundary[n-1]+1;i<=s->top[n];i++)
		{
			printf("\t%d",s->arr[i]);
		}
	}
}

int main()
{
	stack s;
	printf("\nEnter the array size, and number of stacks to be implemented:");
	int n,t;
	scanf("%d%d",&n,&t);
	createStack(&s,n,t);
	printf("\n1. Push to Stack\n2. Pop from stack \n3. Display i'th stack\n4. Exit");
	int ch;
	do{
		printf("\nEnter Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the element to be pushed to stack and the stack number:");
				int item, x;
				scanf("%d%d",&item,&x);
				push(&s,item,x);
				break;
			
			case 2: printf("\nPop from which stack?");
				int y;
				scanf("%d",&y);
				int popped=pop(&s,y);
				if(popped!=-1)
				{
					printf("\nThe popped element is: %d",popped);
				}
				break;
				
			case 3: printf("\nDisplay which stack?");
				int z;
				scanf("%d",&z);
				display(&s,z);
				break;	
		}
	}while(ch!=4);
	return 0;
}
