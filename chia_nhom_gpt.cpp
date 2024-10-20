#include <iostream>
#include <cstring>

using namespace std;

const int N = 15;

int n, k;
int a[N];
int dp[N][N];

int sum(int l, int r) {
    int res = 0;
    for (int i = l; i <= r; i++) res += a[i];
    return res;
}

int main() {
	freopen("thu.inp","r",stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i && j <= k; j++) {
            for (int x = 1; x <= i && x <= j; x++) {
                if (sum(i-x+1, i) == sum(1, x)) dp[i][j] += dp[i-x][j-1];
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}
