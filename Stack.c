#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct
{
    int arr[20];
    int top;
}stack;

void stackInit(stack*s)
{
    s->top=-1;
}

void push(stack*s, int item)
{
    if(s->top==MAX-1)
    {
        printf("\n \n Stack Overflow.");
    }
    else
    {
        s->top++;
        s->arr[s->top]=item;
    }
}

int pop(stack*s)
{
    if(s->top==-1)
    {
         printf("\n \n Stack Underflow.");
         return -1;
    }
    else
    {
        int item=s->arr[s->top];
        s->top--;
        return item;
    }
}


void display(stack *s)
{
    if(s->top==-1) printf("\n \n Stack empty.");
    else
    {
        printf("\n \n Display stack elements: \n");
        int i;
        for(i=s->top;i>-1;i--)
        {
            printf("\t %d",s->arr[i]);
        }
    }
}

void main()
{
    stack s;
    stackInit(&s);
    int ch;
    do
    {
        printf("\n1.Push\n2.Pop\n3.Display\nPress 4 to exit.");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                {
                    printf("\n \n Enter the integer to be pushed:");
                    int item;
                    scanf("%d",&item);
                    push(&s,item);
                    break;
                }

            case 2:
                {
                    int r=pop(&s);
                    if(r!=-1)
                    printf("\n \n The popped element is: %d",r);
                    break;
                }

            case 3:
                {
                    display(&s);
                    break;
                }
        }

    }while(ch!=4);
}
