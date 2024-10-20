#include <bits/stdc++.h>
using namespace std;

int t, n, a[1005], b[1005], g[1005];

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int main() {
		freopen("thu.inp","r",stdin);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        b[0] = a[0];
        g[0] = a[0];
        for (int i = 1; i < n; i++) {
            g[i] = gcd(a[i], g[i - 1]);
            b[i] = a[i] * b[i - 1] / g[i];
        }
        b[n] = b[n - 1];
        for (int i = 0; i <= n; i++) cout << b[i] << " ";
        cout << endl;
    }
    return 0;
}
