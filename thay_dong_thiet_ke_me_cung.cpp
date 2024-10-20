#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=111539786,INF=4e18;
#define maxn 
int n,m,k,s;
int dp[105][15][1500];
map<pii,int> banned;
pii up_edge(int i,int j)
{
    pii ans; 
    ans.first = (m + 1) * (i-1) + j;
    ans.second = ans.first + 1;
    return ans;
}
pii down_edge(int i,int j)
{
    pii ans = up_edge(i,j);
    ans.first += (m+1);
    ans.second += (m+1);
    return ans;
}
pii left_edge(int i,int j)
{
    pii ans;
    ans.first = up_edge(i,j).first;
    ans.second = down_edge(i,j).first;
    return ans;
}
pii right_edge(int i,int j)
{
    pii ans;
    ans.first = left_edge(i,j).first + 1;
    ans.second = left_edge(i,j).second + 1;
    return ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m>>k>>s;
    FOR(i,1,s)
    {
        int x,y; cin>>x>>y;
        banned[up_edge(x,y)] = 1;
        banned[down_edge(x,y)] = 1;
        banned[left_edge(x,y)] = 1;
        banned[right_edge(x,y)] = 1;
    }
    FOR(i,1,n) 
    {
        banned[left_edge(i,1)] = 1;
        banned[right_edge(i,m)] = 1;
    }
    FOR(i,1,m)
    {
        banned[up_edge(1,i)] = 1;
        banned[down_edge(n,i)] = 1;
    }
    int e = s + 1 + k + (m + 1) * (n + 1) - 2;
    e -= banned.size();
    dp[0][0][0] = 1;
    int pre_i = 0, pre_j = 0;    
    FOR(i,1,n)
        FOR(j,1,m) 
        {
            int cnt = banned[down_edge(i,j)] + banned[right_edge(i,j)];
            if (cnt == 2)
                FOR(k,0,e) dp[i][j][k] = dp[pre_i][pre_j][k];
            if (cnt == 1)
                FOR(k,0,e) 
                {
                    if (k >= 1) dp[i][j][k] += dp[pre_i][pre_j][k-1];
                    dp[i][j][k] += dp[pre_i][pre_j][k];
                    dp[i][j][k] %= MOD;
                }
            if (cnt == 0)
                FOR(k,0,e)
                {
                    if (k >= 2) dp[i][j][k] += dp[pre_i][pre_j][k-2];
                    if (k >= 1) dp[i][j][k] += 2*dp[pre_i][pre_j][k-1];
                    dp[i][j][k] %= MOD;
                }
            pre_i = i, pre_j = j;
        }
    cout<<dp[n][m][e];
}
