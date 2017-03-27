#include<stdio.h>
#include<stdlib.h>

void main()
{
    int **table;
    printf("\nNumber of rows? :");
    int i,n,j;
    scanf("%d",&n);
    table=(int**)malloc(n*sizeof(int*));
    printf("\nEnter the number of columns for each row:");
    for(i=0;i<n;i++)
    {
        int c;
        scanf("%d",&c);
        table[i]=(int*)calloc(c+1,sizeof(int));
        table[i][0]=c;
    }

    printf("\n \nEnter values for each row: ");
    for(i=0;i<n;i++)
    {
        for(j=1;j<=table[i][0];j++)
        scanf("%d",&table[i][j]);
    }

      for(i=0;i<n;i++)
    {
        for(j=1;j<=table[i][0];j++)
        printf("\t %d \t",table[i][j]);

    printf("\n");
    }
}
