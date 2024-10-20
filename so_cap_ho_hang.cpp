#include<iostream>
using namespace std;
using ll = long long;
#define maxn 
int cnt[(1<<10)+5];
int mask(ll x)
{
    int d[10]={},res=0;
    while (x)
    {
        int k=x%10;
        x/=10;
        if (!d[k]) res+=(1<<k);
        d[k]=1;
    }
    return res;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        cnt[mask(x)]++;
    }
    ll res=0;
    for (int mask=1;mask<(1<<10);mask++)
    {
        res+=max(0,cnt[mask]*(cnt[mask]-1)/2);
        for (int amask=mask+1;amask<=(1<<10);amask++)
            if (mask & amask) res+=max(0,cnt[mask]*cnt[amask]);
    }
    cout<<res;
}

