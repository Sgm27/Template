#ifdef DS
    #include "debug.h"
#else 
    #include<bits/stdc++.h>
    #define deb(...) 
#endif
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define NALL(x) x.begin()+1,x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n; cin>>n;
    set<string> s;
    unordered_map<string, vector<string>> g;
    FOR(i,1,n)
    {
        string a,b,c;
        cin>>a>>b>>c;
        s.insert(a);
        s.insert(c);
        if (b == "<") g[a].push_back(c);
        else g[c].push_back(a);
    }

    unordered_map<string, int> color;
    function<bool(string)> find_cycle = [&](string u)
    {
        bool ans = true;
        color[u] = 1;
        for (auto v : g[u])
            if (color[v] == 0) ans &= find_cycle(v);
            else
            if (color[v] == 1) return false;
        color[u] = 2;
        return ans;
    };

    bool ans = true;
    for (auto it : s)
        if (color[it] == 0) ans &= find_cycle(it);
    cout<<(ans ? "possible" : "impossible");
}
