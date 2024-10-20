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


int main()
{
    // freopen("thu.inp","r",stdin);
    int n;
    ll res=0;
    char s[1005];
    scanf("%d",&n);
    scanf("%s",s);
    for (int i=n-1;i>=0;i--)
    {
        if (s[i]=='5' || s[i]=='0') 
        {
            res++;
            for (int j=i-1;j>=0;j--) 
            if (s[j]!='0') res++;
        }
    }
    printf("%lld",res);
}
