#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 1000006
int n,a[maxn],q;
struct Fenwick{
    vector<int> t;
    int n;
    Fenwick(int sz)
    {
        n=sz;
        t.resize(n+1);
    }
    void update(int x,int val)
    {
        for (;x<=n;x+=x&-x) t[x]+=val;
    }
    int get(int x)
    {
        int ans=0;
        for (;x>0;x-=x&-x) ans+=t[x];
        return ans;
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    Fenwick fw(n);
    while (q--)
    {
        string type;
        int u,v;
        cin>>type>>u>>v;
        if (type=="find") 
            cout<<fw.get(v)-fw.get(u-1)<<"\n";
        else
            fw.update(u,v);
    }
}
