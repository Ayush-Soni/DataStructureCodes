#include<stdlib.h>
#include<stdio.h>
#define MAX 20

typedef struct
{
    int *arr;
    int front, rear, cap;
}Q;

void Qinit(Q *q)
{
    q->front=0;
    q->rear=0;
    q->cap=5;
    q->arr=(int*)calloc((int)q->cap,sizeof(int));
}

void Qfull(Q *q)
{
    int *narr;
    narr=(int*)calloc(2*q->cap,sizeof(int));
    int i=q->front;
    int k=0;
     for(;i!=q->rear;i=(i+1)%(q->cap))
        {
            narr[k]=q->arr[i];
            k++;
        }
    q->arr=narr;
    q->rear=q->cap;
    q->front=0;
    q->cap*=2;
}

void enQ(Q *q, int item)
{
    if((q->rear+1)%(q->cap)==q->front)
    {
        printf("Going to Q full.");
        Qfull(q);
    }
    else
    {
        q->arr[q->rear]=item;
        q->rear=(q->rear+1)%(q->cap);
    }
}

int DeQ(Q *q)
{
    if(q->front==q->rear)
    {
        printf("\n \n Queue is empty."); return -1;
    }
    else
    {
        int item=q->arr[q->front];
        q->front=(q->front+1)%(q->cap);
        return item;
    }
}

void displayQ(Q *q)
{
    if(q->front==q->rear) printf("\n \nQueue is empty.");
    else
    {
        printf("\n \n The Queue items are:");
        int i=q->front;
        for(i;i!=q->rear;i=(i+1)%(q->cap))
        {
            printf("\t %d",q->arr[i]);
        }

    }
}

void main()
{
    Q q;
    Qinit(&q);
    int ch;
    do
    {
        printf("\n 1. enQ\n 2. DeQ\n 3. Display Q\n Press 4 to exit.");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            {
                printf("\n \n Enter the element to be enQ'd:");
                int item;
                scanf("%d",&item);

                enQ(&q,item);
                                printf("Here");
                break;
            }

        case 2:
            {
                int item=DeQ(&q);
                if(item==-1) break;
                else printf("\n \n The DeQ'd element is: %d\n",item);
                break;
            }

        case 3:
            {
                displayQ(&q);
                break;
            }
        }
    }while(ch!=4);
}

