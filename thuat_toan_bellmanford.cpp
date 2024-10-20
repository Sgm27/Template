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
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,s; cin>>n>>s;
    vector<vi> a(n+1, vi(n+1));
    FOR(i,1,n)
        FOR(j,1,n) cin>>a[i][j];
    vi d(n+1);
    vi trace(n+1, -1);
    FOR(i,1,n) 
    {
        d[i] = a[s][i];
        if (d[i] != 1000 && i != s) trace[i] = s;
    } 
    bool ok = true;
    FOR(i,1,n-1)
    {
        ok = true;
        FOR(u,1,n)
            FOR(v,1,n) 
            {
                if (a[v][u] == 1000) continue; 
                if (d[v] != 1000 && d[u] > d[v] + a[v][u])
                {
                    d[u] = d[v] + a[v][u];
                    trace[u] = v;
                    ok = false;
                }
            }
        if (ok) 
        {
            cout<<"end in : "<<i<<"\n";
            break;
        }
        cout<<"Buoc "<<i<<": ";
        FOR(x,1,n) cout<<d[x]<<" ";
        cout<<"\n";
    }
    FOR(i,1,n)
    {
        if (d[i] == 1000)
        {
            cout<<"Khong ton tai duong di tu "<<s<<" den "<<i<<"\n";
            continue;
        }
        cout<<"Duong di ngan nhat tu "<<s<<" den "<<i<<" la: "<<d[i]<<"\n";
        int cur = i;
        vi path;
        while (cur != -1)
        {
            path.push_back(cur);
            cur = trace[cur];
        }
        reverse(ALL(path));
        cout<<"Duong di : ";
        for (auto it : path) cout<<it<<" ";
        cout<<"\n";
    }
}
/*
    8 1
    0 1000 1000 1000 2 1000 1 1000
    1000 0 -1 1000 1000 1000 1000 1000
    1000 1000 0 1000 1000 1 1000 2
    -1 1000 1000 0 1000 1000 1000 1000
    1000 1000 1000 1 0 1000 2 1000
    1000 2 1000 1000 1000 0 1000 1
    1000 2 1000 1000 1000 -1 0 1000
    1000 1000 1000 1 2 1000 1000 0 
*/