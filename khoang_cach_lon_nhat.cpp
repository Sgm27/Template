#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,l,r,a[100005];
void input()
{
    cin>>n>>l>>r;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
}
ll f(ll k)
{
    int it=lower_bound(a+1,a+1+n,k)-a;
    return min(abs(k-a[it]),abs(k-a[it-1]));
}
void process()
{
    while (r-l>4)
    {
        ll m1=(l+r)/2;
        ll m2=m1+1;
        if (f(m1)>f(m2)) l=m2;
        else r=m2;
    }
    ll Max=-9e18,ans;
    for (int i=l;i<=r;i++) 
    {
        ll tmp=f(i);
        if (tmp>Max)
        {
            Max=tmp;
            ans=i;
        }
    }
    cout<<ans;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

