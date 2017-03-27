#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 40

typedef struct node_
{
	int coef,exp;
	struct node_ *link;
}poly;

void createPoly(poly **h)
{
	*h=NULL;
}

void insertPoly(poly **head, int c, int e)
{
	poly *temp=malloc(sizeof(poly));
	temp->coef=c;
	temp->exp=e;
	if(*head==NULL)
	{
		*head=temp;
	}
	else if((*head)->link==(*head))
	{
		(*head)->link=temp;		
	}
	else
	{
		poly *t1=(*head)->link;
		while(t1->link!=*head)
		{
			t1=t1->link;
		}
		t1->link=temp;
	}
	temp->link=*head;
}

bool listContains(poly *head, int e)
{
	if(!head) return false;
	poly *t1=head;
	do{
		if(t1->exp==e) return true;
		t1=t1->link;
	}while(t1!=head);
	return false;
}


void displayPoly(poly *h)
{
	if(h==NULL) return;
	poly *temp=h;
	do{
		printf("\t(%dx^%d)",temp->coef,temp->exp);
		if(temp->link!=h) printf("+");
		temp=temp->link;
	}while(temp!=h);
}


void addPoly(poly *h1, poly *h2, poly **h3)
{
	poly *t1=h1;
	poly *t2=h2;
	poly *t3=*h3;
	do{
		insertPoly(h3,t1->coef,t1->exp);
		t1=t1->link;
	}while(t1!=h1);
	
	do{
		if(listContains(*h3,t2->exp))
		{
			poly *t4=*h3;
			do{
				if(t4->exp==t2->exp) break;
				t4=t4->link;
			}while(t4!=*h3);
			(t4->coef)+=t2->coef;
			//displayPoly(*h3);
		}
		else
		{
			insertPoly(h3,t2->coef,t2->exp);
		}
		t2=t2->link;
	}while(t2!=h2);
}

void multiplyPoly(poly *h1, poly *h2, poly **h4)
{
	poly *t1=h1;
	poly *t2=h2;
	poly *t4=*h4;
	do{
		t2=h2;
		do{
			if(listContains(*h4,(t1->exp+t2->exp)))
			{
				poly *t3=*h4;
				do{
					if(t3->coef==(t2->exp+t1->exp))
					{
						t3->coef+=t1->coef*t2->coef;
					}
				}while(t3!=*h4);
			}
			else
			{
				insertPoly(h4,t2->coef*t1->coef,t1->exp+t2->exp);
			}
			t2=t2->link;
		}while(t2!=h2);
		t1=t1->link;
	}while(t1!=h1);
}

int main()
{
	poly *h1, *h2, *h3, *h4;
	createPoly(&h1);
	createPoly(&h2);
	createPoly(&h3);
	createPoly(&h4);
	printf("\n1.Insert Polynomial.\n2.Add the polynomials.\n3.Multiply the polynomials.\n4.Display\n5.Exit");
	int choice;
	do{
		printf("\nEnter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nEnter data into which polynomial? Press 1 for F(x), 2 for G(x):");
					int ch;
					scanf("%d",&ch);
					printf("\nEnter coefficient and power:");
					int c,e;
					scanf("%d%d",&c,&e);
					if(ch==1) insertPoly(&h1,c,e);
					else if(ch==2) insertPoly(&h2,c,e);
					else printf("\nWrong choice.");
					break;
			
			case 2: addPoly(h1,h2,&h3);
					break;
					
			case 3: multiplyPoly(h1,h2,&h4);
					break;
			
			case 4: printf("\nF(x):"); displayPoly(h1);
					printf("\nG(x):"); displayPoly(h2);
					printf("\nF(x)+G(x)=H(x):"); displayPoly(h3);
					printf("\nF(x)*G(x)=I(x):"); displayPoly(h4);
					break;
		}
				
	}while(choice!=5);
	return 0;
}
