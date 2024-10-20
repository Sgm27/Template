#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 100005
int n,k,p;
int a[maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k>>p;
    FOR(i,1,n) cin>>a[i];
    int sum = 0, ans = INF;
    set<int> se;
    for (int i=1;i<=n;i++)
    {
        (sum += a[i]) %= p;
        auto pos = se.upper_bound((sum - k + p*p) %p);
        if (pos == se.begin()) 
        {
            se.insert(sum);
            continue;
        }
        pos = prev(pos);
        ans = min(ans,(sum - *pos + p*p) %p);
        se.insert(sum);
    }
    cout<<ans;
}
