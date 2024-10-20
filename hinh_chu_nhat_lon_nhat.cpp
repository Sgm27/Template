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
int find_max_area(const vi &a)
{
    int N = a.size() - 1;
    vi l(N+1), r(N+1);
    stack<int> st;
    FOR(i,1,N)
    {
        while (!st.empty() && a[i] <= a[st.top()]) st.pop();
        if (st.size()) l[i] = st.top() + 1;
        else l[i] = 1; 
        st.push(i);
    }
    st = stack<int>();
    FOD(i,N,1)
    {
        while (!st.empty() && a[i] <= a[st.top()]) st.pop();
        if (st.size()) r[i] = st.top() - 1;
        else r[i] = N;
        st.push(i);
    }

    int ans = -INF;
    FOR(i,1,N)
        ans = max(ans, a[i] * (r[i] - l[i] + 1));
    return ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        int n; cin>>n;	
        vi a(n+1);
        FOR(i,1,n) cin>>a[i];
        cout<<find_max_area(a)<<"\n";
    }
}
