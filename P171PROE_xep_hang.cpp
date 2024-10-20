#include<bits/stdc++.h>
using namespace std;
using ll = long long;
pair<ll,ll> a[200005];
ll n;
const ll inf=1e18;
void input()
{
    cin>>n;
    a[0].first=0;
    for (int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
}
void process()
{
    ll cs=0,l=0,r=inf;
    for (int i=0;i<n;i++)
    {
        cs+=a[i].first;
        if (a[i+1].second==1) l=max(l,1900-cs);
        else r=min(r,1899-cs);
    }
    if (r==inf)
    {
        cout<<"Infinity";
        return;
    }
    if (l!=0 && l>r)
    {
        cout<<"Impossible";
        return;
    }
    ll res=r;
    for (int i=1;i<=n;i++)
        res+=a[i].first;
    cout<<res;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

