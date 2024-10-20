#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18, BLOCK_SZ = 512;
#define maxn 200005
int n,a[maxn],q;
int Sum[maxn / BLOCK_SZ + 2];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    FOR(i,1,n)
    {
        cin>>a[i];
        Sum[i / BLOCK_SZ] += a[i];
    }
    while (q--)
    {
        int type; cin>>type;
        if (type == 1)
        {
            int k,u;
            cin>>k>>u;
            Sum[k / BLOCK_SZ] += u - a[k];
            a[k] = u;
        }
        else
        {
            int u,v,ans = 0; cin>>u>>v;
            int L = u / BLOCK_SZ + 1;
            int R = v / BLOCK_SZ - 1;
            FOR(i,L,R) ans += Sum[i];
            if (u / BLOCK_SZ != v / BLOCK_SZ)
            {
                for (int i=u;i<L * BLOCK_SZ;i++) ans += a[i];
                for (int i=(R+1) * BLOCK_SZ;i<=v;i++) ans += a[i];
            }
            else
                for (int i=u;i<=v;i++) ans += a[i];
            cout<<ans<<"\n";
        }
    }
}
