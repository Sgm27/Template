#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
#define maxn 100005
#define max_val 10000000
vector<pii> val[max_val + 2];
int n,a[maxn],pos_idx[max_val + 2],have[max_val + 2];
int upper[max_val + 2];
struct DSU {
	vector<int> e; void init(int N) { e = vector<int>(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};
void solve()
{
    DSU dsu;
    dsu.init(n+5);
    FOR(i,1,n) have[a[i]] = 1, pos_idx[a[i]] = i;
    FOD(i,max_val,1) 
        if (have[i]) upper[i] = i;
        else upper[i] = upper[i+1]; 
    FOR(i,1,n)
    {
        int next_first = upper[a[i] + 1];
        if (have[next_first] && next_first - a[i] < a[i]) 
            val[next_first - a[i]].push_back({i,pos_idx[next_first]});
        for (int j = a[i] * 2;j<=max_val;j+=a[i])
        {
            if (!have[upper[j]]) break;
            if (upper[j] - j < a[i]) 
                val[upper[j] - j].push_back({i,pos_idx[upper[j]]});
        }
    }
    int ans = 0, cnt = 0;
    FOR(w,0,max_val)
    {
        for (pii e : val[w])
        {
            if (dsu.unite(e.first,e.second))
            {
                ans += w;
                cnt++;
            }
            if (cnt == n-1) break;
        }
        if (cnt == n-1) break;
    }
    cout<<ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    int _sz = unique(a+1,a+1+n) - a - 1;
    n = _sz;
    solve();    
}
