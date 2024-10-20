#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,k;
void input()
{
    cin>>n>>m>>k;
}
ll f(ll x)
{
    ll cnt=0,mod=0;
    for (ll i=1;i<=n;i++) cnt+=min(x/i,m);
    return cnt;
}
void process()
{
    ll l=0,r=n*m,ans;
    while (r-l>1)
    {
        ll mid=(l+r)/2;
        if (f(mid)>=k) r=mid;
        else l=mid;
    }
    cout<<r;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}
