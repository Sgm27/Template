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
struct DynamicDisjointSetDS{
    unordered_map<int, int> parent;
    int N;
    DynamicDisjointSetDS(int n)
    {
        N = n;
    }
    int getParent(int vertex)
    {
        if (parent.find(vertex) != parent.end()) {
            if (parent[vertex] != vertex) {
                parent[vertex] = getParent(parent[vertex]);
                return parent[vertex];
            }
        }
        else {
            parent.insert(make_pair(vertex, vertex));
        }
        return vertex;
    }
 
    void Union(int vertexA, int vertexB)
    {
        int x = getParent(vertexA);
        int y = getParent(vertexB);
        if (x == y)
            return;
        if (x > y) swap(x,y);
        parent[y] = x;
    }
    int GetTotalComponent()
    {
        unordered_set<int> total;
        for (auto itr = parent.begin();
            itr != parent.end(); itr++) {
            total.insert(getParent(itr->first));
        }
        return N - parent.size() + total.size();
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n; cin>>n;
    vector<pii> a(n+1);
    FOR(i,1,n) 
        cin>>a[i].first>>a[i].second;
    sort(NALL(a), [](pii a, pii b)
    {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    });
    DynamicDisjointSetDS dsu(1e9);
    int ans = 0;
    FOR(i,1,n)
    {
        int tmp = dsu.getParent(a[i].first);
        if (tmp)
        {
            ans += a[i].second;
            dsu.Union(tmp - 1, tmp);
        }
    }
    cout<<ans;
}
