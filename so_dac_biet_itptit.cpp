#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
const ll N=1e6+5;
const ll limit=1e12;
ll prime[1000005],nt[79000],n=0,res[100005],nmax=0;
void sang()
{
	for (int i=1;i<=N;i++) prime[i]=1;
	prime[0]=0; prime[1]=0;
	for (int i=2;i<=sqrt(N);i++)
		if (prime[i])
		{
			for (int j=i*i;j<=N;j+=i) prime[j]=0;
		}
	for (int i=1;i<=N;i++) 
		if (prime[i]) nt[++n]=i;
}
void swap(ll *a,ll *b)
{
	ll tmp=*a;
	*a=*b;
	*b=tmp;
}
void sort(ll l,ll r)
{
	ll i=l,j=r,g=res[(ll)((i+j)/2)];
	while (i<=j)
	{
		while (res[i]<g) i++;
		while (res[j]>g) j--;
		if (i<=j)
		{
			swap(&res[i],&res[j]);
			i++;
			j--;
		}
	}
	if (l<j) sort(l,j);
	if (i<r) sort(i,r); 
}
void process()
{
	for (int i=1;i<=n;i++)
	{
		ll j=2,tmp=nt[i];
		while (1)
		{
			if (tmp*nt[i]<limit) 
			{
				if (prime[j+1]) 
					res[++nmax]=tmp*nt[i];
				tmp*=nt[i];
				j++;
			}
			else break;
		}
	}
	res[++nmax]=1e12+1;
	sort(1,nmax);
}
ll Bsearch(ll l,ll r,ll key)
{
	ll ans=-1;
	while (l<=r)
	{
		ll mid=(l+r)/2;
		if (res[mid]>=key)
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}
int main()
{
	// freopen("thu.inp","r",stdin);
	sang();
	process();
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		ll a,b;
		scanf("%lld %lld",&a,&b);
		ll l=Bsearch(1,nmax,a);
		ll r=Bsearch(1,nmax,b);
		if (b<res[r]) r--;
		printf("%lld\n",r-l+1);
	}
}

