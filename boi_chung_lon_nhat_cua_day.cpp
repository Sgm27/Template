#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = unsigned long long;
#define maxn 1005
ll n,dp[maxn][maxn];
ll lcm(ll a,ll b)
{
    return a/__gcd(a,b)*b;
}
void process()
{
    FOR(i,1,n) dp[i][1]=i;
    FOR(i,1,n)
        FOR(j,2,i)
            FOR(k,1,i-1) 
                dp[i][j]=max(dp[i][j],lcm(dp[i-k][j-1],k));
    ll ans=0;
    FOR(i,1,n) ans=max(ans,dp[n][i]);
    cout<<ans;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    process();
}
