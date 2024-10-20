#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;

ll n,a[5005];
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
int cmp(const void *a,const void *b)
{
	ll *x=(ll*)a;
	ll *y=(ll*)b;
	return *x-*y;
}
ll cp(ll k)
{
	ll tmp=sqrt(k);
	if (tmp*tmp==k) return 1;
	return 0;
}
ll binary_search(ll a[],ll l,ll r,ll key)
{
	while (l<=r)
	{
		ll mid=(l+r)/2;
		if (a[mid]==key) return 1;
		else 
			if (a[mid]<key) l=mid+1;
			else r=mid-1;
	}
	return 0;
}
void process()
{
	qsort(a+1,n,sizeof(ll),cmp);
	for (int i=1;i<=n-2;i++)
		for (int j=i+1;j<=n-1;j++)
		{
			ll tmp=a[i]*a[i]+a[j]*a[j];
			if (!cp(tmp)) continue;
			if (binary_search(a,1,n,sqrt(tmp)))
			{
				printf("YES\n");
				return;
			}
		}
	printf("NO\n");
}

int main()
{
	//freopen("thu.inp","r",stdin);
	ll tc;
	scanf("%lld",&tc);
	while (tc--)
	{
		scanf("%lld",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		process();
	}
}

