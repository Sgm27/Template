#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
char s[1005];
int cur_base,cov_base;

ll convert(char s[])
{
    ll ans=0;
    for (int i=0;i<strlen(s);i++)
        if (isdigit(s[i])) ans=ans*cur_base+(s[i]-'0');
        else ans=ans*cur_base+(s[i]-'A'+10);
    return ans;
}
void process()
{
    ll num=convert(s);
    int a[1005],nmax=0;
    while(num)
    {
        a[++nmax]=num%cov_base;
        num/=cov_base;
    }
    for (int i=nmax;i>=1;i--)
        if (a[i]>=10) printf("%c",a[i]-10+'A');
        else printf("%d",a[i]);
}
int main()
{
    // freopen("thu.inp","r",stdin);
    int tc; scanf("%d",&tc);
    while (tc--)
    {
        scanf("%s %d %d",s,&cur_base,&cov_base);
        process();
        printf("\n");
    }
}
