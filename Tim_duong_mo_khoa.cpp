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
#define maxn 55
int n,m,k;
char a[maxn][maxn];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

struct Data{
    int px,py;
    vi state;
    Data()
    {
        state.assign(5, 0);
    }
    Data(int _px,int _py,vi _state)
    {
        px = _px;
        py = _py;
        state = _state;
    }
};
int get_idx(char c)
{
    if (islower(c)) return c - 'a';
    return c - 'A';
}
bool end_state(const vi &a)
{
    FOR(i,0,k-1)
        if (a[i] != 2) return false;
    return true;
}
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
        cin>>n>>m>>k;
        FOR(i,1,n)
            FOR(j,1,m) cin>>a[i][j];
        auto inside = [&](int x,int y) -> bool
        {
            if (x >= 1 && x <= n && y >= 1 && y <= m) return true;
            return false;
        };
        queue<pair<Data, int>> q;
        set<pair<pair<int,int>,vector<int>>> mark;
        vi st(5,0);
        assert(!isalpha(a[1][1]));
        if (islower(a[1][1])) st[get_idx(a[1][1])] = 1;
        q.push(make_pair(Data(1, 1, st), 0));
        mark.insert(make_pair(make_pair(1,1), st));
        int ans = INF;
        while (!q.empty())
        {
            auto x = q.front();
            q.pop();
            FOR(p,0,3)
            {
                int xx = x.first.px + dx[p];
                int yy = x.first.py + dy[p];
                if (inside(xx,yy) && a[xx][yy] != '#')
                {
                    Data newx = Data(xx, yy, x.first.state);
                    if (a[xx][yy] == '.')
                    {
                        if (!mark.count(make_pair(make_pair(xx, yy), newx.state)))
                        {
                            mark.insert(make_pair(make_pair(xx, yy), newx.state));
                            q.push(make_pair(newx, x.second+1));
                        }
                    }
                    else
                    {
                        int idx = get_idx(a[xx][yy]);
                        vi tmp = x.first.state;
                        if (islower(a[xx][yy]))
                        {
                            if (tmp[idx] != 0) continue;
                            tmp[idx]++;
                            newx.state = tmp;
                            if (!mark.count(make_pair(make_pair(xx, yy), newx.state))) 
                            {
                                mark.insert(make_pair(make_pair(xx, yy), newx.state));
                                q.push(make_pair(newx, x.second+1));
                            }
                        }
                        else
                        {
                            if (tmp[idx] == 1)
                            {
                                tmp[idx]++;
                                newx.state = tmp;
                                if (!mark.count(make_pair(make_pair(xx, yy), newx.state)))
                                {
                                    if (end_state(newx.state)) 
                                    {
                                        ans = min(ans, x.second + 1);
                                        // break;
                                    }
                                    mark.insert(make_pair(make_pair(xx, yy), newx.state));
                                    q.push(make_pair(newx, x.second+1));
                                }
                            }
                        }
                    }
                }
            }
            // if (ans != INF) break;
        }
        cout<<(ans == INF ? -1 : ans)<<"\n";
    }
}
