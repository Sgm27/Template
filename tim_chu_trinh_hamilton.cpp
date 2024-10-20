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
#define maxn 100
int a[maxn][maxn],n,s;
int x[maxn];
int vs[maxn];
void Hamilton(int k)
{
    if (k == n+1)
    {
        if (a[x[k-1]][x[1]] == 1)
        {
            for (int i = 1; i <= n; i++) cout<<x[i]<<" ";
            cout<<x[1]<<"\n";
        }
        return;       
    }
    for (int i = 1; i <= n; i++)
        if (a[x[k-1]][i] == 1 && vs[i] == 0) 
        {
            vs[i] = 1;
            x[k] = i;
            Hamilton(k+1);
            vs[i] = 0;
        }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>s;
    FOR(i,1,n)
        FOR(j,1,n) cin>>a[i][j];
    vs[s] = 1;
    x[1] = s;
    cout<<"Cac chu trinh Hamilton tim duoc la:\n";
    Hamilton(2);    
}
