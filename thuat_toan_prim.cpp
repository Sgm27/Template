#include "debug.h"
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
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,s;
    cin>>n>>s;
    vector<vi> a(n+1, vi(n+1));
    FOR(i,1,n)
        FOR(j,1,n) cin>>a[i][j];
    vi d(n+1, INF), vs(n+1, 0), trace(n+1, 0);
    d[s] = 0;
    int step = 1;
    int WT = 0;
    vector<pii> T;
    while (1)
    {
        int u = 0, dmin = INF;
        FOR(i,1,n)
            if (vs[i] == 0 && d[i] < dmin)
            {
                dmin = d[i];
                u = i;
            }
        if (u == 0) break;
        vs[u] = 1;
        WT += d[u];
        if (trace[u] != 0)
            T.push_back({min(trace[u], u), max(trace[u], u)});
        FOR(v,1,n)
            if (a[u][v] != -1 && d[v] > a[u][v])
            {
                d[v] = a[u][v];
                trace[v] = u;
            }
        cout<<"Buoc "<<step++<<":\n";
        FOR(i,1,n)
        {
            cout<<"(";
            if (d[i] == INF) cout<<"vc";
            else cout<<d[i];
            cout<<"|";
            if (trace[i] == 0) 
            {
                if (i == s) cout<<0;
                else cout<<s;
            }
            else 
                cout<<trace[i];
            cout<<")";
            cout<<" ";
        }
        cout<<"WT = "<<WT<<"\n";
    }
    cout<<"Cay khung T tim duoc theo thuat toan Prim la:\n";
    cout<<"T = ";
    for (auto it : T)
        cout<<"("<<it.first<<", "<<it.second<<"); ";
}
/*

10 1
0	4	1	1	2	9	-1	5	4	7
4	0	2	-1	9	1	5	-1	6	-1
1	2	0	7	-1	6	6	1	1	9
1	-1	7	0	1	7	-1	6	-1	-1
2	9	-1	1	0	3	4	3	1	2
9	1	6	7	3	0	3	1	1	5
-1	5	6	-1	4	3	0	4	5	-1
5	-1	1	6	3	1	4	0	4	2
4	6	1	-1	1	1	5	4	0	4
7	-1	9	-1	2	5	-1	2	4	0

*/