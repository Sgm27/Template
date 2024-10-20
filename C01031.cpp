#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


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
	//freopen("thu.inp","r",stdin);
	int tc,n;
	scanf("%d",&tc);
	while (tc--)
	{
		int i=2;
		long long res=1;
		scanf("%d",&n);
		while (n!=1)
		{
			if (n%i==0)
			{
				res*=i;
				while (n%i==0) n/=i;
			}
			else i++;
		}
		printf("%lld\n",res);
	}
}

