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

    auto is_op = [](string s) -> bool
    {
        if (!isdigit(s.back())) return true;
        return false;
    };

    auto process_op = [](stack<int> &st, string op,int type) -> void
    {
        int r = st.top();
        st.pop();
        int l = st.top();
        st.pop();
        if (type) swap(l,r);
        int val;
        if (op == "+") val = l + r;
        if (op == "-") val = l - r;
        if (op == "*") val = l * r;
        if (op == "/") val = l / r;
        st.push(val);
    };

    int tc; cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        vector<string> a(n+1);
        FOR(i,1,n) cin>>a[i];
        stack<int> st;
        FOD(i,n,1)
            if (!is_op(a[i]))
                st.push(stoll(a[i]));
            else
                process_op(st, a[i], 1);
        cout<<st.top()<<"\n";
    }
}
