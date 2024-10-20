#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
int n;
const int MOD=1e9+7;
ll dp[1000005];
void input()
{
    scanf("%d",&n);
}
void process()
{
    memset(dp,0,sizeof(dp));
    dp[1]=1;
    dp[2]=3;
    for (int i=3;i<=n;i++) 
    {
        dp[i]=dp[i-1]+dp[i-2]*2;
        dp[i]%=MOD;
    }
    printf("%lld",dp[n]);
}
int main()
{
    // freopen("thu.inp","r",stdin);
    input();
    process();
}
