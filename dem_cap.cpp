#include<bits/stdc++.h>
using namespace std;
#define f0(i,n) for (int i=0;i<n;i++)
#define f1(i,n) for (int i=1;i<=n;i++)
using ll = long long;
#define maxn 
int cnt[1<<14],n,k,Max;
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    f1(i,n) 
    {
        int x; cin>>x;
        Max=max(Max,x);
        cnt[x]++;
    }
    ll ans=0;
    for (int i=0;i<=Max;i++)
    {
        if (!k) 
        {
            ans+=max(0,cnt[i]*(cnt[i]-1)/2);
            continue;
        }
        for (int j=i+1;j<=Max;j++)
        {
            int tmp=i^j;
            if (__builtin_popcount(tmp)==k) 
            {
                ans+=max(0,cnt[i]*cnt[j]);
                // if (cnt[i]*cnt[j]) cout<<i<<" "<<j<<"\n";
            }
        }
    }
    cout<<ans;
}
