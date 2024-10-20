//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x > y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "minpath"
#define maxn 100005
#define MOD 1000000007
#define maxc 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

int n, m, s, t;
vector < pii > ke[maxn];
int d[maxn], tr[maxn];
bool dd[maxn];

void Read()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ke[u].PB(mp(v,w));
        ke[v].PB(mp(u,w));
    }
}

void Fordbellman()
{
    fill(d, d+n+1, maxc);
    d[s] = 0;
    while (1){
            int stop = true;
            for (int u = 1; u <= n; u++)
                for (int i = 0; i < ke[u].size(); i++)
                {
                    int v = ke[u][i].first;
                    int w = ke[u][i].second;
                    if (d[v] > d[u] + w)
                        {
                            d[v] = d[u] + w;
                            stop = false;
                        }
                }
            if (stop) break;
    }
}

void Write()
{
    cout << d[t] << endl;

}

int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    Read();
    Fordbellman();
    //IJK();
    Write();
    return 0;
}

