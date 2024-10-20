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
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=1e9;
#define maxn 1003
#define bit(i,n) (n >> i & 1)
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int n,m; 
int f[maxn][maxn];
char a[maxn][maxn];
int cost[20][20];
int dp[10][1 << 10];
int nearest[20];
vector<pii> A_point;

bool valid(int i,int j)
{
    if (i >= 1 && j >= 1 && i <= n && j <= m && a[i][j] != '#') return true;
    return false;
};

int vs[maxn][maxn];
void make_cost(int x,int y,int idx)
{
    FOR(i,1,n)
        FOR(j,1,m) 
        {
            f[i][j] = INF;
            vs[i][j] = 0;
        }
    f[x][y] = 0;
    vs[x][y] = 1;
    queue<pii> q;
    q.push({x,y});
    while (q.size())
    {
        auto [i,j] = q.front();
        q.pop();
        FOR(k,0,3)
        {
            int xx = i + dx[k];
            int yy = j + dy[k];
            if (!valid(xx,yy)) continue;
            if (vs[xx][yy] == 0)
            {
                f[xx][yy] = f[i][j] + 1;
                vs[xx][yy] = 1;
                q.push({xx,yy});
                if (a[xx][yy] == 'D')
                    nearest[idx] = min(nearest[idx], f[xx][yy]);
            }
        }
    }
    FOR(i,0,A_point.size()-1)
        cost[idx][i] = f[A_point[i].first][A_point[i].second];
}



signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    FOR(i,1,n)
        FOR(j,1,m)
        {
            char c; cin>>c;
            a[i][j] = c;
            if (c == 'A') A_point.push_back({i,j});
        }
    for (int i = 0; i < A_point.size(); i++) nearest[i] = INF;
    for (int i = 0; i < A_point.size(); i++)
        make_cost(A_point[i].first, A_point[i].second, i);

    for (int i = 0; i < A_point.size(); i++)
        for (int j = 0; j < A_point.size(); j++)
            cost[i][j] = min(cost[i][j], nearest[i] + nearest[j]);

    int N = A_point.size();
    int ans = INF;
    for (int start = 0; start < N; start++)
    {
        for (int i = 0; i < N; i++)
            for (int mask = 0; mask < (1 << N); mask++) dp[i][mask] = INF;

        dp[start][1<<start] = 0;

        for (int mask = 0; mask < (1 << N); mask++)
        {
            if (bit(start,mask) == 0) continue;
            for (int i = 0; i < N; i++)
            {
                if (i == start) continue;
                if (!bit(i,mask)) continue;
                int pre_mask = mask - (1 << i);
                for (int j = 0; j < N; j++)
                    if (bit(j, pre_mask) && cost[j][i] != INF)
                        dp[i][mask] = min(dp[i][mask], dp[j][pre_mask] + cost[j][i]);
            }
        }
        for (int i = 0; i < N; i++)
            ans = min(ans, dp[i][(1 << N) - 1]);
    }
    if (ans != INF)
        cout<<ans;
    else 
        cout<<"-1";
}
