#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
const ll Max=1e9;

int max(int a,int b)
{
	if (a>b) return a;
	return b;
}
ll min(ll a,ll b)
{
	if (a>b) return b;
	return a;
}


int main()
{
//	freopen("thu.inp","r",stdin);
	ll n,minx=Max,miny=Max;
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
	{
		ll x,y;
		scanf("%lld %lld",&x,&y);
		minx=min(minx,x);
		miny=min(miny,y);
	}
	printf("%lld",minx*miny);
}

