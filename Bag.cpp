#include <iostream>
#include <vector>

using namespace std;


int zeroOne(vector<int> v,vector<int>w,int volume)
{
	int f[volume+1];
	for(int i=0;i<volume+1;i++)
	{
		f[i]=0;
	}
	for(int i=0;i<w.size();i++)
	{
		for(int j=volume;j>=0;j--)
		{
			if(j>=w[i])
			{
				f[j]=f[j]>f[j-w[i]]+v[i]?f[j]:f[j-w[i]]+v[i];
			}

		}
	}
	return f[volume];
}

int complete(vector<int> v,vector<int>w,int volume)
{
	int f[volume+1];
	for(int i=0;i<volume+1;i++)
	{
		f[i]=0;
	}
	for(int i=0;i<w.size();i++)
	{
		for(int j=0;j<=volume;j++)
		{
			if(j>=w[i])
			{
				f[j]=f[j]>f[j-w[i]]+v[i]?f[j]:f[j-w[i]]+v[i];
			}

		}
	}
	return f[volume];
}

int multi(vector<int> v,vector<int>w,vector<int>num,int volume)
{
	int f[volume+1];
	for(int i=0;i<volume+1;i++)
	{
		f[i]=0;
	}
	for(int i=0;i<w.size();i++)
	{



		for(int j=volume;j>=0;j--)
		{
			for(int k=1;k<=num[i];k++)
			{
				if(j>=k*w[i])
				{
					f[j]=f[j]>f[j-k*w[i]]+k*v[i]?f[j]:f[j-k*w[i]]+k*v[i];
				}
			}

		}


	}
	return f[volume];
}


int main()
{
	int _v[]={1,2,3,4};
	int _w[]={1,1,3,4};
	int _n[]={2,3,2,3};
	vector<int>v(_v,_v+sizeof(_v)/sizeof(int));
	vector<int>w(_w,_w+sizeof(_w)/sizeof(int));
	vector<int>n(_n,_n+sizeof(_n)/sizeof(int));

	cout<<zeroOne(v,w,5)<<endl;
	cout<<complete(v,w,5)<<endl;
	cout<<multi(v,w,n,5)<<endl;

	return 0;
}