#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 200005
int n,a[maxn],k,pos[maxn];
struct Fenwick{
    vector<int> t;
    Fenwick ()
    {
        t.resize(maxn);
    }
    void update(int x,int val)
    {
        for (;x>0;x-=x&-x) t[x]+=val;
    }
    int get(int x,int limit)
    {
        int ans=0;
        for (;x<=limit;x+=x&-x) ans+=t[x];
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
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>k;
        Fenwick	fw;
        FOR(i,1,n) 
        {
            pos[i]=n-i+1;
            fw.update(i-1,1);
        }
        while (k--)
        {
            int x; cin>>x;
            cout<<fw.get(pos[x],n)<<" ";
            fw.update(pos[x],-1);
            pos[x]=++n;
            fw.update(pos[x]-1,1);
        }
        cout<<"\n";
    }
}
