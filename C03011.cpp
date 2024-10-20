#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
ll gt[15];

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
void init()
{
	gt[0]=1;
	for (int i=1;i<=10;i++) gt[i]=gt[i-1]*i;
}
int strong(ll n)
{
	ll k=n,sum=0;
	while (n)
	{
		int tmp=n%10;
		n/=10;
		sum+=gt[tmp];
	}
	if (sum==k) return 1;
	return 0;
}
int main()
{
	init();
//	freopen("thu.inp","r",stdin);
	ll n,m;
	scanf("%lld %lld",&n,&m);
	for (ll i=min(n,m);i<=max(n,m);i++)
		if (strong(i)) printf("%lld ",i);
}

