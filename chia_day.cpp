#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 100005
int n,a[maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    set<int> s;
    FOR(i,1,n)
    {
        auto pos = s.upper_bound(a[i]);
        if (pos == s.begin()) s.insert(a[i]);
        else
        {
            pos = prev(pos);
            s.erase(pos);
            s.insert(a[i]);
        }
    }
    cout<<s.size();
}
