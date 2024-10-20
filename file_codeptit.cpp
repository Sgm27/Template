#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define TASK "DATA"
const int MOD=1e9+7,INF=4e18;
#define maxn 
// ofstream os(TASK"1.out");
ifstream in1(TASK".in");
ifstream in2(TASK"2.in");
// #define cout os
#define cin in1
#define cin2 in2

int check(string s)
{
    for (char c : s) 
        if (!isdigit(c)) return 0;
    if (s.length() <= 10) return stoll(s);
    return 0;
}
signed main()
{
    // #ifndef ONLINE_JUDGE
    // freopen(TASK".in","r",stdin);
    // freopen(TASK".out","w",stdout);
    // #endif
    int n,m; cin>>n>>m;
    set<int> SA,SB,ans;
    FOR(i,1,n)
    {
        int x; cin>>x;
        SA.insert(x);
    }
    FOR(i,1,m)
    {
        int x; cin>>x;
        SB.insert(x);
    }
    for (int x : SA)
        if (SB.count(x)) ans.insert(x);
    for (int x : ans) cout<<x<<" ";
}
