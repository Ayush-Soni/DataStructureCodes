#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int d;
    struct Q *link;
}Q;

void insertQ(Q **front, Q **rear, int data)
{
    Q *temp=(Q*)malloc(sizeof(Q));
    if(*front==NULL)
    {
        *front=temp;
    }
    temp->d=data;
    temp->link=NULL;
    if(*rear!=NULL)
    (*rear)->link=temp;
    *rear=temp;
}

int deleteQ(Q **front, Q **rear)
{
    if((*front==NULL)&&(*rear==NULL)) printf("\n\nQueue is empty.");
    else
    {
        int t=(*front)->d;
        *front=(*front)->link;
        return t;
    }
}

void displayIt(Q **front, Q **rear)
{
    Q *temp=*front;
    printf("\n\nQueue Contents:");
    while(temp!=NULL)
    {
        printf("%d\t",temp->d);
        temp=temp->link;
    }
}

void main()
{
    Q *front=NULL;
    Q *rear=NULL;
    int c;
    printf("\n \n1.EnQ\n2.DeQ\n3.Display\n4.Exit");
    do
    {
        printf("\n \nEnter Option:");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            {
                printf("\n \nEnter the element to be enQ'd:");
                int t;
                scanf("%d",&t);
                insertQ(&front,&rear,t);
                break;
            }
        case 2:
            {
                int t=deleteQ(&front,&rear);
                printf("\n \nThe deQ'd element is:%d",t);
                break;
            }
        case 3:
            {
                displayIt(&front,&rear);
                break;
            }
        }
    }while(c!=4);
}
