#ifdef DS
    #include "debug.h"
#else 
    #include<bits/stdc++.h>
    #define deb(...) 
#endif
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define NALL(x) x.begin()+1,x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n; cin>>n;
    vector<vi> a(n+1, vi(n+1));
    FOR(i,1,n)
        FOR(j,1,n) cin>>a[i][j];
    vi visited(n+1, 0);
    function<void(int,int)> dfs = [&](int u,int p) 
    {
        cout<<u<<"("<<p<<"); ";
        visited[u] = 1;
        for (int v = 1; v <= n; v++)
            if (a[u][v] == 1 && visited[v] == 0) dfs(v,u);
    };

    FOR(i,1,n)
    {
        cout<<"DFS("<<i<<") = ";
        visited.assign(n+1, 0);
        dfs(i,0);
        cout<<"\n";
    }
}

/*

10 
0	0 	0   1	0	0	0	0	0	1
0	0 	0   1	0	0	0	0	0	0
0	0	0	0	0	0	0	1	1	0
0	1	0	0	0	0	0	0	0	1
0	0	0	0	0	1	1	0	0	0
0	0	0	0	1	0	1	1	0	0
0	0	1	0	0	0	0	1	1	0
0	0	0	0	1	1	1	0	1	0
0	0	0	0	1	0	0	1	0	0
1	1	0	0	0	0	0	0	0	0

*/