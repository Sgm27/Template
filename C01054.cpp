#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
const int N=2000005;
int prime[N];
void sang()
{
	for (int i=0;i<=N;i++) prime[i]=i;
	prime[0]=0;
	prime[1]=0;
	for (int i=2;i<=sqrt(N);i++)
		if (prime [i])
			for (int j=i*i;j<=N;j+=i) 	
				if (prime[j]==j) prime[j]=i;
}
int max(int a,int b)
{
	if (a>b) return a;
	return b;
}
int min(int a,int b)
{
	if (a>b) return b;
	return a;
}


int main()
{
	sang();
//	freopen("thu.inp","r",stdin);
	int tc,n;
	long long res=0;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d",&n);
		while (n!=1)
		{
			int tmp=prime[n];
			while (n%tmp==0) 
			{
				res+=tmp;
				n/=tmp;
			}
		}
	}
	printf("%lld",res);
}

