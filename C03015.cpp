#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


long long max(long long a,long long b)
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
//	freopen("thu.inp","r",stdin);
	int tc;
	long long n,i,tmp,res;
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%lld",&n);
		tmp=sqrt(n);
		i=2;
		res=0;
		while (n!=1 && i<=tmp)
		{
			while (n%i==0) 
			{
				res=max(res,i);
				n/=i;
			}
			i++;
		}
		if (n!=1) res=max(res,n);
		if (!res) printf("%lld\n",n);
		else printf("%lld\n",res);
	}
}

