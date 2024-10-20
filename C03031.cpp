#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
ll gcd(ll a,ll b)
{
	if (!b) return a;
	return gcd(b,a%b);
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
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		ll a,b,c,d;
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		if (gcd(a,b)==gcd(c,d)) printf("YES\n");
		else printf("NO\n");
	}
}

