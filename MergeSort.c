#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 200

void merge(int arr[], int low, int mid, int high)
{
	int nL=mid-low+1; int nR=high-mid;
	int *newL=malloc(nL*sizeof(int));
	int *newR=malloc(nR*sizeof(int));
	int i,j;
	
	for(i=0;i<nL;i++)
	{
		newL[i]=arr[low+i];
	}
	
	for(j=0;j<nR;j++)
	{
		newR[j]=arr[mid+j+1];
	}
	/*for(i=0;i<nL;i++)
	  printf("\n %d",newL[i]);
	for(i=0;i<nR;i++)
	  printf("\n %d",newR[i]);*/  
	  
	i=j=0;
	int k=low;
	while(i<nL&&j<nR)
	{
		if(newL[i]>newR[j])
		{
			arr[low+k]=newR[j++];
			k++;
		}
		else
		{
			arr[low+k]=newL[i++];
			k++;
		}
	}
	
	if(i>=nL)
	{
		while(j<nR)
		{
			arr[low+k]=newR[j++];
			k++;
		}
	}
	if(j>=nR)
	{
		while(i<nL)
		{
			arr[low+k]=newL[i++];
			k++;
		}
	}
}

void mergeSort(int arr[], int low, int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}

int main()
{
	printf("\nEnter the size of the array:");
	int i,n;
	scanf("%d",&n);
	int* arr=malloc(n*sizeof(int));
	printf("\nEnter the array elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	mergeSort(arr,0,n);
	printf("\nMerge sort performed.");
	printf("\nArray is as follows:");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
