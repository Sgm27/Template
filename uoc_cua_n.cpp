#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
ll n,a,b,uoc1=0,uoc2=0;
void dem_uoc(ll k)
{
    int i=2;
    while (k!=1)
    {
        int cnt=0;
        while (k%i==0) 
        {
            cnt++;
            k/=i;
        }
    }
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
void process(ll n,ll a,ll b)
{
    ll res=0;
    n=(n)*(n+a)*(n+b);
    for (ll i=2;i<n;i++)
        if (n%i!=0 && (n*n)%i==0) res++;
    printf("%d\n",res);
}
int main()
{
    freopen("thu.inp","r",stdin);
    int tc;
    scanf("%d",&tc);
    while (tc--)
    {
        scanf("%lld %lld %lld",&n,&a,&b);
        process(n,a,b);
    }
}
