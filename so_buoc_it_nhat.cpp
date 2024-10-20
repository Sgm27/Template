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
    int tc; cin>>tc;
    while (tc--)
    {
        int n,m; cin>>n>>m;

        auto inside = [&](int x,int y) -> bool
        {
            return (x >= 1 && y >= 1 && x <= n && y <= m);
        };

        vector<vi> a(n+1, vi(m+1));
        FOR(i,1,n)
            FOR(j,1,m) cin>>a[i][j];
        
        auto bfs = [&]() -> int
        {
            queue<pii> q;
            q.push({1,1});
            vector<vi> mark(n+1, vi(m+1, -1));
            mark[1][1] = 0;
            while (!q.empty())
            {
                auto [x,y] = q.front();
                q.pop();
                if (x < n)
                {
                    int xx = x + abs(a[x][y] - a[x+1][y]);
                    int yy = y;
                    if (inside(xx,yy) && mark[xx][yy] == -1) 
                    {
                        mark[xx][yy] = mark[x][y] + 1;
                        q.push({xx,yy});
                    }
                }
                if (y < m)
                {
                    int xx = x;
                    int yy = y + abs(a[x][y] - a[x][y+1]);
                    if (inside(xx,yy) && mark[xx][yy] == -1) 
                    {
                        mark[xx][yy] = mark[x][y] + 1;
                        q.push({xx,yy});
                    }
                }
                if (x < n && y < m)
                {
                    int xx = x + abs(a[x][y] - a[x+1][y+1]);
                    int yy = y + abs(a[x][y] - a[x+1][y+1]);
                    if (inside(xx,yy) && mark[xx][yy] == -1) 
                    {
                        mark[xx][yy] = mark[x][y] + 1;
                        q.push({xx,yy});
                    }
                }
            }
            return mark[n][m];
        };

        cout<<bfs()<<"\n";
    }
}
