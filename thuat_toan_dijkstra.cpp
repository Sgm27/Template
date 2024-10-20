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
        FOR(v,1,n)
            if (a[u][v] != -1 && d[v] > d[u] + a[u][v])
            {
                d[v] = d[u] + a[u][v];
                trace[v] = u;
            }
        cout<<"Buoc "<<step++<<":\n";
        cout<<"Dinh duoc gan nhan: "<<u<<"\n";
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
        cout<<"\n";
    }

    auto tracing = [&](int u) -> void
    {
        if (d[u] == INF)
        {
            cout<<"Khong ton tai duong di tu "<<s<<" den "<<u<<"!\n";
            return;
        }
        cout<<"Do dai duong di ngan nhat tu "<<s<<" den "<<u<<" la: "<<d[u]<<"\n";
        vi path;
        while (u != 0)
        {
            path.push_back(u);
            u = trace[u];
        }
        reverse(ALL(path));
        cout<<"Duong di: ";
        for (int i : path) cout<<i<<" ";
        cout<<"\n";
    };

    FOR(i,1,n) tracing(i);
}
/*

7 1 
0	20	5	17	-1	-1	-1
20	0	-1	1	-1	-1	1
5	-1	0	25	3	10	-1
17	1	25	0	15	-1	-1
-1	-1	3	15	0	1	-1
-1	-1	10	-1	1	0	1
-1	1	-1	-1	-1	1	0

*/