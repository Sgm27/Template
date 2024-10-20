#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;


int max(int a,int b)
{
    if (a>b) return a;
    return b;
}
int min(int a,int b)
{
    if (a>b) return b;
    return a;
}
int ans[105];

int main()
{
    freopen("thu.inp","r",stdin);
    int nTest; scanf("%d",&nTest);
    while (nTest--)
    {
        ll k,N = 0;
        scanf("%lld",&k);
        while (k)
        {
            ans[++N] = k & 1;
            k >>= 1;
        }
        for (int i=N;i>=1;i--) printf("%d",ans[i]);
        printf("\n");
    }
}
