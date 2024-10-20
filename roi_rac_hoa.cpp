#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int n,a[maxn],b[maxn];
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    int m = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
}

