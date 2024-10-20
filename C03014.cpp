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
ll lcm(ll a,ll b)
{
	return a*b/gcd(a,b);
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
	ll n,m;
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%lld %lld",&n,&m);
		printf("%lld %lld\n",lcm(n,m),gcd(n,m));
	}
}

