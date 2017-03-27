#include<stdio.h>
#include<stdlib.h>

int partitionIt(int *a, int start, int end)
{
    int pivot=a[end];
    int i=start;
    int pIndex=start;
    for(;i<end;i++)
    {
        if(a[i]<pivot)
        {
            int temp=a[i];
            a[i]=a[pIndex];
            a[pIndex]=temp;
            pIndex+=1;
        }
    }
    int temp=a[end];
    a[end]=a[pIndex];
    a[pIndex]=temp;
    return pIndex;
}

void quickSort(int *a, int start, int end)
{
    if(start>=end) return;
    int pIndex=partitionIt(a,start,end);
    quickSort(a,start,pIndex-1);
    quickSort(a,pIndex+1,end);
}

int main()
{
    int *a;
    int i,n;
    printf("\nEnter the size of the array:");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("\nEnter the array elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    quickSort(a,0,n-1);
    printf("\nSorted array is:");
    for(i=0;i<n;i++)
        printf("\t%d",a[i]);
    printf("\n\n\t\t\t\tQUICKSORT.");
    return 0;
}
