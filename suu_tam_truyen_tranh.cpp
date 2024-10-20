#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool cp(ll k)
{
    ll tmp=sqrt(k);
    if (tmp*tmp==k) return true;
    return false;
}
void process(ll n,ll a[])
{
    ll Min=1e9,res=0;
    for (int i=1;i<=n;i++) Min=min(Min,a[i]);
    for (int i=1;i<=n;i++) a[i]-=Min;
    ll gcd=0;
    for (int i=1;i<=n;i++) gcd=__gcd(gcd,a[i]);
    for (int i=1;i<=sqrt(gcd);i++)
        if (gcd%i==0) res+=2;
    if (cp(gcd)) res--;
    cout<<res<<endl;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc;
    cin>>tc;
    while (tc--)
    {
        ll n,a[100005];
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        process(n,a);
    }
}

