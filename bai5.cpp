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

void solve(int n)
{
    queue<string> q; 
    n /= 2;
    q.push("0");
    q.push("1");
    vector<string> ans;
    while (!q.empty())
    {
        string cur = q.front();
        q.pop();
        string tmp = cur;
        reverse(ALL(tmp));
        ans.push_back(cur + tmp);
        if (cur.size() < n)
        {
            q.push(cur + '0');
            q.push(cur + '1');
        }
    }
    sort(ALL(ans), [](string &a,string &b)
    {
        if (a.length() != b.length())
            return a.length() < b.length();
        return a < b;
    });
    for (auto it : ans)
        cout<<it<<" ";
    cout<<"\n";
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
        solve(n);
    }
}
