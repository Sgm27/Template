#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
#define maxn 200005
ll n,d,a[maxn];
ll c,pre[maxn];
ll f(ll k)
{
    ll res=0;
    k++;
    res=1ll*(d/k)*pre[min(1ll*n,k)]+pre[min(1ll*n,d%k)];
    return max(res,pre[min(n,d)]);
}
void process()
{
    if (f(0)<c) 
    {
        cout<<"Impossible\n";
        return;
    }
    ll l=0,r=1e18;
    while (r-l>1)
    {
        ll mid=(l+r)/2;
        if (f(mid)>=c) l=mid;
        else r=mid;
    }
    if (l==999999999999999999) cout<<"Infinity\n";
    else cout<<l<<"\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        pre[0]=0;
        cin>>n>>c>>d;
        for (int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n,greater<int>());
        for (int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
        process();
    }
}

