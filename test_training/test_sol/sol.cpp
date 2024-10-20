#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
int n, cnt_odd[maxn], cnt_even[maxn];
long long get_ans(int l, int r)
{
    int nodd = cnt_odd[r] - cnt_odd[l - 1];
    int neven = cnt_even[r] - cnt_even[l - 1];
    return 1LL * (nodd) * (nodd - 1) / 2 * (neven) + 1LL * (neven) * (neven - 1) * (neven - 2) / 6;
}
int main()
{
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x % 2)
        {
            cnt_odd[i] = cnt_odd[i - 1] + 1;
            cnt_even[i] = cnt_even[i - 1];
        }
        else
        {
            cnt_odd[i] = cnt_odd[i - 1];
            cnt_even[i] = cnt_even[i - 1] + 1;
        }
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << get_ans(l, r) << "\n";
    }
}