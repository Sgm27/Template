#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 1000006
int n,a[maxn],b[maxn],f1[maxn],f2[maxn],last_end_pos[maxn],last_first_pos[maxn];

struct Fenwick{
    vector<int> t;
    Fenwick(int n)
    {
        t.resize(n+1);
    }
    void update(int x)
    {
        for(;x<=n;x+=x&-x) t[x]++;
    }
    int get(int x)
    {
        int ans=0;
        for(;x>0;x-=x&-x) ans+=t[x];
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

void calc_f()
{
    FOR(i,1,n)
    {
        f1[i]=f1[last_first_pos[a[i]]]+1;
        last_first_pos[a[i]]=i;
    }
    FOD(i,n,1)
    {
        f2[i]=f2[last_end_pos[a[i]]]+1;
        last_end_pos[a[i]]=i;
    }
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
    calc_f();
    int ans=0;
    FOD(i,n,1)
    {
        ans+=fw.get(f1[i]-1);
        fw.update(f2[i]);
    }
    cout<<ans;
}
