#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 40

typedef struct stack_
{
	int arr[MAX];
	int top;
}stack;


void createStack(stack *s)
{
	s->top=-1;
}

typedef enum{ lparen, rparen, plus, minus, divide, multiply, mod, eos, operand }precedence;


void push(stack *s, int c)
{
	if(s->top==MAX-1) printf("\nStack Overflow.");
	else
	{
		s->arr[++(s->top)]=c;
	}
}

int pop(stack *s)
{
	if(s->top==-1) printf("\nStack Underflow.");
	else
	{
		return s->arr[(s->top)--];
	}
}

void display(stack *s)
{
	printf("\nStack is as follows:");
	int i=0;
	for(;i<=s->top;i++)
	{
		printf("\t%d",s->arr[i]);
	}
}

precedence getSymbol(char exp[], int *n)
{
	char ch=exp[(*n)++];
	switch(ch)
	{
		case '*': return multiply;
		case '/': return divide;
		case '+': return plus;
		case '-': return minus;
		case '%': return mod;
		case '(': return lparen;
		case ')': return rparen;
		case '\0': return eos;
		default: return operand;
	}
}

int postfixEval(char exp[])
{
	char ch; int n=0,op1,op2;
	stack s;
	createStack(&s);
	//push(&s,eos);
	precedence token=getSymbol(exp,&n);
	while(token!=eos)
	{
		//display(&s);
		char c=exp[n-1];
		if(token==operand)
		{
			push(&s,c-'0');
		}
		else
		{
			op2=pop(&s);
			op1=pop(&s);
		}
			switch(token)
			{
				case plus: {
						int c=(op1+op2);
						push(&s,c);
						break;
					}
					
				case minus:{
						int c=(op1-op2);
						push(&s,c);
						break;
					}
					
				case multiply:{
							int c=op1*op2;
							push(&s,c);
							break;
					}
					
				case divide:{
							 int c=op1/op2;  
							push(&s,c);
							break;
					}
				case mod:{
						 int c=op1%op2;
							push(&s,c);
							break;
					}
			}
		
		token=getSymbol(exp,&n);
	}
	return pop(&s);
}

int main()
{
	char exp[50];
	printf("\nEnter the postfix expression:");
	scanf("%s",exp);
	int x=postfixEval(exp);
	printf("\nAnswer:%d",x);
	return 0;
}
