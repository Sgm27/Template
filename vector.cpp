#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define bit(i,n) ((n>>i) & 1)
const int MOD=1e9+7,INF=4e18;
#define maxn 35 
int n,U,V;
pii a[maxn],b[maxn];
map<pii,int> mp;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    int n1 = n/2;
    FOR(i,0,n1-1) cin>>a[i].first>>a[i].second;
    int n2 = n/2 + (n & 1);
    FOR(i,0,n2-1) cin>>b[i].first>>b[i].second;
    cin>>U>>V;
    FOR(mask,0,(1<<n1)-1)
    {
        int X = 0, Y = 0;
        FOR(i,0,n1-1)
            if (bit(i,mask)) X += a[i].first, Y += a[i].second;
        mp[{X,Y}]++;
    }
    int ans = 0;
    FOR(mask,0,(1<<n2)-1)
    {
        int X = 0, Y = 0;
        FOR(i,0,n2-1)
            if (bit(i,mask)) X += b[i].first, Y += b[i].second;
        ans += mp[{U-X,V-Y}];
    }
    cout<<ans;
}
