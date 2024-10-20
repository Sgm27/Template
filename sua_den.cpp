#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,k,b,d[100005],sum[100005];
void input()
{
    memset(d,0,sizeof(d));
    sum[0]=0;
    cin>>n>>k>>b;
    k--;
    for (int i=1;i<=b;i++) 
    {
        ll x;
        cin>>x;
        d[x]=1;
    }
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+d[i];
}
void process()
{
    ll res=1e9;
    for (int i=1;i<=n-k;i++)
    {
        res=min(res,sum[i+k]-sum[i-1]);
    }
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

