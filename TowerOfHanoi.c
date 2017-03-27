#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void TowerOfHanoi(int n, char a[20], char b[20], char c[20])
{
	if(n==1)
	{
		printf("\nMove peg %d from %s to %s.",n,a,c);
	}
	else
	{
		TowerOfHanoi(n-1,a,c,b);
		printf("\nMove peg %d from %s to %s.",n,a,c);
		TowerOfHanoi(n-1,b,a,c);
	}
}

int main()
{
	int n;
	char a[20], b[20], c[20];
	strcpy(a,"Source");
	strcpy(b,"Auxilliary");
	strcpy(c,"Destination");
	printf("\nEnter the number of pegs:");
	scanf("%d",&n);
	TowerOfHanoi(n,a,b,c);
	return;
}
