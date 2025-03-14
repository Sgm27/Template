#include <bits/stdtr1c++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef DS
#include "debug.h"
#else
#define deb(...)
#endif
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn
struct Treap
{ /// hash = 96814
    int len;
    const int ADD = 1000010;
    const int MAXVAL = 1000000010;
    tr1::unordered_map<long long, int> mp; /// Change to int if only int in treap
    tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> T;

    Treap()
    {
        len = 0;
        T.clear(), mp.clear();
    }

    inline void clear()
    {
        len = 0;
        T.clear(), mp.clear();
    }

    inline void insert(long long x)
    {
        len++, x += MAXVAL;
        int c = mp[x]++;
        T.insert((x * ADD) + c);
    }

    inline void erase(long long x)
    {
        x += MAXVAL;
        int c = mp[x];
        if (c)
        {
            c--, mp[x]--, len--;
            T.erase((x * ADD) + c);
        }
    }

    /// 1-based index, returns the K'th element in the treap, -1 if none exists
    inline long long kth(int k)
    {
        if (k < 1 || k > len)
            return -1;
        auto it = T.find_by_order(--k);
        return ((*it) / ADD) - MAXVAL;
    }

    /// Count of value < x in treap
    inline int count(long long x)
    {
        x += MAXVAL;
        int c = mp[--x];
        return (T.order_of_key((x * ADD) + c));
    }

    /// Number of elements in treap
    inline int size()
    {
        return len;
    }
} ms; // ordered_multiset

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp", "r", stdin);
    // freopen("thu.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--)
    {
        string type;
        int val;
        cin >> type;
        if (type == "add")
        {
            cin >> val;
            ms.insert(val);
        }
        else if (type == "del")
        {
            cin >> val;
            ms.erase(val);
        }
        else
            cout << ms.kth((ms.size() + 1) / 2) << "\n";
    }
}
