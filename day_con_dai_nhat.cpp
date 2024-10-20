#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
ll n,a[1000006],d[1000006];

ll max(ll a,ll b)
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
	memset(d,0,sizeof(d));
//	freopen("thu.inp","r",stdin);
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	ll l=1,r=1,res=1;
	while (r<=n)
	{
		d[a[r]]++;
		while (d[a[r]]>=2) 
		{
			d[a[l]]--;
			l++;
		}
		res=max(res,r-l+1);
		r++;
	}
	printf("%lld",res);
}

