#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nmax 100005
#define oo 1000000005
using namespace std;
int n, m, s = 0, ans = 0;
vector<int> dp(nmax);
vector<vector<int> > a(nmax);
int dfs(int u)
{
    if(dp[u]) return dp[u];
    for(int v : a[u]){
        dp[v] = dfs(v);
        dp[u] = max(dp[v] + 1, dp[u]);
    }
    return dp[u];
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    m=n-1;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        a[x].pb(y);
    }
    for(int i = 1; i <= n; i++) dfs(i);
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
