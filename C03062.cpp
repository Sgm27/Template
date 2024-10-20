#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
ll gcd(ll a,ll b)
{
	if (!b) return a;
	else return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
	return ((a*b)/gcd(a,b));
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
		int x,y;
		scanf("%d %d",&x,&y);
		ll res=x;
		for (int i=x+1;i<=y;i++) res=lcm(res,i);
		printf("%lld\n",res);
	}
}

