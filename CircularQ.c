#include<stdlib.h>
#include<stdio.h>
#define MAX 5

typedef struct
{
    int arr[MAX];
    int front,rear;
}Q;

void Qinit(Q *q)
{
    q->front=0;
    q->rear=0;
}

void enQ(Q *q, int item)
{
    if((q->rear+1)%MAX==q->front)
    {
        printf("\n \n Queue is full.");
    }
    else
    {
        q->arr[q->rear]=item;
        q->rear=(q->rear+1)%MAX;   
    }
}

int DeQ(Q *q)
{
    if(q->front==q->rear)
    {
        printf("\n \n Queue is empty.");
    }
    else
    {
        q->front=(q->front+1)%MAX;
        int item=q->arr[q->front];
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
        while(i!=q->rear)
        {
            printf("\t %d",q->arr[i]);
            i=(q->front+1)%MAX;
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
