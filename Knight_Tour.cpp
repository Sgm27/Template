#include<bits/stdc++.h>
#ifdef DS
    #include "debug.h"
#else 
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
int x,y,ans[9][9];
const int dx[] = {-2, -2, -1, -1,  1,  1,  2,  2};
const int dy[] = {-1,  1, -2,  2, -2,  2, -1,  1};

bool inside(int x,int y)
{
    if (x >= 1 && x <= 8 && y >= 1 && y <= 8) return 1;
    return 0;
}
int getDegree(int cur_x,int cur_y)
{
    int cnt = 0;
    FOR(k,0,7)
    {
        int xx = cur_x + dx[k];
        int yy = cur_y + dy[k];
        if (inside(xx,yy) && ans[xx][yy] == -1) cnt++;
    }
    return cnt;
}
pii getNext(int cur_x,int cur_y)
{
    int nxt_x = -1, nxt_y = -1, min_deg = INF;
    int st = rand() % 8;
    FOR(k,0,7)
    {
        int kk = (st + k) % 8;
        int xx = cur_x + dx[kk];
        int yy = cur_y + dy[kk];
        if (inside(xx,yy) && ans[xx][yy] == -1)
        {
            int deg = getDegree(xx,yy);
            if (deg < min_deg)
            {
                min_deg = deg;
                nxt_x = xx;
                nxt_y = yy;
            }
        } 
    }
    return {nxt_x, nxt_y};
}
bool genMap()
{
    memset(ans, -1, sizeof ans);
    int cur_x = x, cur_y = y;
    ans[cur_x][cur_y] = 1;
    FOR(i,1,63)
    {
        auto [nxt_x, nxt_y] = getNext(cur_x, cur_y);
        if (nxt_x == -1 && nxt_y == -1) return false;
        ans[nxt_x][nxt_y] = ans[cur_x][cur_y] + 1;
        cur_x = nxt_x;
        cur_y = nxt_y;
    }
    FOR(i,1,8)
    {
        FOR(j,1,8) cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
    return true;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    freopen("thu.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>y>>x;
    while (1)
        if (genMap()) break;
}
