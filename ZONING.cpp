#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1000006
#define int long long
int n,a[maxn],x;
signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>x;
        for (int i=1;i<=n;i++) cin>>a[i];
        int l=1,r=1,sum=0,ans=0;
        while (r<=n+1)
        {
            if (sum==x) 
            {
                ans++;
                sum-=a[l++];
                sum+=a[r++];

            }
            else 
            if (sum<x) sum+=a[r++];
            else
            if (sum>x) sum-=a[l++];
        }
        if (ans) cout<<ans; else cout<<"HUHU";
        cout<<"\n";
    }
}

