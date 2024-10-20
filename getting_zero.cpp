#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = long long;
const int MOD=32768;
#define maxn 100005
int n,dp[maxn];
int solve(int n)
{
    cout<<n<<"\n";
    if (!n) return 0;
    return min(solve((n+1)%MOD)+1,solve((n*2)%MOD)+1);
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        int n;	
        cin>>n;
        cout<<solve(n);
    }
}
