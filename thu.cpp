#include "bits/stdc++.h"
using namespace std;
#define int long long

struct dt{
    int t,v;
};

signed main(){
    int n; cin>>n;
    vector<dt> a(n);
    for (int i=0; i<n; i++) cin>>a[i].t>>a[i].v;
    sort(a.begin(),a.end(),[](dt a, dt b)
    {
        if (a.v != b.v) return a.v > b.v;
        return a.t < b.t;
    });
    int ans = 0;
    set<int> not_selected;
    for (int i = 1; i <= n; i++) not_selected.insert(i);
    for (dt x : a)
    {
        auto it = not_selected.lower_bound(x.t);
        if (it == not_selected.end()) continue;
        ans += x.v;
        not_selected.erase(it);
    }
    cout<<ans;
}
