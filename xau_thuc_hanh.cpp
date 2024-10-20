#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0 || j == 0) dp[i][j] = 1;
            else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
                if(a[i-1] != b[j-1]) dp[i][j] = (dp[i][j] - dp[i-1][j-1] + MOD) % MOD;
            }
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}