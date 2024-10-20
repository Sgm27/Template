#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = long long;
#define maxn 
int bit[105],max_bit;
const int MOD=1e9+7;
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        int n,k;
        cin>>n>>k;
        while (k)
        {
            bit[max_bit++]=k%2;
            k/=2;
        }
        ll ans=0,power;
        FOR(i,0,max_bit)
        {
            if (!i) power=1; else power=(power*n)%MOD;
            if (bit[i]) ans=(ans+power)%MOD;
        }
        cout<<ans;
    }
}
