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
    int n,k; cin>>n>>k;
    vi x(30);
    x[0] = 1;
    function<void(int)> Try = [&](int i)
    {
        FOR(j,x[i-1],n)
        {
            x[i] = j;
            if (i == k)
            {
                FOR(kk,1,k) cout<<x[kk]<<" ";
                cout<<"\n";
            }
            else
                Try(i+1);
        }
    };
    Try(1);
}
