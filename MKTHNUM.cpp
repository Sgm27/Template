#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
#define TIME "Time elapsed : " << (double)clock() / 1000 << " s"
#define pii pair<int, int>
#define maxn 100005
int n, q, a[maxn];
struct node
{
    int l, r, sum;
};
struct Persistent_IT
{
    int nver = 0; // number of version
    int root[maxn];
    vector<node> t;
    Persistent_IT(int sz)
    {
        t.resize(sz * (log2(sz) + 2));
    }
    void refine(int ver)
    {
        t[ver].sum = t[t[ver].l].sum + t[t[ver].r].sum;
        // update this version from left and right node
    }
    int update(int prev, int l, int r, int p, int val)
    {
        if (l == r)
        {
            ++nver;
            t[nver].sum += val;
            return nver;
        }
        int m = l + r >> 1;
        int cur = ++nver;
        if (p <= m)
        {
            t[cur].l = update(t[prev].l, l, m, p, val);
            t[cur].r = t[prev].r;
        }
        else
        {
            t[cur].l = t[prev].l;
            t[cur].r = update(t[prev].r, m + 1, r, p, val);
        }
        refine(cur);
        return cur;
    }
    int get(int cur, int prev, int l, int r, int k)
    {
        if (l == r)
            return l;
        int m = l + r >> 1;
        int count = t[t[cur].l].sum - t[t[prev].l].sum;
        // count is number of element added in the left node from prev->cur
        if (count >= k)
            return get(t[cur].l, t[prev].l, l, m, k);
        else
            return get(t[cur].r, t[prev].r, m + 1, r, k - count);
        // walking on tree
    }
};
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("thu.inp", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> q;
    vector<int> compress;
    Persistent_IT ST(n);
    FOR(i, 1, n)
    {
        cin >> a[i];
        compress.push_back(a[i]);
    }
    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
    FOR(i, 1, n)
    {
        int PosX = lower_bound(compress.begin(), compress.end(), a[i]) - compress.begin() + 1;
        ST.root[i] = ST.update(ST.root[i - 1], 1, n, PosX, 1);
    }
    FOR(i, 1, q)
    {
        int l, r, k;
        cin >> l >> r >> k;
        int Pos = ST.get(ST.root[r], ST.root[l - 1], 1, n, k);
        cout << compress[Pos - 1] << "\n";
    }
}
