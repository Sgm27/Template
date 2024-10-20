//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) {if (x > (y)) x = (y)}
#define MAX(x,y) {if (x < (y)) x = (y)}
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "cbridge"
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;
int n, m, par[maxn];
vector <int> a[maxn];
int id[maxn], low[maxn], cnt = 0;
vector <pii> res;

void DFS(int u){
	low[u] = id[u] = ++ cnt;
	
	for (int v : a[u])		
	{
		if (v == par[u]) continue;
		if (id[v]) low[u] = min(low[u], id[v]);
			else {
				par[v] = u;
				DFS(v);
				low[u] = min(low[u], low[v]);				
				if (low[v] == id[v]) 
					res.PB({min(u,v), max(u,v)});
			}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
   freopen("thu.inp", "r", stdin);
//    freopen(Task".out", "w", stdout);
    cin >> n;
	for (int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			int x; cin>>x;
			if(x) 
				a[i].push_back(j);
		}
    for (int i = 1; i <= n; i++)
        if (!par[i]){
            par[i] = -1;
            DFS(i);
        }
	cout << res.size() << '\n';
	sort(res.begin(), res.end());
	for ( pii x : res) cout << x.F << " " << x.S << '\n';
    return 0;
}

