#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 5005
int a[maxn],b[maxn],n,f[maxn][maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) 
    {
        cin>>a[i];
        b[i-1] = a[i] - a[i-1];
    }
    n--;
    int ans = 0;
    FOR(i,1,n-1)
        FOR(j,i+1,n)
        {
            if (b[i] == b[j])
            {
                f[i][j] = f[i-1][j-1] + 1;
                ans = max(ans,min(f[i][j],j-i-1)); 
            }
            else f[i][j] = 0;
        }
    if (ans < 4) cout<<"0";
    else cout<<ans + 1;
}
