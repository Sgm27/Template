#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 10004
#define MOD 5000000
int a[maxn],b[maxn],n,k,fw[maxn],dp[55][maxn];
void compression()
{
    sort(b+1,b+1+n);
    int m=unique(b+1,b+1+n)-b-1;
    FOR(i,1,n)
        a[i]=lower_bound(b+1,b+1+m,a[i])-b;
}
void update(int x,int val)
{
    for(;x<=n;x+=x&-x) (fw[x]+=val)%=MOD;
}
int get(int x)
{
    int ans=0;
    for(;x>0;x-=x&-x) ans+=fw[x];
    return ans%MOD;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    FOR(i,1,n) cin>>a[i], b[i]=a[i], dp[1][i]=1;
    compression();
    FOR(p,2,k)
    {
        memset(fw,0,sizeof(fw));
        FOR(i,1,n)
        {
            dp[p][i]=get(a[i]-1);
            update(a[i],dp[p-1][i]);
        }
    }
    int res=0;
    FOR(i,1,n) 
        (res+=dp[k][i])%=MOD;
    cout<<res;
}
