#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define bit(i,n) ((n>>i) & 1)
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 35
int coin[maxn];
map<int,int> L,R;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    coin[1] = 2, coin[2] = 3, coin[3] = 5;
    FOR(i,4,34) coin[i] = coin[i-1] + coin[i-2] + coin[i-3];
    for (int mask = 0;mask< (1<<17) ; mask++)
    {
        int s1 = 0,s2 = 0;
        for (int i=0;i<17;i++)
            if (bit(i,mask))
            {
                s1 += coin[i+1];
                s2 += coin[i+18];
            }
        L[s1] = max(L[s1],1ll*__builtin_popcountll(mask));
        R[s2] = max(R[s2],1ll*__builtin_popcountll(mask));
    }
    int nTest; cin>>nTest;
    FOR(t,1,nTest)
    {
        cout<<"Case #"<<t<<": ";
        int n,ans = -1; cin>>n;
        for (auto it : L)
            if (it.first <= n && R.count(n-it.first)) 
            {
                auto pos = *R.find(n-it.first);
                ans = max(ans, it.second + pos.second);
            }
        cout<<ans<<"\n";
    }
}
