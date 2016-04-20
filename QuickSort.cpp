#include<stdio.h>
#include<stdlib.h>

int Partition(int *array,int low,int high)
{
	int pivotkey=array[low];

	while(low<high)
	{
		while(high>low&&array[high]>=pivotkey)
		{
			high--;
		}
		array[low]=array[high];

		while(high>low&&array[low]<=pivotkey)
		{
			low++;
		}
		array[high]=array[low];
	}
	array[low]=pivotkey;
	return low;
}
void QuickSort(int *array,int low,int high)
{
	if(low<high)
	{
		int pivoloc=Partition(array,low,high);
		QuickSort(array,low,pivoloc-1);
		QuickSort(array,pivoloc+1,high);
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
	QuickSort(array,0,n-1);
	printf("after processing\n");
	for (int i = 0; i < n; ++i)
	{
		/* code */
		printf("%d\n",array[i]);
	}
	printf("\n");
	return 0;
}