#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
template <typename T> using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    order_set<int> se;
    int q; cin>>q;
    while (q--)
    {
        char type; int val;
        cin>>type>>val;
        if (type == 'I') se.insert(val);
        if (type == 'D') se.erase(val);
        if (type == 'C') 
            cout<<se.order_of_key(val)<<"\n";
        if (type == 'K')
        {
            if (val > se.size()) cout<<"invalid\n";
            else
            cout<<*se.find_by_order(val-1)<<"\n";
        }
    }
}
