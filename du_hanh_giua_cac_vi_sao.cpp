#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
ll n,m,d,t,v[100005],p[100005],a[100005];
void input()
{
    scanf("%lld %lld %lld %lld",&n,&m,&d,&t);
    for (int i=1;i<=n;i++) scanf("%lld %lld",&v[i],&p[i]);
    for (int i=1;i<=m;i++) scanf("%lld",&a[i]);
}
void swap(ll *a,ll *b)
{
	ll tmp=*a;
	*a=*b;
	*b=tmp;
}
void sort(ll l,ll r)
{
	ll i=l,j=r,g=a[(ll)((i+j)/2)];
	while (i<=j)
	{
		while (a[i]<g) i++;
		while (a[j]>g) j--;
		if (i<=j)
		{
			swap(&a[i],&a[j]);
			i++;
			j--;
		}
	}
	if (l<j) sort(l,j);
	if (i<r) sort(i,r); 
}
ll Bsearch(ll a[],ll l,ll r,ll key)
{
    ll ans=-1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (a[mid]<=key)
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}
ll time(ll k)
{
    ll vis=0,res=0,pos=1;
    while (1)
    {
        if (vis+k>=d)
        {
            res=res+(d-vis)/2 +(d-vis)%2;
            return res;
        }
        pos=Bsearch(a,1,m,vis+k);
        res=res+(a[pos]-vis)/2+(a[pos]-vis)%2;
        vis=a[pos];
    }
}
void process()
{
    if (d/2+d%2>t)
    {
        printf("No hope!");
        return;
    }
    if (d==1) 
    {
        ll tmp=1e9+5;
        for (int i=1;i<=n;i++) tmp=fmin(tmp,v[i]);
        if (tmp==1e9+5)
            printf("No hope!");
        else printf("%lld",tmp);
        return;
    }
    sort(1,m);
    ll energy_min=fmax(a[1],d-a[m]),time_min=0;
    for (int i=2;i<=m;i++)
    {
        energy_min=fmax(energy_min,a[i]-a[i-1]);
    }
    ll l=energy_min,r=2000000005,ans=-1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (time(mid)<=t)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    if (ans==-1)
    {
        printf("No hope!");
        return;
    }
    ll res=2000000005;
    for (int i=1;i<=n;i++)
        if (p[i]>=ans) res=fmin(res,v[i]);
    if (res==2000000005)
        printf("No hope!");
    else printf("%lld",res);
}
int main()
{
    //  freopen("thu.inp","r",stdin);
    input();
    process();
}
