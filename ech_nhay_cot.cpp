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
    int n,m; cin>>n>>m;
    vi a(n+1);
    FOR(i,1,n) cin>>a[i];
    vi nxt(n+1);
    stack<int> st;
    FOD(i,n,1)
    {
        while (st.size() && a[i] >= a[st.top()]) st.pop();
        if (st.size()) nxt[i] = st.top();
        else nxt[i] = n+1;
        st.push(i);
    }
    vi dp(n+2);
    FOD(i,n,1) 
        dp[i] = dp[nxt[i]] + 1;
    while (m--)
    {
        int x; cin>>x;
        cout<<dp[x] - 1<<"\n";
    }
}
