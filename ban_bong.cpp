#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
ll n,k,m;
struct mang{
    ll gt,kt,t;
} a[maxn];
bool cmp(mang a,mang b)
{
    return a.t<b.t;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i].gt>>a[i].kt;
        a[i].t=a[i].gt;
        if (a[i].kt>m) a[i].t+=(a[i].kt-m);
    }
    sort(a+1,a+1+n,cmp);
    ll ans=0;
    for (int i=1;i<=n;i++)
        if (a[i].t<=k) 
        {
            ans++;
            k-=a[i].t;
        }
        else break;
    cout<<ans;
}

