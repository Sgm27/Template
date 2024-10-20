#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 6005
int n,l,a[maxn],f[maxn],sum[maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>l;
    FOR(i,1,n) cin>>a[i], sum[i] = sum[i-1] + a[i];
    memset(f,0x3f,sizeof(f));
    f[0] = 0;
    FOR(i,1,n)
        FOD(j,i-1,0)   
        {
            if (sum[i] - sum[j] > l) break;
            f[i] = min(f[i],max(f[j], l - (sum[i] - sum[j])));
        }
    cout<<f[n];
}
