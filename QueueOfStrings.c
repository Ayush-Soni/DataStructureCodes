#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 40

//Dynamically allocates memory.

typedef struct
{
	char **strings;
	int front,rear,capacity;
}Q;

void createQ(Q *q)
{
	printf("\nEnter the size of Q:");
	int n;
	scanf("%d",&n);
	q->strings=(char**)malloc(n*sizeof(char*));
	q->front=0;
	q->rear=0;
	q->capacity=n;
}

void isfullQ(Q *q)
{
	if((q->rear+1)%q->capacity==q->front)
	{
		char **newStrings=(char**)malloc(2*q->capacity*sizeof(char*));
		int i=q->front;
		int j=0;
		for(;i!=q->rear;i=(i+1)%q->capacity)
		{
			newStrings[j]=(char*)malloc(strlen(q->strings[i])*sizeof(char));
			strcpy(newStrings[j],q->strings[i]);
			j++;
		}
		q->capacity*=2;
		q->front=0;
		q->rear=j;
		q->strings=newStrings;
	}
}

void insertQ(Q *q, char a[])
{
	isfullQ(q);
	if(q->strings[q->rear]==NULL) q->strings[q->rear]=malloc(MAX*sizeof(char));
	strcpy(q->strings[(q->rear)++],a);
}

char* delQ(Q *q)
{
	if(q->front==q->rear) return NULL;
	else
	{ 	
		return q->strings[--(q->rear)];
	}
}

void displayQ(Q *q)
{
	printf("\nQueue is as follows:");
	int i=q->front;
	for(;i!=q->rear;i=(i+1)%q->capacity)
	{
		printf("\t%s",q->strings[i]);
	}
}

int main()
{
	Q q;
	createQ(&q);
	printf("\n1.InsertQ\n2.DeleteQ\n3.DisplayQ\n4.Exit");
	int choice;
	do{
		printf("\nEnter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nEnter the string to be enQ'd:");
					char str[MAX];
					scanf("%s",str);
					insertQ(&q,str);
					break;
					
			case 2:printf("\nThe deQ'd string is:");
					char *string=delQ(&q);
					printf("\t%s",string);
					break;
			
			case 3:displayQ(&q);
					break;
		}
	}while(choice!=4);
	return 0;
}
