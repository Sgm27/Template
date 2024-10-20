#include<iostream>
#include<map>
using namespace std;
using ll = long long;
map<ll,ll> mp;
void Update(ll x,ll y,ll w)
{
    mp[x]+=w;
    mp[y]+=w;
    while (x!=y)
    {
        if (x>y)
        {
            x/=2;
            mp[x]+=w;
        }
        else
        {
            y/=2;
            mp[y]+=w;
        }
    }
    mp[x]-=2*w;
}
ll Get(ll x,ll y)
{
    ll ans=mp[x]+mp[y];
    while (x!=y)
    {
        if (x>y)
        {
            x/=2;
            ans+=mp[x];
        }
        else
        {
            y/=2;
            ans+=mp[y];
        }
    }
    return ans-mp[x]*2;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int q; cin>>q;
    while (q--)
    {
        int type;
        cin>>type;
        if (type==1)
        {
            ll x,y,w;
            cin>>x>>y>>w;
            Update(x,y,w);
        }
        else{
            ll x,y;
            cin>>x>>y;
            cout<<Get(x,y)<<"\n";
        }
    }
}

