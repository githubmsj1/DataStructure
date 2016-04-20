#include<stdio.h>
#include<stdlib.h>

int GetNumInPos(int num,int pos)
{
	
	int temp[]={1,10,100,1000,10000};
	return (num/temp[pos-1])%10;
}

void RadixSort(int *array,size_t size,size_t bit_num)
{
	int radix=10;
	int *count,*bucket,i,j,k;
	count=(int*)malloc(sizeof(int)*radix);
	bucket=(int*)malloc(sizeof(int)*size);
	
	for(k=1;k<=bit_num;k++)
	{
		for(int i=0;i<radix;i++)
		{
			count[i]=0;
		}

		for(int i=0;i<size;i++)
		{
			count[GetNumInPos(array[i],k)]++;
		}

		for(int i=1;i<radix;i++)
		{
			count[i]=count[i]+count[i-1];
		}

		int j=0;
		for(int i=size-1;i>=0;i--)
		{
			j=GetNumInPos(array[i],k);
			bucket[count[j]-1]=array[i];
			count[j]--;
		}

		for(int i=0;i<size;i++)
		{
			array[i]=bucket[i];
		}
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
	RadixSort(array,n,3);
	printf("after processing\n");
	for (int i = 0; i < n; ++i)
	{
		/* code */
		printf("%d\n",array[i]);
	}
	printf("\n");
	return 0;
}