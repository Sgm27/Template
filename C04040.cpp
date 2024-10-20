#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
ll n,a[100005];

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
void process()
{
	ll sum=0,Max=-1e9;
	int check=0;
	for (int i=1;i<=n;i++) Max=max(Max,a[i]);
	if (Max<0) 
	{
		printf("%lld\n",Max);
		return;
	}
	for (int i=1;i<=n;i++)
	{
		sum+=a[i];
		if (sum<0) sum=0;
		else Max=max(Max,sum);
	}
	printf("%lld\n",Max);
}

int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%lld",&n);
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		process();
	}
}

