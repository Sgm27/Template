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
const int MOD=1e9+7,INF=1e9;
#define maxn 
int dx[8]={-1,0,1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,1,-1};

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
        int sx,sy,ex,ey;
        cin>>sx>>sy>>ex>>ey;
        int n; cin>>n;
        map<pii,int> line;
        FOR(i,1,n)
        {
            int x,yy1,yy2; 
            cin>>x>>yy1>>yy2;
            FOR(j,yy1,yy2) line[{x,j}] = 1;
        }

        auto inside = [](int x,int y) -> bool
        {
            return (x >= 0 && x <= INF && y >= 0 && y <= INF);
        };

        queue<pair<pii,int>> q;
        q.push({{sx,sy}, 0});
        int ans = INF;
        while (!q.empty())
        {
            auto [it, step] = q.front();
            q.pop();
            FOR(k,0,7)
            {
                int xx = it.first + dx[k];
                int yy = it.second + dy[k];
                if (inside(xx, yy) && line.find({xx, yy}) != line.end()) 
                {
                    if (xx == ex && yy == ey) 
                    {
                        ans = step + 1;
                        break;
                    }
                    line.erase({xx, yy});
                    q.push({{xx,yy}, step+1});
                }
            }
            if (ans != INF) break; 
        }

        cout<<(ans == INF ? -1 : ans)<<"\n";
    }
}
