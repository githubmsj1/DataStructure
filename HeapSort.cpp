#include<stdio.h>
#include<stdlib.h>

void HeapAjust(int *array,int s,int m)
{
	int tmp=array[s];

	for(int i=(s+1)*2-1;i<=m;i=(i+1)*2-1)
	{
		if(i<m && array[i]<array[i+1])
		{
			i++;
		}

		if(!(tmp<array[i]))
		{
			break;
		}
		array[s]=array[i];
		s=i;
	}
	array[s]=tmp;
}

void HeapSort(int *array,size_t size)
{
	int endIdex=size-1;
	for(int i=endIdex/2;i>=0;i--)
	{
		HeapAjust(array,i,endIdex);
	}

	int tmp;
	for(int i=endIdex;i>0;i--)
	{
		tmp=array[0];
		array[0]=array[i];
		array[i]=tmp;
		HeapAjust(array,0,i-1);
	}
}

int main()
{
	int i;
	int *array;
	printf("input the size of array\n");
	int n;
	scanf("%d",&n);
	array=(int*)malloc(sizeof(int)*n);
	// int len=sizeof(array)/sizeof(array[0]);
	printf("Please input the data\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d/%d: ",i,n );
		scanf("%d",&array[i]);

	}
	HeapSort(array,n);
	printf("after processing\n");
	for (int i = 0; i < n; ++i)
	{
		/* code */
		printf("%d\n",array[i]);
	}
	printf("\n");
	return 0;
}