#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 405
int n,f[maxn][40005];
struct TMP{
    int h,a,c;
} k[maxn];
bool cmp(TMP a,TMP b)
{
    return a.a<b.a;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) cin>>k[i].h>>k[i].a>>k[i].c;
    sort(k+1,k+1+n,cmp);
    k[0].a = INF;
    int ans = 0;
    FOR(i,1,n)
        FOR(j,1,k[i].a)
        {
            FOR(z,0,k[i].c)
            {
                int l = z * k[i].h;
                if (j - l < 0 || j - l > k[i-1].a) continue;
                f[i][j] = max(f[i][j], f[i-1][j-l] + l);
            }
            ans = max(ans,f[i][j]);
        }
    cout<<ans;
}
