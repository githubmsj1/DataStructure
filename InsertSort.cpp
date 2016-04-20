#include<stdio.h>
#include<stdlib.h>


void InsertSort(int *array,int len)
{
	
	printf("The lenth of array is %d\n",len);
	for(int i=1;i<len;i++)
	{

		int index=i-1;
		int tmp=array[i];
		int j=0;
		for(j=i-1;j>=0;j--)
		{
			if(tmp>array[j])
			{
				//index=j;
				break;
			}
			else
			{
				//printf("tmp is %d\n");
				array[j+1]=array[j];
				
			}

		}
		array[j+1]=tmp;
		printf("j:%d",j);
		// if(j==0)
		// {
		// 	array[0]=tmp;
		// }
		// else
		// {
		// 	array[index+1]=tmp;
		// }

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
	InsertSort(array,n);
	printf("after processing\n");
	for (int i = 0; i < n; ++i)
	{
		/* code */
		printf("%d\n",array[i]);
	}
	printf("\n");
	return 0;
}