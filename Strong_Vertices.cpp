#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 200005
int n,b[maxn];
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
        FOR(i,1,n) cin>>a[i].first ,a[i].second=i;
        FOR(i,1,n) cin>>b[i], a[i].first-=b[i];
        sort(a+1,a+1+n);
        vector<int> res;
        res.push_back(a[n].second);
        FOD(i,n-1,1)
            if (a[i].first==a[i+1].first) res.push_back(a[i].second);
            else break;
        cout<<res.size()<<"\n";
        sort(res.begin(),res.end());
        for (int x : res) cout<<x<<" ";
        cout<<"\n";
    }
}
