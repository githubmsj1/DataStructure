#include<stdio.h>
#include<stdlib.h>

void Merge(int *source,int *target,int i,int m,int n)
{
	int j,k;
	for(j=m+1,k=i;i<=m&&j<=n;k++)
	{
		if(source[i]<source[j])
		{
			target[k]=source[i++];
		}
		else
		{
			target[k]=source[j++];
		}
	}
	while(i<=m)
	{
		target[k++]=source[i++];
	}
	while(j<=n)
	{
		target[k++]=source[j++];
	}
}

void MergeSort(int *source,int *target,int s,int t)
{
	int m,*tmp;
	if(s==t)
	{
		target[s]=source[s];
	}
	else
	{
		tmp=(int*)malloc(sizeof(int)*(t-s+1));
		m=(s+t)/2;
		MergeSort(source,tmp,s,m);
		MergeSort(source,tmp,m+1,t);
		Merge(tmp,target,s,m,t);
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
	MergeSort(array,array,0,n-1);
	printf("after processing\n");
	for (int i = 0; i < n; ++i)
	{
		/* code */
		printf("%d\n",array[i]);
	}
	printf("\n");
	return 0;
}