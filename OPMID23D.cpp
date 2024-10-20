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
ll process(ll n)
{
    ll ans=-1;
    for (int i=3;i<=sqrt(n);i+=2)
        if (n%i==0 && n/i - (n/i)/2 >0) return i;
    return ans;
}

int main()
{
    freopen("thu.inp","r",stdin);
    int tc;
    scanf("%d",&tc);
    while (tc--)
    {
        ll x;
        scanf("%lld",&x);
        if (x%2!=0) printf("2\n");
        else printf("%lld\n",process(x));
    }
}
