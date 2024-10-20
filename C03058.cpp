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
ll gcd(ll a,ll b)
{
	if (!b) return a;
	else return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
	return a*b/gcd(a,b);
}
void process(int n)
{
	ll res=1;
	for (int i=1;i<=n;i++) res=lcm(res,i);
	printf("%lld\n",res);
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		int n;
		scanf("%d",&n);
		process(n);
	}
}

