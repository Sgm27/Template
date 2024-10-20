#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
#define TIME "Time elapsed : " << (double)clock() / 1000 << " s"
#define int long long
#define pii pair<int, int>
const int MOD = 1e9 + 7, INF = 9e18;
#define maxn 1000006
int n, q, a[maxn];
struct node
{
    int Min, sum;
} t[maxn * 4];
node Merge(node l, node r)
{
    node ans;
    ans.sum = l.sum + r.sum;
    if (a[l.Min] <= a[r.Min])
        ans.Min = l.Min;
    else
        ans.Min = r.Min;
    return ans;
}
void build(int id, int l, int r)
{
    if (l == r)
        return t[id] = {l, a[l]}, void();
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    t[id] = Merge(t[id * 2], t[id * 2 + 1]);
}
void update(int id, int l, int r, int p, int val)
{
    if (r < p || l > p)
        return;
    if (l == r)
    {
        a[p] = val;
        t[id] = {p, val};
        return;
    }
    int m = (l + r) / 2;
    update(id * 2, l, m, p, val);
    update(id * 2 + 1, m + 1, r, p, val);
    t[id] = Merge(t[id * 2], t[id * 2 + 1]);
}
int get_min(int id, int l, int r, int u, int v)
{
    if (r < u || l > v)
        return 0;
    if (l >= u && r <= v)
        return t[id].Min;
    int m = (l + r) / 2;
    int left = get_min(id * 2, l, m, u, v);
    int right = get_min(id * 2 + 1, m + 1, r, u, v);
    if (a[left] <= a[right])
        return left;
    return right;
}
int get_sum(int id, int l, int r, int u, int v)
{
    if (r < u || l > v)
        return 0;
    if (l >= u && r <= v)
        return t[id].sum;
    int m = (l + r) / 2;
    int left = get_sum(id * 2, l, m, u, v);
    int right = get_sum(id * 2 + 1, m + 1, r, u, v);
    return left + right;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("thu.inp", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> q;
    FOR(i, 1, n)
        cin >> a[i];
    a[0] = INF;
    build(1, 1, n);
    int bonus = 0;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int d;
            cin >> d;
            bonus += d;
            if (bonus > n)
                bonus %= n;
        }
        if (type == 2)
        {
            int s, t, p;
            cin >> s >> t >> p;
            s -= bonus;
            t -= bonus;
            if (s <= 0)
                s += n;
            if (t <= 0)
                t += n;
            if (s <= t)
            {
                int min_idx = get_min(1, 1, n, s, t);
                update(1, 1, n, min_idx, p);
            }
            else
            {
                int min_idx;
                int i1 = get_min(1, 1, n, s, n);
                int i2 = get_min(1, 1, n, 1, t);
                if (a[i1] <= a[i2])
                    min_idx = i1;
                else
                    min_idx = i2;
                update(1, 1, n, min_idx, p);
            }
        }
        if (type == 3)
        {
            int s, t, S = 0;
            cin >> s >> t;
            s -= bonus, t -= bonus;
            if (s <= 0)
                s += n;
            if (t <= 0)
                t += n;
            if (s <= t)
                S = get_sum(1, 1, n, s, t);
            else
                S = get_sum(1, 1, n, s, n) + get_sum(1, 1, n, 1, t);
            cout << S << "\n";
        }
    }
}
