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
using ld = long double;
const int base = 1e14;
int ch(ld x)
{
    return (int)(x * base);
}
vector<int> solve(int a,int b,int c)
{
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0) return {-1};
            else 
            return {};
        }
        else 
            return {ch((ld)(-c)/(ld)(b))};
    }
    else 
    {
        int delta = b*b - 4*a*c;
        if (delta < 0)
            return {};
        else
        if (delta == 0)
            return {ch((ld)(-b) / (ld)(2*a))};
        else
        {
            ld sqrt_delta = (ld)(sqrt(delta));
            return {ch((ld)(-b+sqrt_delta) / (ld)(2*a)), ch((ld)(-b-sqrt_delta) / (ld)(2*a))};
        }
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n; cin>>n;
    set<int> ans;
    bool check = 0;
    FOR(i,1,n)
    {
        int a,b,c; cin>>a>>b>>c;
        vi save = solve(a,b,c);
        for (int x : save)
            if (x == -1)
            {
                check = 1;
                break;
            }
            else 
                ans.insert(x);
        if (check) break;
    }
    if (check)
        cout<<-1;
    else 
        cout<<ans.size();
}