#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n,t[maxn*4],b[maxn],dp[maxn],max_prefix[maxn];
struct data{
    int st,ed;
    int sum()
    {
        return st+ed;
    }
    int time()
    {
        return ed-st;
    }
} a[maxn];
bool cmp(data a,data b)
{
    if (a.ed!=b.ed) return a.ed<b.ed;
    return a.st>b.st;
}
void update(int id,int l,int r,int p,int val)
{
    if (r<p || l>p) return;
    if (l==r)
    {
        t[id]=max(t[id],val);
        return;
    }
    int m=(l+r)/2;
    update(id*2,l,m,p,val);
    update(id*2+1,m+1,r,p,val);
    t[id]=max(t[id*2],t[id*2+1]);
}
int get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return -INF;
    if (l>=u && r<=v) return t[id];
    int m=(l+r)/2;
    int t1=get(id*2,l,m,u,v);
    int t2=get(id*2+1,m+1,r,u,v);
    return max(t1,t2);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    fill(t+1,t+1+4*n,-INF); 
    FOR(i,1,n) cin>>a[i].st>>a[i].ed;
    sort(a+1,a+1+n,cmp);
    FOR(i,1,n) b[i]=a[i].ed;
    int ans=0;
    FOR(i,1,n)
    {
        int k=upper_bound(b+1,b+1+n,a[i].st)-b-1;
        int right_val=get(1,1,n,k+1,i-1);
        dp[i]=max(max_prefix[k]+a[i].time(),right_val+a[i].sum());
        update(1,1,n,i,dp[i]-2*a[i].ed);
        max_prefix[i]=max(max_prefix[i-1],dp[i]);
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}
