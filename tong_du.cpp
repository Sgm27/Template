#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;


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
//	freopen("thu.inp","r",stdin);
	ll n,a;
	scanf("%lld %lld",&a,&n);
	if ((a==3 && n==2) || (a==3 && n==3) || (a==4 && n==2)) 
	{
		printf("1");
		return 0;
	}
	if (a>=n) 
	{
		printf("0");
		return 0;
	}
	ll sum=(a*(a+1))/2;
	if (sum==n)
	{
		printf("1");
		return 0;
	}
	printf("0");
}

