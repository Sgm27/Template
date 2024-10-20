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
	//freopen("thu.inp","r",stdin);
	ll n,cs=0,res=0;
	scanf("%lld",&n);
	n=1+(n-1)*2;
	while (n>0)
	{
		cs++;
		if (cs%2) res+=(n+1)*((n-1)/2 +1)/2;
		else res+=(n+2)*((n-2)/2 +1)/2;
		n-=3;
	}
	printf("%lld",res);
}

