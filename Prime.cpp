#include <stdlib.h>

#include <vector>
#include <iostream>
#include <limits.h>

#define MAX_NODE 10

using namespace std;

bool isPrime(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return n!=1;
}


void sieve(int n)
{
	int prime[n+1];
	for(int i=2;i<=n;i++)
		prime[i]=true;
	prime[0]=prime[1]=false;

	for(int i=2;i<=n;i++)
	{
		if(prime[i]==true)
		{
			cout<<prime[i]<<" ";
			for(int j=2*i;j<=n;j+=i)
				prime[j]=false;
		}
	}
}

int main()
{
	sieve(12);
	return 0;
}
