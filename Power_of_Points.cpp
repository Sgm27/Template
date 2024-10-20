#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 200005
int n,ps[maxn];
pii a[maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n;
        FOR(i,1,n) cin>>a[i].first, a[i].second=i;
        sort(a+1,a+1+n);
        FOR(i,1,n) ps[i]=ps[i-1]+a[i].first;
        vector<int> ans(n+5);
        FOR(i,1,n)
            ans[a[i].second]=a[i].first*i-ps[i]+(ps[n]-ps[i])-a[i].first*(n-i)+n;
        FOR(i,1,n) cout<<ans[i]<<" ";
        cout<<"\n";
    }
}
