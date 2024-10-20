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
int n,k;
ll a[100005],sum[100005];

int main()
{
	freopen("thu.inp","r",stdin);
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]), sum[i]=sum[i-1]+a[i];
	ll ans=-1e18,l,r;
	for (int i=k;i<=n;i++)
	{
		if (sum[i]-sum[i-k]>=ans) 
		{
			ans=sum[i]-sum[i-k];
			l=i-k+1;
			r=i;
		}
	}
	printf("%lld\n",ans);
	for (int i=l;i<=r;i++) printf("%lld ",a[i]);
}

