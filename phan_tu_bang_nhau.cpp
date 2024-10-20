#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
int d[100005],n,a[100005];

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
	ll res=0;
	//freopen("thu.inp","r",stdin);
	memset(d,0,sizeof(d));
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%lld",&a[i]);
		d[a[i]]++;
	}
	for (int i=1;i<=n;i++)
		if (d[a[i]])
		{
			ll tmp=d[a[i]];
			res+=(tmp-1)*tmp/2;
			d[a[i]]=0;
		}
	printf("%lld",res);
}

