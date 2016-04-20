#include<stdio.h>
#include<stdlib.h>


void ShellSort(int *array,int len)
{
	int k=len/2;
	while(k>0)
	{
		
		for(int i=k;i<len;i++)
		{
			int tmp=array[i];
			int j;
			for(j=i-k;j>=0;j-=k)
			{
				if(tmp>array[j])
				{
					break;
				}
				else
				{
					array[j+k]=array[j];
				}
			}	
			array[j+k]=tmp;		
		}
		k=k/2;
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
		printf("%d/%d: ",i,n-1 );
		scanf("%d",&array[i]);

	}
	ShellSort(array,n);
	printf("after processing\n");
	for (int i = 0; i < n; ++i)
	{
		/* code */
		printf("%d\n",array[i]);
	}
	printf("\n");
	return 0;
}