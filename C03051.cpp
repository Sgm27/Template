#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
const int N=1000005;
int prime[1000005];

void sang()
{
	for (int i=1;i<=N;i++) prime[i]=1;
	prime[0]=0; prime[1]=0;
	for (int i=2;i<=sqrt(N);i++)
		if (prime[i])
			for (int j=i*i;j<=N;j+=i) prime[j]=0;
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
int cp(ll k)
{
	ll tmp=sqrt(k);
	if (tmp*tmp==k) return 1;
	return 0;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	sang();
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		ll l,r,cnt=0;
		scanf("%lld %lld",&l,&r);
		if (cp(l)) l=sqrt(l);
		else l=sqrt(l)+1;
		r=sqrt(r);
		for (int i=l;i<=r;i++)
			if (prime[i]) cnt++;
		printf("%lld\n",cnt);
	}
}

