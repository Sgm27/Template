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
	ll n,ssh;
	scanf("%lld",&n);
	if (n%2)
	{
		ssh=(n-1)/2+1;
		if (ssh%2) printf("1");
		else printf("0");
	}
	else
	{
		printf("0");
	}
}

