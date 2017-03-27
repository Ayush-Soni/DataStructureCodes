#include<stdlib.h>
#include<stdio.h>
#define MAX 20

typedef struct
{
    int arr[MAX];
    int front,rear;
}Q;

void Qinit(Q *q)
{
    q->front=-1;
    q->rear=-1;
}

void enQ(Q *q, int item)
{
    if(q->rear==MAX-1)
    {
        printf("\n \n Queue is full.");
    }
    else
    {
        q->rear+=1;
        q->arr[q->rear]=item;
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
        q->front+=1;
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
        int i=q->rear;
        while(i>q->front)
        {
            printf("\t %d",q->arr[i]);
            i--;
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
