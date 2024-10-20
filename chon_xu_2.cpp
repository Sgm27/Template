#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = long long;
const int MOD=1e9+7;
#define maxn 1000006
int n,s;
ll dp[maxn],a[105];
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>s;
    FOR(i,1,n) cin>>a[i];
    dp[0]=1;
    FOR(i,1,n)
        FOR(j,a[i],s) 
            if (dp[j-a[i]]) 
            {
                dp[j]+=dp[j-a[i]];
                dp[j]%=MOD;
            }
    cout<<dp[s];
}