#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 300005 
int Min[20][maxn],Max[20][maxn];
int n,a[maxn],k;
int f[maxn],g[maxn];
int get(int l,int r,string type)
{
	int k=log2(r-l+1);
	if (type=="max") return max(Max[k][l],Max[k][r-(1<<(k))+1]);
	return min(Min[k][l],Min[k][r-(1<<(k))+1]);
}
void RMQ()
{
	for (int i=1;i<=n;i++) Min[0][i]=Max[0][i]=a[i];
	for (int i=1;i<=log2(n);i++)
	{
		for (int j=1;j<=(n-(1<<i)+1);j++)
		{
			Min[i][j]=min(Min[i-1][j],Min[i-1][j+(1<<(i-1))]);
			Max[i][j]=max(Max[i-1][j],Max[i-1][j+(1<<(i-1))]);
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
    cin>>n>>k;
    if (n == 1) return cout<<1, 0;
    FOR(i,1,n) cin>>a[i];
    RMQ();
    FOR(i,1,n)
    {
        int l=0,r=i;
        while (r-l>1)
        {
            int m = l+r >> 1;
            if (get(m,i,"max") - get(m,i,"min") <= k) r=m;
            else l=m;
        }
        f[i] = max(f[i],i-r+1);
        g[r] = max(g[r],i-r+1);
    }
    FOR(i,1,n) f[i] = max(f[i],f[i-1]);
    FOD(i,n,1) g[i] = max(g[i],g[i+1]);
    int ans = 0;
    FOR(i,1,n)
        ans = max(ans,f[i] + g[i+1]);
    cout<<ans;
}
