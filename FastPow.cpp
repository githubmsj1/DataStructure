#include <stdlib.h>

#include <vector>
#include <iostream>
#include <limits.h>

#define MAX_NODE 10

using namespace std;

int fastPow(int x,int n,int mod)
{
	int res=1;
	while(n>0)
	{
		if(n&1!=0)res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}


int main()
{
	int,x,n,mod;
	cin>>x>>n>>mod;
	cout<<fastPow(x,n,mod)<<endl;
	return 0;
}
