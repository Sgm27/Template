#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 30004
int n,a[maxn],f[maxn],b[maxn];

struct Fenwick{
    vector<int> t;
    Fenwick(int n)
    {
        t.resize(n+1);
    }
    void update(int x,int val)
    {
        for(;x<=n;x+=x&-x) t[x]=max(t[x],val);
    }
    int get(int x)
    {
        int ans=0;
        for(;x>0;x-=x&-x) ans=max(ans,t[x]);
        return ans;
    }
};

void compression(int a[])
{
    FOR(i,1,n) b[i]=a[i];
    sort(b+1,b+1+n);
    int m=unique(b+1,b+1+n)-b-1;
    FOR(i,1,n)
        a[i]=lower_bound(b+1,b+1+m,a[i])-b;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    compression(a);
    Fenwick fw(n);
    FOR(i,1,n)
    {
        f[i]=fw.get(a[i]-1)+1;
        fw.update(a[i],f[i]);
    }
    cout<<*max_element(f+1,f+1+n);
}
