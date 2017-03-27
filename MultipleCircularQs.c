//Multiple Qs in an array. Qs are circular, hold strings.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 40

typedef struct
{
	char **arr;
	int *front;
	int *rear;
	int size;
	int noOfQs;
	int sizeOfQ;
}Q;

void queueInit(Q *q)
{
	printf("\nEnter the size of the array:");
	int n,t,i;
	scanf("%d",&n);
	q->arr=(char**)calloc(n,sizeof(char*));
	q->size=n;
	printf("\nHow many circular Qs do you want to implement? :");
	scanf("%d",&t);
	q->front=(int*)malloc(t*sizeof(int));
	q->rear=(int*)malloc(t*sizeof(int));
	q->noOfQs=t;
	q->sizeOfQ=n/t;
	for(i=0;i<t;i++)
	{
		q->front[i]=(q->size/q->noOfQs)*i;
		q->rear[i]=(q->size/q->noOfQs)*i;
	}
}

void enQ(Q *q, char a[], int i)
{
	i=i-1;
	if(((q->rear[i]+1)%(q->sizeOfQ)+(i*(q->sizeOfQ)))==q->front[i])
	{
		printf("\nQueue %d is full.",i+1);
		return;
	}
	if(!q->arr[q->rear[i]]) q->arr[q->rear[i]]=malloc(MAX*(sizeof(char)));
	strcpy(q->arr[q->rear[i]],a);
	q->rear[i]++;
}

char* deQ(Q *q, int i)
{
	i=i-1;
	if(q->rear[i]==q->front[i])
	{
		printf("\nQueue %d is empty.",i+1);
		return NULL;
	}
	return q->arr[(q->front[i])++];
}

void displayQs(Q *q)
{
	int i,j;
	for(i=0;i<q->noOfQs;i++)
	{
		printf("\nQueue %d:",i+1);
		for(j=q->front[i];j<q->rear[i];j++)
		{
			printf("\t%s",q->arr[j]);
		}
	}
}

int main()
{
	Q q;
	queueInit(&q);
	printf("\n1| EnQueue\n2| DeQueue\n3| Display Queue\n4| Exit");
	int ch;
	do
	{
		printf("\nEnter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:{
					printf("\nEnter the string to be enqueued:");
					char *str=calloc(MAX,sizeof(char));
					scanf("%s",str);
					printf("\nInsert into which Q? :");
					int i;
					scanf("%d",&i);
					enQ(&q,str,i);
					break;
				}
			
			case 2:{
					printf("\nDelete from which Q? :");
					int i;
					scanf("%d",&i);
					printf("\nThe dequeued string is:");
					char *s=deQ(&q,i);
					printf("%s",s);
					break;					
				}
			
			case 3: displayQs(&q);
					break;
		}
	}while(ch!=4);	
}
