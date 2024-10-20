#include<bits/stdc++.h>
using namespace std;

const int N = 35;

int n, S, t[N];
int ans = INT_MAX;

bool check(int x) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (t[i] > x) {
            return false;
        }
        if (sum + t[i] > x) {
            sum = t[i];
        } else {
            sum += t[i];
        }
    }
    return sum <= x;
}

int main() {
	freopen("thu.inp","r",stdin);
    cin >> n >> S;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    int l = 0, r = S;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}
