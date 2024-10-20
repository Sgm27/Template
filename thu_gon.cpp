#include <bits/stdc++.h>
using namespace std;

int t, n, cnt;

int main () {
	freopen("thu.inp","r",stdin);
    cin >> t;
    while (t--) {
        cin >> n;
        cnt = 1;
        while (n > 1) {
            if (cnt % 2 == 1) n = (n + 1) / 2;
            else n = n / 2;
            cnt++;
        }
        cout << n << endl;
    }
    return 0;
}
