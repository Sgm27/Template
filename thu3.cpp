#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ii pair<int, int>
const int N = 1e6+5, M = 1e3+5, MOD = 1e9+7, inf = 1e18;
int n, m, x, y, res, test, cnt, sum, k;
int a[N], b[N], f[740][40][15];

void process() {
    ++cnt;
    for (int i = 1; i <= 3; ++i) ++f[cnt][0][a[i]];
    for (int i = 0; i <= 32; ++i) {
        for (int j = 1; j <= 9; ++j) if (f[cnt][i][j]) {
            x = j * 3;
            while (x) {
                y = x % 10;
                f[cnt][i + 1][y] += f[cnt][i][j];
                x /= 10;
            }
        }
    }
}

void bk(int i, int k) {
    for (int j = k; j <= 9; ++j) {
        a[i] = j;
        if (i == 3) process();
        else if (i < 3) bk(i + 1, a[i]);
    }
}

signed main() {
    freopen("thu.inp", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> test;
    bk(1, 1);
    while (test--) {
        cin >> n >> m;
        for (int i = 1; i <= 9; ++i) a[i] = 0; cnt = 0;
        for (int i = 1; i <= m; ++i) cin >> x, ++a[x];
        int i = 0;
        while (1) {
            ++i; x = 0; y = 0;
            for (int j = 1; j <= 9; ++j)
                if (f[i][n][j] == a[j]) ++x;
                else if (f[i][n][j] == a[j] + 1) ++y, res = j;
            if (x == 8 && y == 1) {
                cout << res << endl;
                break;
            }
        }
    }
}