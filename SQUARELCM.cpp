#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 200005
ll n,a[maxn];
ll lcm(ll a,ll b)
{
    return a/__gcd(a,b)*b;
}
bool cp(ll x)
{
    ll tmp=sqrt(x);
    return tmp*tmp==x;
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    ll ans=0,pre_lcm=1;
    for (int i=1;i<=n;i++)
    {
        ll t1=lcm(a[i],a[i+1]);
        ll t2=lcm(a[i])
        if (bc%pre_lcm!=0) ans++;
        pre_lcm=bc; 
    }   
    cout<<ans;
}

