#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e9;
#define maxn 105
int d[maxn][maxn];
int n,a[5];
void floyd()
{
    FOR(k,1,n)
        FOR(i,1,n)
            FOR(j,1,n)
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(u,1,n)
        FOR(v,1,n) 
        {
            d[u][v] = INF;
            if (u == v) d[u][v] = 0;
        }
    FOR(i,1,4) cin>>a[i];
    int u,v,w;
    while (cin>>u>>v>>w) 
    {
        d[u][v] = min(d[u][v],w);
        d[v][u] = min(d[v][u],w);
    }
    floyd();
    int ans = INF;
    sort(a+1,a+5);
    do
    {
        FOR(u,1,n)
            FOR(v,1,n)
            {
                int cost = d[u][v] + d[u][a[1]] + d[u][a[2]] + d[v][a[3]] + d[v][a[4]];
                ans = min(ans,cost);
            }
    } while (next_permutation(a+1,a+5));
    cout<<ans;
}
