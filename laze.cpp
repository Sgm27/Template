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
int sx,sy,ex,ey;
int n; 
map<int, vector<pii>> gx,gy;
map<int,int> mx,my; 
map<pii,int> visited;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>sx>>sy>>ex>>ey;
    FOR(i,1,n)
    {
        int x,y; cin>>x>>y;
        gx[x].push_back({x,y});
        gy[y].push_back({x,y});
    }
    if (sx == sy && ex == ey)  
        return cout<<0, 0;
    gx[ex].push_back({ex,ey});
    gy[ey].push_back({ex,ey});
    queue<pii> q;
    q.push({sx,sy});
    visited.insert({{sx,sy}, 0});
    while (!q.empty())
    {
        auto [x,y] = q.front();
        deb(x,y, visited[{x,y}])
        q.pop();
        if (mx[x] == 0)
        {
            mx[x] = 1;
            for (auto [xx,yy] : gx[x]) 
                if (visited.find({xx,yy}) == visited.end()) 
                {
                    q.push({xx,yy});
                    visited.insert({{xx,yy}, visited[{x,y}] + 1});
                }
        }
        if (my[y] == 0)
        {
            my[y] = 1;
            for (auto [xx,yy] : gy[y])
                if (visited.find({xx,yy}) == visited.end()) 
                {
                    q.push({xx,yy});
                    visited.insert({{xx,yy}, visited[{x,y}] + 1});
                }
        }
    }

    if (visited.find({ex,ey}) == visited.end()) cout<<"-1";
    else cout<<visited[{ex,ey}] - 1;
}
