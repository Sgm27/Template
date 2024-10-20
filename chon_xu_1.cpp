#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 1000006
const int MOD=1e9+7;
int dp[maxn],n,s,a[maxn];
signed main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>s;
    FOR(i,1,n) cin>>a[i];
    dp[0]=1;
    FOR(i,0,s)
        FOR(j,1,n)
            if (i>=a[j]) dp[i]=(dp[i]+dp[i-a[j]])%MOD;
    cout<<dp[s];
}
